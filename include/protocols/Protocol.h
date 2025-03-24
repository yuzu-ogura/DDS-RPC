#ifndef _PROTOCOLS_PROTOCOL_H_
#define _PROTOCOLS_PROTOCOL_H_

namespace eprosima
{
    namespace rpc
    {
        namespace transport
        {
            class Transport;
            class Endpoint;
        }

        namespace protocol
        {
			/**
             * @brief This abstract class represents the protocol used by the RPCs. It serializes and deserializes
             *        the information and uses a eprosima::rpc::transport::Transport to send it and receive it.
             * 
             */
            class Protocol
            {
                public:

                    /**
                     * @brief This method sets a eprosima::rpc::transport::Transport object, used for the communications.
                     * 
                     * @param transport eprosima::rpc::transport::Transport to use for the communications.
                     */
                    virtual void setTransport(eprosima::rpc::transport::Transport &transport) = 0;

                protected:

                    /// @brief Default constructor.
                    Protocol() = default;

                    /// @brief Default destructor.
                    virtual ~Protocol() = default;
            };
        } // namespace protocol
    } // namespace rpc
} // namespace eprosima
#endif // _PROTOCOLS_PROTOCOL_H_
