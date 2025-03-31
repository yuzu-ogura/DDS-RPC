#include <strategies/ThreadPerRequestStrategy.h>
#include "ServerStrategyImpl.h"
#include <transports/ServerTransport.h>

#include <thread>
#include <memory>

static const char* const CLASS_NAME = "ThreadPerRequestStrategy";

namespace eprosima
{
    namespace rpc
    {
        namespace strategy
        {
            class ThreadPerRequestStrategyJob
            {
                public:
                    ThreadPerRequestStrategyJob(std::function<void()> callback)
                        : m_callback(callback)
                    {
                    }

                    void run()
                    {
                        m_callback();
                    }

                private:
                    
                    std::function<void()> m_callback;
            };

			class ThreadPerRequestStrategyImpl : public ServerStrategyImpl
            {
                public:

                    /// @brief Default constructor.
                    ThreadPerRequestStrategyImpl() = default;

                    /// @brief Default destructor.
                    virtual ~ThreadPerRequestStrategyImpl() = default;

                    /**
                     * @brief This function creates a new thread that will process the request.
                     *
                     * @param data The request. Cannot be NULL.
                     */
                    void schedule(std::function<void()> callback)
					{
                        std::shared_ptr<ThreadPerRequestStrategyJob> job = std::make_shared<ThreadPerRequestStrategyJob>(callback);
						std::thread thread(std::bind(&ThreadPerRequestStrategyJob::run, job));
						thread.detach();
					}
            };
        } // namespace strategy
    } // namespace rpc
} // namespace eprosima

using namespace eprosima::rpc;
using namespace ::strategy;
using namespace ::transport;

ThreadPerRequestStrategy::ThreadPerRequestStrategy() : m_impl(NULL)
{
    m_impl = new ThreadPerRequestStrategyImpl();
}

ThreadPerRequestStrategy::~ThreadPerRequestStrategy()
{
    if(m_impl != NULL)
        delete m_impl;
}

ServerStrategyImpl* ThreadPerRequestStrategy::getImpl()
{
	return m_impl;
}
