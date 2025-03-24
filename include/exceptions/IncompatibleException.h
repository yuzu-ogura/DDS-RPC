#ifndef _EXCEPTIONS_INCOMPATIBLEEXCEPTION_H_
#define _EXCEPTIONS_INCOMPATIBLEEXCEPTION_H_

#include "SystemException.h"

namespace eprosima
{
    namespace rpc
    {
        namespace exception
        {
            /**
             * @brief This class is thrown as an exception when a selected protocol and transport
             * are incompatible.
             * 
             */
            class IncompatibleException : public SystemException
            {
                public:

                    /**
                     * @brief Default constructor.
                     *
                     * @param message An error message. This message is copied.
                     */
					IncompatibleException(const std::string &message) : SystemException(message.c_str(), 1) {}

                    /**
                     * @brief Default copy constructor.
                     *
                     * @param ex IncompatibleException that will be copied.
                     */
                    IncompatibleException(const IncompatibleException &ex);

                    /**
                     * @brief Default move constructor.
                     *
                     * @param ex IncompatibleException that will be moved.
                     */
                    IncompatibleException(IncompatibleException&& ex);

                    /**
                     * @brief Assigment operation.
                     *
                     * @param ex IncompatibleException that will be copied.
                     */
                    IncompatibleException& operator=(const IncompatibleException &ex);

                    /**
                     * @brief Assigment operation.
                     *
                     * @param ex IncompatibleException that will be moved.
                     */
                    IncompatibleException& operator=(IncompatibleException&& ex);

                    /// @brief Default constructor
                    virtual ~IncompatibleException() = default;

                    /// @brief This function throws the object as an exception.
                    virtual void raise() const;
            };
        } // namespace exception
    } // namespace rpc
} // namespace eprosima
#endif // _EXCEPTIONS_INCOMPATIBLEEXCEPTION_H_
