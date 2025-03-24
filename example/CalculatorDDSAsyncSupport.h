#ifndef _Calculator_DDS_ASYNC_SUPPORT_H_
#define _Calculator_DDS_ASYNC_SUPPORT_H_

#include <transports/dds/RTPSAsyncTask.h>
#include <exceptions/UserException.h>
#include "CalculatorAsyncCallbackHandlers.h"
#include "CalculatorTopics.h"
/*
 * @brief This class represents a asynchronous task created to wait the reply of the procedure Calculator::addition from the server in an asynchronous call.
 * 
 */
class Calculator_additionTask : public eprosima::rpc::transport::dds::RTPSAsyncTask
{
    public:

        /*
         * @brief The default constructor.
         *
         * @param obj Object that implements the callbacks that FastRPC will call when
         *            the reply will be received or and exception will be launched.
         * 
         */
        Calculator_additionTask(Calculator_additionCallbackHandler &obj);

        /// @brief Destructor.
        virtual ~Calculator_additionTask();
        
        /*
         * @brief This funcion is called when the reply sample is received.
         */
        virtual void execute();
        
        /*
         * @brief This function is called when an exception occurs.
         *        This exception can be launched in the server's side or in the client's side.
         *
         * @param ex The exception that will be launched.
         */
        virtual void on_exception(const eprosima::rpc::exception::SystemException &ex);        

        
        /*
         * @brief This function returns the object used by the task.
         *
         * @return The object that implements the callbacks.
         */
        Calculator_additionCallbackHandler& getObject();

        /*
         * @brief This function returns the allocated reply sample.
         * @return Pointer to the allocated reply sample.
         */
        virtual void* getReplyInstance();
        
        private:
        
        Calculator_additionCallbackHandler &m_obj;

        Calculator_Reply m_reply;
};

/*
 * @brief This class represents a asynchronous task created to wait the reply of the procedure Calculator::subtraction from the server in an asynchronous call.
 * 
 */
class Calculator_subtractionTask : public eprosima::rpc::transport::dds::RTPSAsyncTask
{
    public:

        /*
         * @brief The default constructor.
         *
         * @param obj Object that implements the callbacks that FastRPC will call when
         *            the reply will be received or and exception will be launched.
         * @param client Pointer to the server's proxy. Cannot be NULL.
         */
        Calculator_subtractionTask(Calculator_subtractionCallbackHandler &obj);

        /// @brief Destructor.
        virtual ~Calculator_subtractionTask();
        
        /*
         * @brief This funcion is called when the reply sample is received.
         */
        virtual void execute();
        
        /*
         * @brief This function is called when an exception occurs.
         *        This exception can be launched in the server's side or in the client's side.
         *
         * @param ex The exception that will be launched.
         */
        virtual void on_exception(const eprosima::rpc::exception::SystemException &ex);        

        
        /*
         * @brief This function returns the object used by the task.
         *
         * @return The object that implements the callbacks.
         */
        Calculator_subtractionCallbackHandler& getObject();

        /*
         * @brief This function returns the allocated reply sample.
         * @return Pointer to the allocated reply sample.
         */
        virtual void* getReplyInstance();
        
        private:
        
        Calculator_subtractionCallbackHandler &m_obj;

        Calculator_Reply m_reply;
};





#endif // _Calculator_DDS_ASYNC_SUPPORT_H_