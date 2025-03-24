#ifndef _TRANSPORTS_DDS_COMPONENTS_RTPSSERVERPROCEDUREENDPOINT_H_
#define _TRANSPORTS_DDS_COMPONENTS_RTPSSERVERPROCEDUREENDPOINT_H_

#include "../RTPSServerTransport.h"
#include "../../components/Endpoint.h"
#include "../../../utils/Messages.h"

#include <fastrtps/fastrtps_dll.h>
#include <fastrtps/subscriber/SubscriberListener.h>
#include <fastrtps/rtps/common/MatchingInfo.h>

#include <string>
#include <mutex>

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
                /**
                 * @brief This class represents a communication endpoint used by a server.
                 *        It also encapsulates the DDS datawriter and the DDS datareader.
                 * 
                 */
                class RTPSServerProcedureEndpoint : public Endpoint, public eprosima::fastrtps::SubscriberListener
                {
                    public:

                        /**
                         * @brief Default constructor.
                         * 
                         * @param transport Transport that is creating the server procedure endpoint. It cannot be NULL.
                         */
                        RTPSServerProcedureEndpoint(RTPSServerTransport &transport);

                        /// @brief Default destructor.
                        virtual ~RTPSServerProcedureEndpoint();

                        /**
                         * @brief Initializes the endpoint.
                         * 
                         * @param name The name associated with this procedure endpoint. It cannot be NULL.
                         * @param writertypename The type name of the topic that the server procedure endpoint uses in the datawriter. It cannot be NULL.
                         * @param writertopicname The name of the topic that the server procedure endpoint uses in the datawriter. It cannot be NULL.
                         * @param readertypename The type name of the topic that the server procedure endpoint uses in the datareader. It cannot be NULL.
                         * @param readertopicname The name of the topic that the server procedure endpoint uses in the datareader. It cannot be NULL.
                         * @param create_data Pointer to the function used to create the request data type.
                         * @param destroy_data Pointer to the function used to destory the data.
                         * @param dataSize Pointer to the function used to destory the request data.
                         * @return 0 if the initialization works. -1 in other case.
                         */
                        int initialize(const char *name, const char *writertypename, const char *writertopicname,
                                       const char *readertypename, const char *readertopicname,
                                       RTPSTransport::Create_data create_data, RTPSTransport::Destroy_data destroy_data,
                                       RTPSTransport::ProcessFunc, size_t dataSize);

                        /**
                         * @brief This function finalizes the server procedure endpoint.
                         *        All entities and objects created by this procedure endpoint are deleted.
                         * 
                         */
                        void finalize();

                        /**
                         * @brief This method creates the DDS entities needed to run this DDS Endpoint.
                         * 
                         * @param serviceName Name of the service.
                         * @param instanceName Name of the instance.
                         * @return 0 if the start works. -1 in other case.
                         */
                        int start(const char* const &serviceName, const char* const &instanceName);

                        /// @brief This method deletes the DDS entities needed to run this DDS Endpoint.
                        void stop();

                        /**
                         * @brief Gets the callback used to processes a request.
                         * 
                         * @return Function callback used to processes a request.
                         */
                        RTPSTransport::ProcessFunc getProcessFunc() { return m_process_func; }

                        /**
                         * @brief Get the callback used to destory a request data
                         * 
                         * @return Function callback used to destory a request data
                         */
                        RTPSTransport::Destroy_data getDestoryFunc() { return m_destroy_data; }

                        /**
                         * @brief Sends the reply.
                         * 
                         * @param data 
                         * @return int 
                         */
                        int sendReply(void *data);

                        /// @brief DDS callback.
                        virtual void onNewDataMessage(eprosima::fastrtps::Subscriber *sub);

                        virtual void onSubscriptionMatched(eprosima::fastrtps::Subscriber* /*sub*/, eprosima::fastrtps::rtps::MatchingInfo /*info*/){}



                    private:

                        /**
                         * @brief This function creates the DDS entities.
                         * 
                         * @param serviceName Name of the service.
                         * @param instanceName Name of the instance.
                         * @return 0 if the start works. -1 in other case.
                         */
                        int createEntities(const std::string &serviceName, const std::string &instanceName);

                        /// @brief Transport that has created the proxy procedure endpoint.
                        RTPSServerTransport &m_transport;

                        const char *m_name;

                        std::string m_writerTypeName;

                        std::string m_writerTopicName;

                        std::string m_readerTypeName;

                        std::string m_readerTopicName;

                        /// @brief The data writer used to send.
                        eprosima::fastrtps::Publisher *m_writer;

                        /// @brief The data reader used to receive.
                        eprosima::fastrtps::Subscriber *m_reader;

                        RTPSTransport::Create_data m_create_data;

                        RTPSTransport::Destroy_data m_destroy_data;

                        RTPSTransport::ProcessFunc m_process_func;

                        int m_dataSize;

                        std::mutex *m_mutex;

                        int m_started;
                };
            } // namespace dds
        } // namespace transport
    } // namespace rpc
} // namespace eprosima

#endif // _TRANSPORTS_DDS_COMPONENTS_RTPSSERVERPROCEDUREENDPOINT_H_
