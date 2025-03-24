#ifndef _SERVER_SERVERSTRATEGYIMPL_H_
#define _SERVER_SERVERSTRATEGYIMPL_H_

#include <functional>

namespace eprosima
{
    namespace rpc
    {
        namespace transport
        {
            class ServerTransport;
            class Endpoint;
        }

        namespace strategy
        {
            /**
             * @brief This class is the base of all classes that implement a server strategy.
             *        that could be used by the server.
             * 
             */
            class ServerStrategyImpl
            {
                public:

                    /// @brief Default constructor.
                    ServerStrategyImpl() = default;

                    /// @brief Default destructor.
                    virtual ~ServerStrategyImpl() = default;

                    /**
                     * @brief This function schedules an incoming request.
                     *        This function has to be implemented by the derived classes.
                     *
                     * @param callback The Server's method to invoke when a request arrives.
                     */
                    virtual void schedule(std::function<void()> callback) = 0;
            };
        } // namespace strategy
    } // namespace rpc
} // namespace eprosima

#endif // _SERVER_SERVERSTRATEGYIMPL_H_
