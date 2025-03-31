#include <strategies/SingleThreadStrategy.h>
#include "ServerStrategyImpl.h"
#include <transports/ServerTransport.h>

static const char* const CLASS_NAME = "SingleThreadStrategy";

namespace eprosima
{
    namespace rpc
    {
        namespace strategy
        {
			class SingleThreadStrategyImpl : public ServerStrategyImpl
			{
				public:

					SingleThreadStrategyImpl() = default;

					virtual ~SingleThreadStrategyImpl() = default;

					void schedule(std::function<void()> callback)
					{
						const char* const METHOD_NAME = "schedule";

						if(callback)
						{
							callback();
						}
						else
						{
							printf("ERROR<%s::%s>: Bad parameters\n", CLASS_NAME, METHOD_NAME);
						}
					}
			};
         } // namespace strategy
    } // namespace rpc
} //namespace eprosima

using namespace eprosima::rpc;
using namespace ::strategy;
using namespace ::transport;

SingleThreadStrategy::SingleThreadStrategy() : m_impl(NULL)
{
    m_impl = new SingleThreadStrategyImpl();
}

SingleThreadStrategy::~SingleThreadStrategy()
{
    if(m_impl != NULL)
        delete m_impl;
}

ServerStrategyImpl* SingleThreadStrategy::getImpl()
{
	return m_impl;
}
