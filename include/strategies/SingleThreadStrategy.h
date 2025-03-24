#ifndef _STRATEGIES_SINGLETHREADSTRATEGY_H_
#define _STRATEGIES_SINGLETHREADSTRATEGY_H_

#include "ServerStrategy.h"

namespace eprosima
{
    namespace rpc
    {
        namespace strategy
        {
			class SingleThreadStrategyImpl;

            /**
             * @brief This class implements the single thread strategy.
             *        The server uses a reception thread to execute all the requests.
             * 
             */
            class SingleThreadStrategy : public ServerStrategy
            {
                public:

                    /// @brief Default constructor.
                    SingleThreadStrategy();

                    /// @brief Default destructor.
                    virtual ~SingleThreadStrategy();
					
					/**
                     * @brief Gets the implementation of the strategy.
                     * 
                     * @return Implementation of the strategy.
                     */
					ServerStrategyImpl* getImpl();

			    private:

					/// @brief Implementation of the strategy.
					SingleThreadStrategyImpl *m_impl;
            };
        } // namespace strategy
    } // namespace rpc
} //namespace eprosima

#endif // _STRATEGIES_SINGLETHREADSTRATEGY_H_
