#ifndef _TRANSPORTS_DDS_DDSASYNCTASK_H_
#define _TRANSPORTS_DDS_DDSASYNCTASK_H_

#include "../AsyncTask.h"
#include "../../exceptions/SystemException.h"

namespace eprosima
{
    namespace rpc
    {
        namespace transport
        {
            namespace dds
            {
                /**
                 * @brief This class represents a asynchronous task created to wait the reply from the server in an asynchronous call.
                 * 
                 */
                class RTPSAsyncTask : public eprosima::rpc::transport::AsyncTask
                {
                    public:

						/// @brief default constructor
                        RTPSAsyncTask() = default;
						
						/// @brief default destructor
                        virtual ~RTPSAsyncTask() = default;

                        /**
                         * @brief This function executes the callback function when an exception occurs on the client's side.
                         *        This function should be implemented by the generated asynchronous tasks.
                         *
                         */
                        virtual void on_exception(const exception::SystemException &ex) = 0;

                        /**
                         * @brief This function executes the callback functions when a reply is received or an exception was transmitted.
                         *        This function should be implemented by the generated asynchronous tasks.
                         */
                        virtual void execute() = 0;

                        /**
                         * @brief Returns the allocated memory that will be used when the reply is taken.
                         *
                         * @return Pointer to the allocated memory.
                         */
                        virtual void* getReplyInstance() = 0;
                };
            } // namespace dds
        } // namespace transport
    } // namespace rpc
} // namespace eprosima

#endif // _TRANSPORTS_DDS_RTPSASYNCTASK_H_
