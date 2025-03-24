#ifndef _EXCEPTIONS_INITIALIZEEXCEPTION_H_
#define _EXCEPTIONS_INITIALIZEEXCEPTION_H_

#include "SystemException.h"

namespace eprosima
{
    namespace rpc
    {
        namespace exception
        {
            /**
             * @brief This class is thrown as an exception when there is an error initializating an object.
             * 
             */
            class InitializeException : public SystemException
            {
                public:

                    /**
                     * @brief Default constructor.
                     *
                     * @param message An error message. This message is copied.
                     */
					InitializeException(const std::string &message) : SystemException(message.c_str(), 1){}

                    /**
                     * @brief Default copy constructor.
                     *
                     * @param ex InitializeException that will be copied.
                     */
                    InitializeException(const InitializeException &ex);

                    /**
                     * @brief Default move constructor.
                     *
                     * @param ex InitializeException that will be moved.
                     */
                    InitializeException(InitializeException&& ex);

                    /**
                     * @brief Assigment operation.
                     *
                     * @param ex InitializeException that will be copied.
                     */
                    InitializeException& operator=(const InitializeException &ex);

                    /**
                     * @brief Assigment operation.
                     *
                     * @param ex InitializeException that will be moved.
                     */
                    InitializeException& operator=(InitializeException&& ex);

                    /// @brief Default constructor
                    virtual ~InitializeException() = default;

                    /// @brief This function throws the object as an exception.
                    virtual void raise() const;
            };
        } // namespace exception
    } // namespace rpc
} // namespace eprosima
#endif // _EXCEPTIONS_INITIALIZEEXCEPTION_H_
