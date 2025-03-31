#include <transports/dds/components/RTPSProxyProcedureEndpoint.h>
#include <transports/dds/RTPSAsyncTask.h>
#include <protocols/dds/MessageHeader.h>
#include <fastrtps/Domain.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/Domain.h>
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastrtps/subscriber/SampleInfo.h>

static const char* const CLASS_NAME = "eprosima::rpc::transport::dds::RTPSProxyProcedureEndpoint";

namespace eprosima
{
    namespace rpc
    {
        namespace transport
        {
            namespace dds
            {
                class RecvPoint
                {
                public:
                    RecvPoint(void *reply) : received_(false), reply_(reply), task_(NULL) {}

                    explicit RecvPoint(RTPSAsyncTask *task) : received_(false), reply_(NULL), task_(task)
                    {
                        if (task_ != NULL)
                            reply_ = task_->getReplyInstance();
                    }

                    void *getReply() { return reply_; }

                    RTPSAsyncTask *getTask() { return task_; }

                    bool received_;
                    std::mutex mutex_;
                    std::condition_variable cond_;

                private:
                    void *reply_;

                    RTPSAsyncTask *task_;
                };
            }
        }
    }
}

using namespace eprosima::rpc;
using namespace ::transport::dds;

RTPSProxyProcedureEndpoint::RTPSProxyProcedureEndpoint(RTPSProxyTransport &transport) : m_mutex(NULL), recv_mutex_(NULL),
    matched_mutex_(NULL), matched_sub_cond_(NULL), matched_pub_cond_(NULL), num_matched_sub_(0), num_matched_pub_(0),
    m_transport(transport), m_writer(NULL), m_reader(NULL), m_numSec(0),
    m_create_data(NULL), m_copy_data(NULL), m_destroy_data(NULL), m_dataSize(0), data_(NULL)
{
}

RTPSProxyProcedureEndpoint::~RTPSProxyProcedureEndpoint()
{
    // Remove asynchronous tasks.
    //TODO
    //m_transport.deleteAssociatedAsyncTasks(this);

    finalize();
}

int RTPSProxyProcedureEndpoint::initialize(const char *name, const char *writertypename,
        const char *writertopicname, const char *readertypename, const char *readertopicname,
        RTPSTransport::Create_data create_data, RTPSTransport::Copy_data copy_data,
        RTPSTransport::Destroy_data destroy_data, size_t dataSize)
{
    const char* const METHOD_NAME = "initialize";
    m_create_data = create_data;
    m_copy_data = copy_data;
    m_destroy_data = destroy_data;
    m_dataSize = dataSize;
    m_mutex =  new std::mutex();
    recv_mutex_ = new std::mutex();
    matched_mutex_ = new std::shared_timed_mutex();
    matched_sub_cond_ = new std::condition_variable_any();
    matched_pub_cond_ = new std::condition_variable_any();

    if(m_mutex != NULL && recv_mutex_ != NULL && matched_mutex_ != NULL &&
            matched_sub_cond_ != NULL && matched_pub_cond_ != NULL)
    {
        if(createEntities(name, writertypename, writertopicname,
                    readertypename, readertopicname) == 0)
        {
            // Not oneway
            if(m_reader != NULL)
            {
                data_ = m_create_data();

                if(data_ != NULL)
                    return 0;
                else
                    printf("ERROR<%s::%s>: Cannot create data\n", CLASS_NAME, METHOD_NAME);
            }
            else
                return 0;
        }
        else
        {
            printf("ERROR<%s::%s>: Cannot create the DDS entities\n", CLASS_NAME, METHOD_NAME);
        }
    }
    else
    {
        printf("ERROR<%s::%s>: Cannot create the mutex\n", CLASS_NAME, METHOD_NAME);
    }

    return -1;
}

void RTPSProxyProcedureEndpoint::finalize()
{
    if(data_ != NULL)
        m_destroy_data(data_);

    // if not operation oneway.
    if(m_reader != nullptr)
    {
        eprosima::fastrtps::Domain::removeSubscriber(m_reader);
    }

    if(m_writer != nullptr)
        eprosima::fastrtps::Domain::removePublisher(m_writer);

    if(matched_pub_cond_ != NULL)
    {
        delete matched_pub_cond_;
        matched_pub_cond_ = NULL;
    }

    if(matched_sub_cond_ != NULL)
    {
        delete matched_sub_cond_;
        matched_sub_cond_ = NULL;
    }

    if(matched_mutex_ != NULL)
    {
        delete matched_mutex_;
        matched_mutex_ = NULL;
    }

    if(recv_mutex_ != NULL)
    {
        delete recv_mutex_;
        recv_mutex_ = NULL;
    }

    if(m_mutex != NULL)
    {
        delete m_mutex;
        m_mutex = NULL;
    }
}

int RTPSProxyProcedureEndpoint::createEntities(const char *name, const char *writertypename, const char *writertopicname,
        const char *readertypename, const char *readertopicname)
{
    const char* const METHOD_NAME = "createEntities";

    if(name != NULL)
    {
        if(writertypename != NULL)
        {
            eprosima::fastrtps::PublisherAttributes wQos;

            wQos.topic.topicName = writertopicname;
            wQos.topic.topicDataType = writertypename;
            wQos.qos.m_reliability.kind = eprosima::fastrtps::RELIABLE_RELIABILITY_QOS;
            wQos.topic.historyQos.depth = 100;
            wQos.throughputController= {30 * 1000 * 1000, 1000};
            wQos.qos.m_publishMode.kind = eprosima::fastdds::dds::ASYNCHRONOUS_PUBLISH_MODE;
            wQos.historyMemoryPolicy = eprosima::fastrtps::rtps::MemoryManagementPolicy::PREALLOCATED_WITH_REALLOC_MEMORY_MODE;

            m_writer = eprosima::fastrtps::Domain::createPublisher(m_transport.getParticipant(), wQos, this);

            if(m_writer != nullptr)
            {
                // Is not oneway operation
                if(readertypename != NULL)
                {
                    eprosima::fastrtps::SubscriberAttributes rQos;

                    rQos.topic.topicName = readertopicname;
                    rQos.topic.topicDataType = readertypename;
                    rQos.qos.m_reliability.kind = eprosima::fastrtps::RELIABLE_RELIABILITY_QOS;
                    rQos.topic.historyQos.depth = 100;

                    m_reader = eprosima::fastrtps::Domain::createSubscriber(m_transport.getParticipant(), rQos, this);

                    if(m_reader != nullptr)
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }

                eprosima::fastrtps::Domain::removePublisher(m_writer);
            }
            else
            {
                printf("ERROR<%s::%s>: Cannot create the data writer\n", CLASS_NAME, METHOD_NAME);
            }
        }
        else
        {
            printf("ERROR<%s::%s>: Bad parameter (writertypename)\n", CLASS_NAME, METHOD_NAME);
        }
    }
    else
    {
        printf("ERROR<%s::%s>: Bad parameter (name)\n", CLASS_NAME, METHOD_NAME);
    }

    return -1;
}

ReturnMessage RTPSProxyProcedureEndpoint::checkServerConnection(long timeout)
{
    std::shared_lock<std::shared_timed_mutex> lock(*matched_mutex_);

    if(num_matched_sub_ == 0 && m_reader != nullptr)
    {
        matched_sub_cond_->wait_for(lock, std::chrono::milliseconds(timeout));

        if(num_matched_sub_ == 0)
            return SERVER_NOT_FOUND;
    }

    if(num_matched_pub_ == 0)
    {
        matched_pub_cond_->wait_for(lock, std::chrono::milliseconds(timeout));

        if(num_matched_pub_ == 0)
            return SERVER_NOT_FOUND;
    }

    return OK;
}

ReturnMessage RTPSProxyProcedureEndpoint::send(void *request, void *reply)
{
    const char* const METHOD_NAME = "send";
    ReturnMessage returnedValue = CLIENT_INTERNAL_ERROR;
    eprosima::rpc::protocol::RequestHeader *requestHeader = NULL;
    int64_t numSec = 0;

    if(request != NULL)
    {
        requestHeader = reinterpret_cast<eprosima::rpc::protocol::RequestHeader*>(request);
        requestHeader->requestId().writer_guid().guidPrefix() = m_proxyId.guidPrefix();
        requestHeader->requestId().writer_guid().entityId().entityKey() = m_proxyId.entityId().entityKey();
        requestHeader->requestId().writer_guid().entityId().entityKind() = m_proxyId.entityId().entityKind();
        requestHeader->instanceName(m_transport.getInstanceName());

        m_mutex->lock();
        numSec = m_numSec;
        // Thread safe num_Sec handling
        int32_t high = (numSec >> 32) & 0xFFFFFFFF;
        uint32_t low = (numSec & 0xFFFFFFFF);
        requestHeader->requestId().sequence_number().high(high);
        requestHeader->requestId().sequence_number().low(low);
        ++m_numSec;
        m_mutex->unlock();

        if(checkServerConnection(m_transport.getTimeout()) == OK)
        {
            RecvPoint *recvpoint = nullptr;

            // Its not a oneway function.
            if(m_reader != nullptr && reply != nullptr)
            {
                recvpoint = new RecvPoint(reply);
                // Insert reply in map before sending the data.
                std::unique_lock<std::mutex> lock(*recv_mutex_);
                recv_threads.insert(std::pair<int64_t, RecvPoint&>(numSec, *recvpoint));
            }

            bool retWrite = m_writer->write(request);

            // Its not a oneway function.
            if(recvpoint != nullptr)
            {
                if(retWrite)
                {
                    std::unique_lock<std::mutex> lock(recvpoint->mutex_);

                    if(!recvpoint->received_)
                    {
                        if(recvpoint->cond_.wait_for(lock, std::chrono::milliseconds(m_transport.getTimeout())) != std::cv_status::timeout)
                        {
                            returnedValue = OK;
                        }
                        else
                        {
                            returnedValue = TIMEOUT;
                        }
                    }
                    else
                        returnedValue = OK;
                }
                else
                    printf("ERROR <%s::%s>: Some error occurs\n", CLASS_NAME, METHOD_NAME);

                std::unique_lock<std::mutex> lock(*recv_mutex_);

                std::map<int64_t, RecvPoint&>::iterator it = recv_threads.find(numSec);

                if(it != recv_threads.end())
                {
                    recv_threads.erase(it);
                }

                delete recvpoint;
            }
            else if(retWrite)
            {
                returnedValue = OK;
            }
            else
                printf("ERROR <%s::%s>: Some error occurs\n", CLASS_NAME, METHOD_NAME);
        }
        else
        {
            printf("WARNING<%s::%s>: No server discovered.\n", CLASS_NAME, METHOD_NAME);
            returnedValue = SERVER_NOT_FOUND;
        }
    }
    else
    {
        printf("ERROR<%s::%s>: Bad parameter(data)\n", CLASS_NAME, METHOD_NAME);
    }

    return returnedValue;
}

ReturnMessage RTPSProxyProcedureEndpoint::send_async(void *request, RTPSAsyncTask *task)
{
    const char* const METHOD_NAME = "send_async";
    ReturnMessage returnedValue = CLIENT_INTERNAL_ERROR;
    eprosima::rpc::protocol::RequestHeader *requestHeader = NULL;
    int64_t numSec = 0;

    if(request != NULL)
    {
        requestHeader = reinterpret_cast<eprosima::rpc::protocol::RequestHeader*>(request);
        requestHeader->requestId().writer_guid().guidPrefix() = m_proxyId.guidPrefix();
        requestHeader->requestId().writer_guid().entityId().entityKey() = m_proxyId.entityId().entityKey();
        requestHeader->requestId().writer_guid().entityId().entityKind() = m_proxyId.entityId().entityKind();
        requestHeader->instanceName(m_transport.getInstanceName());


        m_mutex->lock();
        numSec = m_numSec;
        // Thread safe num_Sec handling
        int32_t high = (numSec >> 32) & 0xFFFFFFFF;
        uint32_t low = (numSec & 0xFFFFFFFF);
        requestHeader->requestId().sequence_number().high(high);
        requestHeader->requestId().sequence_number().low(low);
        ++m_numSec;
        m_mutex->unlock();

        if(checkServerConnection(m_transport.getTimeout()) == OK)
        {
            RecvPoint *recvpoint = nullptr;

            {
                recvpoint = new RecvPoint(task);
                std::unique_lock<std::mutex> lock(*recv_mutex_);
                recv_threads.insert(std::pair<int64_t, RecvPoint&>(numSec, *recvpoint));
            }
            
            if(m_writer->write(request))
            {
                returnedValue = OK;
            }
            else
            {
                printf("ERROR <%s::%s>: Some error occurs\n", CLASS_NAME, METHOD_NAME);

                std::unique_lock<std::mutex> lock(*recv_mutex_);
                std::map<int64_t, RecvPoint&>::iterator it = recv_threads.find(numSec);

                if(it != recv_threads.end())
                {
                    recv_threads.erase(it);
                }

                delete recvpoint;
            }
        }
        else
        {
            printf("WARNING<%s::%s>: No server discovered.\n", CLASS_NAME, METHOD_NAME);
            returnedValue = SERVER_NOT_FOUND;
        }
    }
    else
    {
        printf("ERROR<%s::%s>: Bad parameter(data)\n", CLASS_NAME, METHOD_NAME);
    }

    return returnedValue;
}

void RTPSProxyProcedureEndpoint::onNewDataMessage(eprosima::fastrtps::Subscriber *sub)
{
    eprosima::fastrtps::SampleInfo_t info;

    std::unique_lock<std::mutex> lock(*recv_mutex_);

    if(sub->takeNextData(data_, &info))
    {
        if(info.sampleKind == eprosima::fastrtps::rtps::ALIVE)
        {
            eprosima::rpc::protocol::ReplyHeader *replyHeader = static_cast<eprosima::rpc::protocol::ReplyHeader*>(data_);

            if(replyHeader->relatedRequestId().writer_guid() == m_proxyId &&
                    replyHeader->relatedInstanceName() == m_transport.getInstanceName())
            {
                int64_t numSec = replyHeader->relatedRequestId().sequence_number().high();

                numSec <<= 32;
                numSec &= 0xFFFFFFFF00000000;
                numSec += replyHeader->relatedRequestId().sequence_number().low();

                std::map<int64_t, RecvPoint&>::iterator it = recv_threads.find(numSec);

                if(it != recv_threads.end())
                {
                    RecvPoint *rp = &it->second;
                    m_copy_data(rp->getReply(), data_);

                    if(rp->getTask() == NULL)
                    {
                        std::unique_lock<std::mutex> lockC(rp->mutex_);
                        rp->received_ = true;
                        lockC.unlock();
                        rp->cond_.notify_one();
                    }
                    // Async task
                    else
                    {
                        recv_threads.erase(it);
                        RTPSAsyncTask *task = rp->getTask();
                        delete rp;
                        lock.unlock();
                        task->execute();
                    }
                }
            }
        }
    }
}

void RTPSProxyProcedureEndpoint::onSubscriptionMatched(eprosima::fastrtps::Subscriber* /*sub*/, eprosima::fastrtps::rtps::MatchingInfo& info)
{
    std::unique_lock<std::shared_timed_mutex> lock(*matched_mutex_);

    if(info.status == eprosima::fastrtps::rtps::MatchingStatus::MATCHED_MATCHING)
    {
        ++num_matched_sub_;

        if(num_matched_sub_ == 1)
            matched_sub_cond_->notify_all();
    }
    else
    {
        --num_matched_sub_;
    }
}

void RTPSProxyProcedureEndpoint::onPublicationMatched(eprosima::fastrtps::Publisher* /*pub*/, eprosima::fastrtps::rtps::MatchingInfo& info)
{
    std::unique_lock<std::shared_timed_mutex> lock(*matched_mutex_);

    if(info.status == eprosima::fastrtps::rtps::MatchingStatus::MATCHED_MATCHING)
    {
        ++num_matched_pub_;

        if(num_matched_pub_ == 1)
            matched_pub_cond_->notify_all();
    }
    else
    {
        --num_matched_pub_;
    }
}
