#ifndef _TRANSPORTS_DDS_RTPSPROXYTRANSPORT_H_
#define _TRANSPORTS_DDS_RTPSPROXYTRANSPORT_H_

#include "RTPSTransport.h"
#include "../ProxyTransport.h"

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
                class RTPSProxyProcedureEndpoint;

                /**
                 * @brief This class is the base of all proxies that implement a DDS transport
                 *        using only the RTPS level provided by FastRTPS library.
                 * 
                 */
                class RTPSProxyTransport : public ProxyTransport, public RTPSTransport
                {
                    public:

                        /**
                         * @brief Default constructor.
                         * 
                         * @param remoteServiceName Name of the remote service. If value is not assigned or NULL pointer, the default service's name will be used.
                         * @param instanceName Instance's name of the remote service. If value is not assigned or NULL pointer, the default instance's name will be used.
                         * @param domainId Optional parameter that specifies the domain identifier will be used in DDS.
                         * @param milliseconds Optional parameter that specifies the connection timeout in milliseconds.
                         */
                        RTPSProxyTransport(const char* const remoteServiceName = NULL, const char* const instanceName = NULL, int domainId = 0, long milliseconds = 10000L);

                        /**
                         * @brief Default constructor.
                         * 
                         * @param participant User's participant that will be use for communications.
                         * @param remoteServiceName Name of the remote service. If value is not assigned or NULL pointer, the default service's name will be used.
                         * @param instanceName Instance's name of the remote service. If value is not assigned or NULL pointer, the default instance's name will be used.
                         * @param milliseconds Optional parameter that specifies the connection timeout in milliseconds.
                         */
                        RTPSProxyTransport(eprosima::fastrtps::Participant *participant, const char* const remoteServiceName = NULL, const char* const instanceName = NULL, long milliseconds = 10000L);


                        /// @brief Default destructor.
                        virtual ~RTPSProxyTransport();

                        /**
                         * @brief This abstract function returns the type of the transport.
                         *        This function has to be implemented by the child classes.
                         * 
                         * @return Transport type name.
                         */
                        virtual const char* getType() const;

						/**
                         * @brief This function returns the service name.
                         * 
                         * @return Service name.
                         */
                        const char* getRemoteServiceName() const;

                        /**
                         * @brief This function returns the Instance name.
                         * 
                         * @return Instance name.
                         */
                        const char* getInstanceName() const;

						/**
                         * @brief This function gets the timeout value.
                         * 
                         * @return Timeout value in milliseconds.
                         */
                        long getTimeout();

                        /**
                         * @brief This function creates a new proxy procedure endpoint.
                         *        This proxy procedure endpoint manages the DDS datawriter and the DDS datareader.
                         * 
                         * @param name The name associated with this proxy procedure endpoint. It cannot be NULL.
                         * @param writertypename The type name of the topic that the procedure endpoint uses in the datawriter. It cannot be NULL.
                         * @param writertopicname The name of the topic that the procedure endpoint uses in the datawriter. It cannot be NULL.
                         * @param readertypename The type name of the topic that the procedure endpoint uses in the datareader. It cannot be NULL.
                         * @param readertopicname The name of the topic that the procedure endpoint uses in the datareader. It cannot be NULL.
                         * @param create_data Pointer to the function used to create the reply data type.
                         * @param copy_data Pointer to the function used to copy the reply data.
                         * @param destroy_data Pointer to the function used to destory the reply data.
                         * @param processFunc Pointer to the function invoked when a message is received from the server.
                         * @param dataSize Size of the DataReader data structure.
                         * @return proxy procedure endpoint.
                         */
                        eprosima::rpc::transport::Endpoint*
                            createProcedureEndpoint(const char *name, const char *writertypename,
                                    const char *writertopicname, const char *readertypename, const char *readertopicname,
                                    RTPSTransport::Create_data create_data, RTPSTransport::Copy_data copy_data, RTPSTransport::Destroy_data destroy_data,
                                    RTPSTransport::ProcessFunc processFunc, size_t dataSize);

                    private:

                        //TODO TEMPORAL
                        bool connect(){return false;}
                        bool send(const void* /*buffer*/, const size_t /*bufferSize*/){return false;}
                        int receive(void* /*buffer*/, const size_t /*bufferSize*/, size_t &/*dataToRead*/){return -1;}

                        /**
                         * @brief Map containing the proxy's procedure endpoints that were created to communicate.
                         *        The map key is the pointer where the name is allocated, not the name itself.
                         *        Then always the same string in memory has to be used and not a copy.
                         * 
                         */
                        std::map<const char*, RTPSProxyProcedureEndpoint*> m_procedureEndpoints;

                        std::string m_remoteServiceName;

                        std::string m_instanceName;

                        long m_timeout;
                };
            } // namespace dds
        } // namespace transport
    } // namespace rpc
} // namespace eprosima

#endif // _TRANSPORTS_DDS_RTPSPROXYTRANSPORT_H_
