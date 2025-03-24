#ifndef _SERVER_SERVERSTRATEGY_H_
#define _SERVER_SERVERSTRATEGY_H_

namespace eprosima
{
    namespace rpc
    {
        namespace strategy
        {
			class ServerStrategyImpl;

            /**
             * @brief This class is the base of all classes that implement a server strategy
             *        that could be used by the server.
             * 
             */
            class ServerStrategy
            {
                public:

                    /// @brief Default constructor.
                    ServerStrategy() = default;

                    /// @brief Default destructor.
                    virtual ~ServerStrategy() = default;

					/**
                     * @brief Gets the implementation of the strategy.
                     * 
                     * @return Implementation of the strategy.
                     */
                    virtual ServerStrategyImpl* getImpl() = 0;
            };
        } // namespace strategy
    } // namespace rpc
} // namespace eprosima

#endif // _SERVER_SERVERSTRATEGY_H_
