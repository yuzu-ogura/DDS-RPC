#ifndef _CLIENT_PROXY_H_
#define _CLIENT_PROXY_H_

namespace eprosima
{
    namespace rpc
    {
        namespace transport
        {
            class ProxyTransport;
        }

        namespace protocol
        {
            class Protocol;
        }

        namespace proxy
        {
            /**
             * @brief This class implements the common functionalities that all server's proxies have.
             * 
             */
            class Proxy
            {
                protected:

                    /**
                     * @brief Construct a new Proxy object
                     * 
                     * @param transport The transport that will be used by the server's proxy. This class doesn't delete this object in its destructor.
                     * @param protocol The protocol used to send request and reply over the transport. This class doesn't delete this object in its destructor.
                     */
                    Proxy(eprosima::rpc::transport::ProxyTransport &transport, eprosima::rpc::protocol::Protocol &protocol);

                    /**
                     * @brief Default destructor.
                     * 
                     */
                    virtual ~Proxy() = default;
                    
					/**
					 * @brief Get the Protocol object
					 * 
					 * @return The reference of Protocol object
					 */
                    eprosima::rpc::protocol::Protocol& getProtocol() const
                    {
                        return m_protocol;
                    }
						
					/**
					 * @brief Get the Transport object
					 * 
					 * @return The reference of ProxyTransport object
					 */
                    eprosima::rpc::transport::ProxyTransport& getTransport() const
                    {
                        return m_transport;
                    }

                private:

                    /// @brief Pointer to the transport that this server's proxy uses.
                    eprosima::rpc::transport::ProxyTransport &m_transport;

                    /// @brief Pointer to the protocol that this server's proxy uses.
                    eprosima::rpc::protocol::Protocol &m_protocol;
            };
        } // namespace proxy
    } // namespace rpc
} // namespace eprosima

#endif // _CLIENT_PROXY_H_
