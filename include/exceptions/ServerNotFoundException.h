#ifndef _EXCEPTIONS_SERVERNOTFOUNDEXCEPTION_H_
#define _EXCEPTIONS_SERVERNOTFOUNDEXCEPTION_H_

#include "SystemException.h"

namespace eprosima
{
    namespace rpc
    {
        namespace exception
        {
            /**
             * @brief This class is thrown as an exception when the server is not found.
             * 
             */
            class ServerNotFoundException : public SystemException
            {
                public:

                    /**
                     * @brief Default constructor.
                     *
                     * @param message An error message. This message is copied.
                     */
					ServerNotFoundException(const std::string &message) : SystemException(message.c_str(), 4) {}

                    /**
                     * @brief Default copy constructor.
                     *
                     * @param ex ServerNotFoundException that will be copied.
                     */
                    ServerNotFoundException(const ServerNotFoundException &ex);

                    /**
                     * @brief Default move constructor.
                     *
                     * @param ex ServerNotFoundException that will be moved.
                     */
                    ServerNotFoundException(ServerNotFoundException&& ex);

                    /**
                     * @brief Assigment operation.
                     *
                     * @param ex ServerNotFoundException that will be copied.
                     */
                    ServerNotFoundException& operator=(const ServerNotFoundException &ex);

                    /**
                     * @brief Assigment operation.
                     *
                     * @param ex ServerNotFoundException that will be moved.
                     */
                    ServerNotFoundException& operator=(ServerNotFoundException&& ex);

                    /// @brief Default constructor
                    virtual ~ServerNotFoundException() = default;

                    /// @brief This function throws the object as an exception.
                    virtual void raise() const;
            };
        } // namespace exception
    } // namespace rpc
} // namespace eprosima
#endif // _EXCEPTIONS_SERVERNOTFOUNDEXCEPTION_H_
