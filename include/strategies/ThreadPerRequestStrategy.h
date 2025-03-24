#ifndef _STRATEGIES_THREADPERREQUESTSTRATEGY_H_
#define _STRATEGIES_THREADPERREQUESTSTRATEGY_H_

#include "ServerStrategy.h"

namespace eprosima
{
    namespace rpc
    {
        namespace strategy
        {
			class ThreadPerRequestStrategyImpl;

            /**
             * @brief This class implements the thread per request strategy.
             *        The server creates a new thread for every new incoming request.
             * 
             */
            class ThreadPerRequestStrategy : public ServerStrategy
            {
                public:

                    /// @brief Default constructor.
                    ThreadPerRequestStrategy();

                    /// @brief Default destructor.
                    virtual ~ThreadPerRequestStrategy();
					
					/**
                     * @brief Gets the implementation of the strategy.
                     * 
                     * @return Implementation of the strategy.
                     */
                    ServerStrategyImpl* getImpl();

			    private:

					/// @brief Implementation of the strategy.
					ThreadPerRequestStrategyImpl *m_impl;
            };
        } // namespace strategy
    } // namespace rpc
} //namespace eprosima

#endif // _STRATEGIES_THREADPERREQUESTSTRATEGY_H_

