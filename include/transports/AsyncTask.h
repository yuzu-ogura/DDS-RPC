#ifndef _TRANSPORTS_ASYNCTASK_H_
#define _TRANSPORTS_ASYNCTASK_H_

namespace eprosima
{
    namespace rpc
    {
        namespace transport
        {
            /**
             * @brief This class represents a asynchronous task created to wait the reply from the server in an asynchronous call.
             * 
             */
            class AsyncTask
            {
                protected:

                /// @brief Default constructor.
                AsyncTask() = default;

                /// @brief Destructor.
                virtual ~AsyncTask() = default;
            };
        } // namespace transport
    } // namespace rpc
} // namespace eprosima

#endif // _TRANSPORTS_ASYNCTASK_H_
