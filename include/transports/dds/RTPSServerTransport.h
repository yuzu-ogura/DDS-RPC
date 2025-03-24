#ifndef _TRANSPORTS_DDS_RTPSSERVERTRANSPORT_H_
#define _TRANSPORTS_DDS_RTPSSERVERTRANSPORT_H_

#include "RTPSTransport.h"
#include "../ServerTransport.h"

#include <string>
#include <map>

namespace eprosima
{
    namespace rpc
    {
        namespace transport
        {
            namespace dds
            {
                class RTPSServerProcedureEndpoint;

                /**
                 * @brief This class implements a DDS transport using only the RTPS level provided by FastRTPS library.
                 *        This transport can be used by the servers.
                 * 
                 */
                class RTPSServerTransport : public ServerTransport, public RTPSTransport
                {
                    public:

                        /**
                         * @brief Default constructor.
                         * 
                         * @param serviceName Name of the remote service. If value is not assigned or NULL pointer, the default service's name will be used.
                         * @param instanceName Instance's name of the remote service. If value is not assigned or NULL pointer, the default instance's name will be used.
                         * @param domainId Optional parameter that specifies the domain identifier will be used in DDS.
                         */
                        RTPSServerTransport(const char* const serviceName = NULL, const char* const instanceName = NULL, int domainId = 0);

                        /**
                         * @brief Default constructor.
                         * 
                         * @param participant User's participant that will be use for communications.
                         * @param serviceName Name of the remote service. If value is not assigned or NULL pointer, the default service's name will be used.
                         * @param instanceName Instance's name of the remote service. If value is not assigned or NULL pointer, the default instance's name will be used.
                         */
                        RTPSServerTransport(eprosima::fastrtps::Participant *participant, const char* const serviceName = NULL, const char* const instanceName = NULL);

                        /// @brief Default destructor.
                        virtual ~RTPSServerTransport();

                        /**
                         * @brief This function returns the type of the transport.
                         *        This function has to be implemented by the child classes.
                         * 
                         * @return Transport type name.
                         */
                        virtual const char* getType() const;

                        /**
                         * @brief This function creates a new server procedure endpoint.
                         *        This server procedure endpoint manages the DDS datawriter and the DDS datareader.
                         * 
                         * @param name The name associated with this server procedure endpoint. It cannot be NULL.
                         * @param writertypename The type name of the topic that the procedure endpoint uses in the datawriter. It cannot be NULL.
                         * @param writertopicname The name of the topic that the procedure endpoint uses in the datawriter. It cannot be NULL.
                         * @param readertypename The type name of the topic that the procedure endpoint uses in the datareader. It cannot be NULL.
                         * @param readertopicname The name of the topic that the procedure endpoint uses in the datareader. It cannot be NULL.
                         * @param create_data Pointer to the function used to create the request data type.
                         * @param copy_data Pointer to the function used to copy the request data.
                         * @param destroy_data Pointer to the function used to destory the request data.
                         * @param processFunc Pointer to the function invoked when a message is received from the proxy.
                         * @param dataSize Size of the DataReader data structure.
                         * @return server procedure endpoint.
                         */
                        eprosima::rpc::transport::Endpoint*
                            createProcedureEndpoint(const char *name, const char *writertypename,
                                    const char *writertopicname, const char *readertypename, const char *readertopicname,
                                    RTPSTransport::Create_data create_data, RTPSTransport::Copy_data copy_data, RTPSTransport::Destroy_data destroy_data,
                                    RTPSTransport::ProcessFunc processFunc, size_t dataSize);
								
						/**
                         * @brief This method is invoked once for each incoming request.
                         * 
                         * @param endpoint The server procedure endpoint.
                         * @param data The request data.
                         */
                        void process(RTPSServerProcedureEndpoint *endpoint, void *data);

						/// @brief This method starts all the DDS Datawriters and Datareaders.
                        void run();

						/// @brief This function does not apply to DDS transport.
                        void stop();

						/**
                         * @brief This function is used to send a reply to a proxy.
                         * 
                         * @param data Data to send.
                         * @param dataLength Length of the data to send.
                         * @param endpoint Endpoint meant to send the data.
                         */
                        void sendReply(void *data, size_t dataLength, Endpoint *endpoint);

						/// @brief This function does not apply to DDS transport.
                        int receive(char *buffer, size_t bufferLength, size_t &dataToRead, Endpoint *endpoint); 

						/**
                         * @brief This function returns the service name.
                         * 
                         * @return service name.
                         */
                        const char* getRemoteServiceName() const;

                    private:

                        /**
                         * @brief Map containing the server's procedure endpoints that were created to communicate.
                         *        The map key is the pointer where the name is allocated, not the name itself.
                         *        Then always the same string in memory has to be used and not a copy.
                         * 
                         */
                        std::map<const char*, RTPSServerProcedureEndpoint*> m_procedureEndpoints;

                        std::string m_serviceName;

                        std::string m_instanceName;
                };
            } // namepsace dds
        } // namespace transport
    } // namepsace fastrpc
} // namespace eprosima

#endif // _TRANSPORTS_DDS_RTPSSERVERTRANSPORT_H_
