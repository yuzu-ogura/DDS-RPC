#ifndef _Calculator_ASYNC_CALLBACK_HANDLERS_H_
#define _Calculator_ASYNC_CALLBACK_HANDLERS_H_

#include <exceptions/SystemException.h>
#include <exceptions/UserException.h>
#include "Calculator.h"

/*
 * @brief This abstract class defines the callbacks that eProsima RPC will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * 
 */
class Calculator_additionCallbackHandler
{
    public:
        /*
         * This function is called when is received the reply from the server.
         */
        virtual void addition(/*out*/ int32_t return_) = 0;
        
        /*
         * @brief This function is called when an exception occurs.
         *        This exception can be launched in the server's side or in the client's side.
         *
         * @param ex The exception that will be launched.
         */
        virtual void on_exception(const eprosima::rpc::exception::SystemException &ex) = 0;
};

/*
 * @brief This abstract class defines the callbacks that eProsima RPC will call in an asynchronous call.
 *        These callback has to be implemented in a derived class.
 * 
 */
class Calculator_subtractionCallbackHandler
{
    public:
        /*
         * This function is called when is received the reply from the server.
         */
        virtual void subtraction(/*out*/ int32_t return_) = 0;
        
        /*
         * @brief This function is called when an exception occurs.
         *        This exception can be launched in the server's side or in the client's side.
         *
         * @param ex The exception that will be launched.
         */
        virtual void on_exception(const eprosima::rpc::exception::SystemException &ex) = 0;
};



#endif // _Calculator_ASYNC_CALLBACK_HANDLERS_H_