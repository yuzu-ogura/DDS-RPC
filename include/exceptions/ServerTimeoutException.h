#ifndef _EXCEPTIONS_SERVERTIMEOUTEXCEPTION_H_
#define _EXCEPTIONS_SERVERTIMEOUTEXCEPTION_H_

#include "SystemException.h"

namespace eprosima
{
    namespace rpc
    {
        namespace exception
        {
            /**
             * @brief This class is thrown as an exception when the remote procedure call exceeds the maximum time.
             * @ingroup EXCEPTIONMODULE
             */
            class ServerTimeoutException : public SystemException
            {
                public:

                    /**
                     * @brief Default constructor.
                     *
                     * @param message An error message. This message is copied.
                     */
					ServerTimeoutException(const std::string &message) : SystemException(message.c_str(), 5) {}

                    /**
                     * @brief Default copy constructor.
                     *
                     * @param ex ServerTimeoutException that will be copied.
                     */
                    ServerTimeoutException(const ServerTimeoutException &ex);

                    /**
                     * @brief Default move constructor.
                     *
                     * @param ex ServerTimeoutException that will be moved.
                     */
                    ServerTimeoutException(ServerTimeoutException&& ex);

                    /**
                     * @brief Assigment operation.
                     *
                     * @param ex ServerTimeoutException that will be copied.
                     */
                    ServerTimeoutException& operator=(const ServerTimeoutException &ex);

                    /**
                     * @brief Assigment operation.
                     *
                     * @param ex ServerTimeoutException that will be moved.
                     */
                    ServerTimeoutException& operator=(ServerTimeoutException&& ex);

                    /// @brief Default constructor
                    virtual ~ServerTimeoutException() = default;

                    /// @brief This function throws the object as an exception.
                    virtual void raise() const;
            };
        } // namespace exception
    } // namespace rpc
} // namespace eprosima
#endif // _EXCEPTIONS_SERVERTIMEOUTEXCEPTION_H_
