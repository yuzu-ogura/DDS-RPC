#ifndef _EXCEPTIONS_EXCEPTION_H_
#define _EXCEPTIONS_EXCEPTION_H_

#include <exception>

namespace eprosima
{
    namespace rpc
    {
        namespace exception
        {
            /**
             * @brief This abstract class is used to create exceptions.
             * 
             */
            class Exception : public std::exception
            {
                public:

                    /**
                     * @brief Default destructor.
                     * 
                     */
                    virtual ~Exception() = default;

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
                    Exception() = default;

                    /**
                     * @brief Default copy constructor.
                     * 
                     * @param ex Exception that will be copied.
                     */
                    Exception(const Exception &ex) = default;

                    /**
                     * @brief Default move constructor.
                     * 
                     * @param ex Exception that will be moved.
                     */
                    Exception(Exception&& ex) = default;

                    /**
                     * @brief Default copy assigment operation.
                     * 
                     * @param ex Exception that will be copied.
                     */
                    Exception& operator=(const Exception &ex) = default;

                    /**
                     * @brief Default move assigment operation.
                     * 
                     * @param ex Exception that will be moved.
                     */
                    Exception& operator=(Exception&& ex) = default;
            };
        } // namespace exception
    } // namespace rpc
} // namespace eprosima

#endif // _EXCEPTIONS_EXCEPTION_H_
