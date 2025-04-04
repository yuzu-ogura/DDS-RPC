#ifndef _TRANSPORTS_SERVERTRANSPORT_H_
#define _TRANSPORTS_SERVERTRANSPORT_H_

#include "Transport.h"
#include "components/Endpoint.h"

#include <stdio.h>

namespace eprosima
{
    namespace rpc
    {
        namespace protocol
        {
            class Protocol;
        }


        namespace strategy
        {
            class ServerStrategy;
        }

        namespace transport
        {
            /*
             * @brief This interface is the base of all classes that implement a transport
             *        that can be used by the server.
             * @ingroup TRANSPORTMODULE
             */
            class ServerTransport : public Transport
            {
                typedef size_t (*ServerTransport_Callback)(eprosima::rpc::protocol::Protocol&, void*&, size_t&, size_t&, Endpoint*);

                public:

                    /// @brief Default constructor.
                    ServerTransport() = default;

                    /// @brief Default destructor.
                    virtual ~ServerTransport() = default;

					/*
					 * @brief Sets the threading strategy.
					 * @param strategy Threading strategy.
					 */
                    void setStrategy(eprosima::rpc::strategy::ServerStrategy &strategy)
                    {
                        m_strategy = &strategy;
                    }

					/*
					 * @brief Sets the communication protocol.
					 * @param protocol Communication protocol.
					 */
                    void linkProtocol(eprosima::rpc::protocol::Protocol &protocol)
                    {
                        m_protocol = &protocol;
                    }

					/*
					 * @brief Gets the communication protocol.
					 * @return Communication protocol.
					 */
                    eprosima::rpc::protocol::Protocol& getLinkedProtocol()
                    {
                        return *m_protocol;
                    }

					/*
					 * @brief Gets the threading strategy.
					 * @return Threading strategy.
					 */
                    eprosima::rpc::strategy::ServerStrategy& getStrategy() const
                    {
                        return *m_strategy;
                    }

					/*
					 * @brief Gets the callback that will proccess the requests.
					 * @return Callback that will proccess the requests.
					 */
                    ServerTransport_Callback getCallback() const
                    {
                        return m_callback;
                    }

					/*
					 * @brief Gets the callback that will proccess the requests.
					 * @param Callback Callback that will proccess the requests.
					 */
                    void setCallback(ServerTransport_Callback callback)
                    {
                        m_callback = callback;
                    }

                    /*
                     * @brief This function returns the behaviour of the transport.
                     * @return The behaviour of the transport.
                     */
                    TransportBehaviour getBehaviour() const
                    {
                        return SERVER_BEHAVIOUR;
                    }

                    /*
                     * @brief This function returns the type of the transport.
                     *        This function has to be implemented by the child classes.
                     */
                    virtual const char* getType() const = 0;

					/*
					 * @brief This method runs the TCP server needed for the HTTP connections.
					 */
                    virtual void run() = 0;

					/*
					 * @brief This method stops the TCP server needed for the HTTP connections.
					 */
                    virtual void stop() = 0;

					/*
					 * @brief This function is used to send a reply to a proxy.
					 * @param data Response to send.
					 * @param dataLength Length of the data to send.
					 * @param endpoint Targeg entpoint to send the data to.
					 */
                    virtual void sendReply(void *data, size_t dataLength, Endpoint *endpoint) = 0;

					/*
					 * @brief This function is used to send a reply to a proxy.
					 * @param buffer Buffer to allocate the received data
					 * @param bufferLength Size of the buffer
					 * @param dataToRead Size of the data to read
					 * @param endpoint Endpoint to receive the data from
					 */
                    virtual int receive(char *buffer, size_t bufferLength, size_t &dataToRead, Endpoint *endpoint) = 0; 

                private:

                    eprosima::rpc::strategy::ServerStrategy *m_strategy{nullptr};

                    eprosima::rpc::protocol::Protocol *m_protocol{nullptr};

                    ServerTransport_Callback m_callback{nullptr};
            };
        }
        // namespace transport
    }// namespace rpc
} // namespace eprosima
#endif // _TRANSPORTS_SERVERTRANSPORT_H_
