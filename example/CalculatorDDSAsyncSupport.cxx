#include "CalculatorDDSAsyncSupport.h"
#include <exceptions/ServerInternalException.h>
#include <exceptions/ClientInternalException.h>
#include <utils/Messages.h>

using namespace eprosima::rpc;
using namespace ::exception;

Calculator_additionTask::Calculator_additionTask(Calculator_additionCallbackHandler &obj) :
    RTPSAsyncTask(), m_obj(obj)
{
}

Calculator_additionTask::~Calculator_additionTask()
{
}

Calculator_additionCallbackHandler& Calculator_additionTask::getObject()
{
    return m_obj;
}

void* Calculator_additionTask::getReplyInstance()
{
    return &m_reply;
}

void Calculator_additionTask::execute()
{  
    int32_t  return_ = 0;
    
    if(m_reply.header().remoteEx() == eprosima::rpc::protocol::REMOTE_EX_OK)
    {
        switch (m_reply.data().addition()._d())
        {
            case 0:
                return_ = m_reply.data().addition().result().return_();
	    	    getObject().addition(return_);
                break;
            default:
                getObject().on_exception(ClientInternalException("Error extracting information from server"));
        }
    }
    else
        getObject().on_exception(ServerInternalException(""));
}

void Calculator_additionTask::on_exception(const SystemException &ex)
{
    getObject().on_exception(ex);
}


Calculator_subtractionTask::Calculator_subtractionTask(Calculator_subtractionCallbackHandler &obj) :
    RTPSAsyncTask(), m_obj(obj)
{
}

Calculator_subtractionTask::~Calculator_subtractionTask()
{
}

Calculator_subtractionCallbackHandler& Calculator_subtractionTask::getObject()
{
    return m_obj;
}

void* Calculator_subtractionTask::getReplyInstance()
{
    return &m_reply;
}

void Calculator_subtractionTask::execute()
{  
    int32_t  return_ = 0;
    
    if(m_reply.header().remoteEx() == eprosima::rpc::protocol::REMOTE_EX_OK)
    {
        switch (m_reply.data().subtraction()._d())
        {
            case 0:
                return_ = m_reply.data().subtraction().result().return_();
	    	    getObject().subtraction(return_);
                break;
            default:
                getObject().on_exception(ClientInternalException("Error extracting information from server"));
        }
    }
    else
        getObject().on_exception(ServerInternalException(""));
}

void Calculator_subtractionTask::on_exception(const SystemException &ex)
{
    getObject().on_exception(ex);
}




