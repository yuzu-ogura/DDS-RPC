#include <strategies/ThreadPoolStrategy.h>
#include "ServerStrategyImpl.h"
#include <transports/ServerTransport.h>

#include "ctpl_stl.h"

static const char* const CLASS_NAME = "ThreadPoolStrategy";

namespace eprosima
{
    namespace rpc
    {
        namespace strategy
        {
            class ThreadPoolStrategyJob
            {
            public:
                ThreadPoolStrategyJob(std::function<void()> callback) : m_callback(callback)
                {
                }

                void run()
                {
                    m_callback();
                }

            private:
                std::function<void()> m_callback;
            };

            class ThreadPoolStrategyImpl : public ServerStrategyImpl
            {
            public:
                ThreadPoolStrategyImpl(uint32_t threadCount)
                {
                    m_pool = new ctpl::thread_pool(threadCount);
                }

                virtual ~ThreadPoolStrategyImpl()
                {
                    delete m_pool;
                }

                ctpl::thread_pool *getPool()
                {
                    return m_pool;
                }

                void schedule(std::function<void()> callback)
                {
                    std::shared_ptr<ThreadPoolStrategyJob> job = std::make_shared<ThreadPoolStrategyJob>(callback);
                    m_pool->push(std::bind(&ThreadPoolStrategyJob::run, job));
                }

            private:
                ctpl::thread_pool *m_pool = nullptr;
            };

        } // namespace strategy
    } // namespace rpc
} // namespace eprosima

using namespace eprosima::rpc;
using namespace ::strategy;
using namespace ::transport;

ThreadPoolStrategy::ThreadPoolStrategy(uint32_t threadCount) : m_impl(NULL)
{
    m_impl = new ThreadPoolStrategyImpl(threadCount);
}

ThreadPoolStrategy::~ThreadPoolStrategy()
{
    if (m_impl != NULL)
    {
        delete m_impl;
    }
}

ServerStrategyImpl* ThreadPoolStrategy::getImpl()
{
    return m_impl;
}
