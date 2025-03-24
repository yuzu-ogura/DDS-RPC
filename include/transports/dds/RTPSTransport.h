#ifndef _TRANSPORTS_DDS_RTPSTRANSPORT_H_
#define _TRANSPORTS_DDS_RTPSTRANSPORT_H_

#include <cstddef>
#include <functional>

namespace eprosima
{
    namespace fastrtps
    {
        class Participant;
    }

    namespace rpc
    {
        namespace protocol
        {
            class Protocol;
        }

        namespace transport
        {
            class Endpoint;

            namespace dds
            {
                /**
                 * @brief This class is the base of all classes that implement a transport using RTPS.
                 *        This transport could be used by both proxies and servers.
                 * 
                 */
                class RTPSTransport
                {
                    public:

                        using Create_data = std::function<void*()>;
                        
                        using Copy_data = std::function<void(void *, void *)>;
                        
                        using Destroy_data = std::function<void(void *)>;
                        
                        using ProcessFunc = std::function<void(eprosima::rpc::protocol::Protocol&, void*,
                                                                    eprosima::rpc::transport::Endpoint*)>;

                        /// @brief Default destructor.
                        virtual ~RTPSTransport();

		                /// @brief Initializes the DDS entity.
                        void initialize();

		                /*
						 * @brief Gets the domain participant.
						 * @return DDS domain participant.
						 */

                        /**
                         * @brief Gets the domain participant.
                         * 
                         * @return DDS domain participant.
                         */
                        eprosima::fastrtps::Participant* getParticipant() const
                        {
                            return m_participant;
                        }

                        /**
                         * @brief This function returns the service name.
                         * 
                         * @return service name.
                         */
                        virtual const char* getRemoteServiceName() const = 0;

                        /* TODO Actualizar
                         * @brief This function creates a new procedure endpoint.
                         * This proxy procedure endpoint manages the DDS datawriter and the DDS datareader.
                         *
                         * @param name The name associated with this proxy procedure endpoint. It cannot be NULL.
                         * @param writertypename The type name of the topic that the procedure endpoint uses in the datawriter. It cannot be NULL.
                         * @param readertypename The type name of the topic that the procedure endpoint uses in the datareader. It cannot be NULL.
						 * @param initialize_data Pointer to the function to initialize DataReader received data
						 * @param finalize_data Pointer to the function to finalize DataReader received data
						 * @param ProcessFunc Pointer to the function invoked when a message is received from the server
						 * @param dataSize Size of the DataReader data structure
						 *
                         * @return 0 if the function ends successfully, -1 otherwise.
                         * TODO
                         */
                        virtual eprosima::rpc::transport::Endpoint*
                            createProcedureEndpoint(const char *name, const char *writertypename,
                                    const char *writertopicname, const char *readertypename,
                                    const char *readertopicname,
                                    Create_data create_data, Copy_data copy_data, Destroy_data destroy_data,
                                    ProcessFunc processFunc, size_t dataSize) = 0;

                    protected:

                        /*
                         * @brief Default constructor.
                         * @param domainId Optional parameter that specifies the domain identifier that will be used in DDS.
                         */
                        RTPSTransport(int domainId = 0);

                        RTPSTransport(eprosima::fastrtps::Participant *participant);

                    private:

                        /// @brief The domain identifier that will be used in DDS.
                        int m_domainId;

                        /*
                         * @brief A DDS transport that uses a DDS::DomainParticipant entity to create DDS entities.
                         * This participant has to be created during the transport creation.
                         * This pointer should never be NULL.
                         */
                        eprosima::fastrtps::Participant *m_participant;

                        bool m_ownership;
                };
            } // namespace dds
        } // namespace transport
    } // namespace rpc
} // namespace eprosima

#endif // _TRANSPORTS_DDS_RTPSTRANSPORT_H_
