#ifndef _SERVER_SERVER_H_
#define _SERVER_SERVER_H_

namespace eprosima
{
    namespace rpc
    {
        namespace strategy
        {
            class ServerStrategy;
        }

        namespace transport
        {
            class ServerTransport;
            class Endpoint;
        }

        namespace protocol
        {
            class Protocol;
        }

        namespace server
        {
            /**
             * @brief This class implements the common functionalities that any server has.
             * 
             */
            class Server
            {

                public:

                    /**
                     * @brief This function makes the server starts listening requests.
                     * 
                     */
                    void serve();

                    /**
                     * @brief This function closes the server's communications.
                     * 
                     */
                    void stop();

                protected:

                    /**
                     * @brief A constructor. The associated domain participant is created.
                     *
                     * @param serviceName The service's name that proxies will use to connect with the server.
                     * @param strategy The strategy used by the server to execute new requests.
                     *         This class doesn't delete this object in its destructor. It cannot be NULL.
                     * @param transport The transport that will use the server. This class doesn't delete this object in its destructor.
                     *        If the pointer is NULL, then a default UDPTransport will be used.
                     * @param domainId The domain id's value that the server proxy will set in the domain participant.
                     * 
                     */
                    Server(eprosima::rpc::strategy::ServerStrategy &strategy, eprosima::rpc::transport::ServerTransport &transport,
                            eprosima::rpc::protocol::Protocol &protocol);

                    /// @brief The default destructor.
                    virtual ~Server() = default;

                private:

					/// @brief Pointer to the thread strategy this server uses.
                    eprosima::rpc::strategy::ServerStrategy &m_strategy;

                    /// @brief Pointer to the transport which this server's proxy uses.
                    eprosima::rpc::transport::ServerTransport &m_transport;

					/// @brief Pointer to the protocol this server uses.
                    eprosima::rpc::protocol::Protocol &m_protocol;
            };
        } // namespace server
    } // namespace rpc
} // namespace eprosima

#endif // _SERVER_SERVER_H_
