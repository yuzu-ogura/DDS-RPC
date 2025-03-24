#ifndef _TRANSPORTS_DDS_COMPONENTS_RTPSPROXYPROCEDUREENDPOINT_H_
#define _TRANSPORTS_DDS_COMPONENTS_RTPSPROXYPROCEDUREENDPOINT_H_

#include "../RTPSProxyTransport.h"
#include "../../components/Endpoint.h"
#include "../../../utils/Messages.h"
#include "../../../protocols/dds/MessageHeader.h"

#include <fastrtps/subscriber/SubscriberListener.h>
#include <fastrtps/publisher/PublisherListener.h>
#include <fastrtps/rtps/common/MatchingInfo.h>

#include <map>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>
#include <cstdint>

namespace eprosima
{
    namespace fastrtps
    {
        class Publisher;
        class Subscriber;
    }

    namespace rpc
    {
        namespace transport
        {
            namespace dds
            {
                class RecvPoint;
                class RTPSAsyncTask;

                /**
                 * @brief This class represents a communication endpoint used by a proxy.
                 *        It also encapsulates the DDS datawriter and the DDS datareader.
                 * 
                 */
                class RTPSProxyProcedureEndpoint : public Endpoint, public eprosima::fastrtps::SubscriberListener, public eprosima::fastrtps::PublisherListener
                {
                    public:

                        /**
                         * @brief Default constructor.
                         * 
                         * @param transport Transport that is creating the proxy procedure endpoint. It cannot be NULL.
                         */
                        RTPSProxyProcedureEndpoint(RTPSProxyTransport &transport);

                        /// @brief Default destructor.
                        virtual ~RTPSProxyProcedureEndpoint();

                        /**
                         * @brief This function initializes the proxy procedure endpoint.
                         * 
                         * @param name The name associated with this proxy procedure endpoint. It cannot be NULL.
                         * @param writertypename The type name of the topic that the proxy procedure endpoint uses in the datawriter. It cannot be NULL.
                         * @param writertopicname The name of the topic that the proxy procedure endpoint uses in the datawriter. It cannot be NULL.
                         * @param readertypename The type name of the topic that the proxy procedure endpoint uses in the datareader. It cannot be NULL.
                         * @param readertopicname The name of the topic that the proxy procedure endpoint uses in the datareader. It cannot be NULL.
                         * @param create_data Pointer to the function used to create the reply data type.
                         * @param copy_data Pointer to the function used to copy the reply data.
                         * @param destroy_data Pointer to the function used to destory the reply data.
                         * @param dataSize unused parameter.
                         * @return 0 if the initialization works. -1 in other case.
                         */
                        int initialize(const char *name, const char *writertypename,
                                       const char *writertopicname, const char *readertypename, const char *readertopicname,
                                       RTPSTransport::Create_data create_data, RTPSTransport::Copy_data copy_data,
                                       RTPSTransport::Destroy_data destroy_data, size_t dataSize);

                        /**
                         * @brief This function finalizes the proxy procedure endpoint.
                         *        All entities and objects created by this procedure endpoint are deleted.
                         * 
                         */
                        void finalize();

                        /**
                         * @brief This function sends a synchronous RPC call.
                         *        It sends the request to the server and waits for the reply.
                         * 
                         * 
                         * @param request Pointer to the request. It cannot be NULL.
                         * @param reply Pointer to the reply. This memory will be filled with the incoming data.
                         *              The pointer can be NULL and this means that the RPC call is oneway.
                         * @return Operation status
                         */
                        ReturnMessage send(void *request, void* reply);

                        /**
                         * @brief This function sends an asynchronous RPC call.
                         *        It sends the request to the server and does not wait for the reply.
                         *        Instead, the corresponding callback inside the RTPSAsyncTask object
                         *        will be invoked when the response arrives.
                         * 
                         * @param request Pointer to the request. It cannot be NULL.
                         * @param task Object containing information of the asynchronous task.
                         * @return Operation status.
                         */
                        ReturnMessage send_async(void *request, RTPSAsyncTask *task);

                        /// @brief DDS callback.
                        virtual void onNewDataMessage(eprosima::fastrtps::Subscriber *sub);

                        virtual void onSubscriptionMatched(eprosima::fastrtps::Subscriber *sub, eprosima::fastrtps::rtps::MatchingInfo& info);

                        virtual void onPublicationMatched(eprosima::fastrtps::Publisher *pub, eprosima::fastrtps::rtps::MatchingInfo& info);

                    private:

                        /**
                         * @brief This function creates the DDS entities.
                         * 
                         * @param name The name associated with this proxy procedure endpoint. It cannot be NULL.
                         * @param writertypename The type name of the topic that the proxy procedure endpoint uses in the datawriter. It cannot be NULL.
                         * @param writertopicname The name of the topic that the proxy procedure endpoint uses in the datawriter. It cannot be NULL.
                         * @param readertypename The type name of the topic that the proxy procedure endpoint uses in the datareader. It cannot be NULL.
                         * @param readertopicname The name of the topic that the proxy procedure endpoint uses in the datareader. It cannot be NULL.
                         * @return 0 value is returned if the initialization works successfully. In other case -1 is returned.
                         */
                        int createEntities(const char *name, const char *writertypename, const char *writertopicname,
                                           const char *readertypename, const char *readertopicname);

                        /**
                         * @brief This function checks if the server was discovered.
                         * 
                         * @param timeout Timeout used to do the checking. Its value is in milliseconds.
                         * @return Operation status.
                         */
                        ReturnMessage checkServerConnection(long timeout);

                        /// @brief Mutex used to ensure that sequence number and query pool is safe-thread.
                        std::mutex *m_mutex;

                        std::mutex *recv_mutex_;

                        std::map<int64_t, RecvPoint&> recv_threads;

                        std::shared_timed_mutex *matched_mutex_;

                        std::condition_variable_any *matched_sub_cond_;

                        std::condition_variable_any *matched_pub_cond_;

                        unsigned int num_matched_sub_;

                        unsigned int num_matched_pub_;

                        /// @brief Transport that created the proxy procedure endpoint.
                        RTPSProxyTransport &m_transport;

                        /// @brief The data writer used to send.
                        eprosima::fastrtps::Publisher *m_writer;

                        /// @brief The data reader used to receive.
                        eprosima::fastrtps::Subscriber *m_reader;

                        /// @brief The identifier used as proxy.
                        eprosima::rpc::protocol::GUID_t m_proxyId;

                        /// @brief The next sequence number for a request.
                        int64_t m_numSec;

                        RTPSTransport::Create_data m_create_data;

                        RTPSTransport::Copy_data m_copy_data;

                        RTPSTransport::Destroy_data m_destroy_data;

                        size_t m_dataSize;

                        void *data_;
                };
            } // namespace dds
        } // namespace transport
    } // namespace rpc
} // namespace eprosima

#endif // _TRANSPORTS_DDS_COMPONENTS_RTPSPROXYPROCEDUREENDPOINT_H_
