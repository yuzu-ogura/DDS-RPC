#ifndef _EXCEPTIONS_USEREXCEPTION_H_
#define _EXCEPTIONS_USEREXCEPTION_H_

#include "Exception.h"

#include <cstdint>

namespace eprosima
{
    namespace rpc
    {
        namespace exception
        {
            /**
             * @brief This abstract class is used to create user exceptions.
             * 
             */
            class UserException : public Exception
            {
                public:

                    /**
                     * @brief Default destructor.
                     * 
                     */
                    virtual ~UserException() = default;

                    /**
                     * @brief This function throws the object as exception.
                     * 
                     */
                    virtual void raise() const = 0;

                protected:

                    /**
                     * @brief Default constructor.
                     * 
                     */
                    UserException() = default;

                    /**
                     * @brief Default copy constructor.
                     *
                     * @param ex UserException that will be copied.
                     */
                    UserException(const UserException &ex) = default;

                    /**
                     * @brief Default move constructor.
                     *
                     * @param ex UserException that will be moved.
                     */
                    UserException(UserException&& ex) = default;

                    /**
                     * @brief Default copy assigment operation.
                     *
                     * @param ex UserException that will be copied.
                     */
                    UserException& operator=(const UserException &ex) = default;

                    /**
                     * @brief Default move assigment operation.
                     *
                     * @param ex UserException that will be moved.
                     */
                    UserException& operator=(UserException&& ex) = default;
            };
        } // namespace exception
    } // namespace rpc
} // namespace eprosima

#endif // _EXCEPTIONS_USEREXCEPTION_H_

