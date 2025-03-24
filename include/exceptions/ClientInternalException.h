#ifndef _EXCEPTIONS_CLIENTINTERNALEXCEPTION_H_
#define _EXCEPTIONS_CLIENTINTERNALEXCEPTION_H_

#include "SystemException.h"

namespace eprosima
{
    namespace rpc
    {
        namespace exception
        {
		/**
		 * @brief This class is thrown as an exception when there is an error in the proxy side.
         * 
		 */
        class ClientInternalException : public SystemException
        {
		public:

			/**
			 * @brief Default constructor.
			 *
			 * @param message An error message. This message is copied.
			 */
			ClientInternalException(const std::string &message) : SystemException(message.c_str(), 2) {}

			/**
			 * @brief Default copy constructor.
			 *
			 * @param ex ClientInternalException that will be copied.
			 */
			ClientInternalException(const ClientInternalException &ex);

			/**
			 * @brief Default move constructor.
			 *
			 * @param ex ClientInternalException that will be moved.
			 */
			ClientInternalException(ClientInternalException&& ex);

			/**
			 * @brief Assigment operation.
			 *
			 * @param ex ClientInternalException that will be copied.
			 */
			ClientInternalException& operator=(const ClientInternalException &ex);

			/**
			 * @brief Assigment operation.
			 *
			 * @param ex ClientInternalException that will be moved.
			 */
			ClientInternalException& operator=(ClientInternalException&& ex);

			/// @brief Default constructor
			virtual ~ClientInternalException() = default;

			/// @brief This function throws the object as an exception.
			virtual void raise() const;
        };
        } // namespace exception
    } // namespace rpc
} // namespace eprosima
#endif // _EXCEPTIONS_CLIENTINTERNALEXCEPTION_H_
