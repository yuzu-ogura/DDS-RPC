#include "CalculatorDDSProtocol.h"
#include <transports/Transport.h>
#include <transports/dds/RTPSProxyTransport.h>
#include <transports/dds/components/RTPSProxyProcedureEndpoint.h>
#include "CalculatorDDSAsyncSupport.h"
#include <transports/dds/RTPSServerTransport.h>
#include <transports/dds/components/RTPSServerProcedureEndpoint.h>
#include <exceptions/Exceptions.h>

#include <fastrtps/Domain.h>

using namespace eprosima::rpc;
using namespace ::protocol::dds;
using namespace ::transport;
using namespace ::exception;

CalculatorProtocol::CalculatorProtocol() : ::protocol::CalculatorProtocol(), m_ddsTransport(NULL)
, Calculator_str("Calculator")
, Calculator_pe(NULL), Calculator_se(NULL)
{
}

CalculatorProtocol::~CalculatorProtocol()
{
}

void CalculatorProtocol::setTransport(Transport &transport)
{
    m_ddsTransport = dynamic_cast<eprosima::rpc::transport::dds::RTPSTransport*>(&transport);
    m_ddsTransport->initialize();
}

bool CalculatorProtocol::activateInterface(const char* interfaceName)
{
    std::string requesttopicName, replytopicName;

    if(m_ddsTransport != NULL)
    {
        TransportBehaviour behaviour = dynamic_cast<Transport*>(m_ddsTransport)->getBehaviour();
        
        if(strcmp(interfaceName, "Calculator") == 0)
        {
            eprosima::fastrtps::Domain::registerType(m_ddsTransport->getParticipant(), &Calculator_requestPlugin);

            requesttopicName = "Calculator_";
            requesttopicName += m_ddsTransport->getRemoteServiceName();
            requesttopicName += "_Request";
            
            eprosima::fastrtps::Domain::registerType(m_ddsTransport->getParticipant(), &Calculator_replyPlugin);

            replytopicName = "Calculator_";
            replytopicName += m_ddsTransport->getRemoteServiceName();
            replytopicName += "_Reply";
            
            if(behaviour == ::transport::PROXY_BEHAVIOUR)
            {
                Calculator_pe = dynamic_cast<eprosima::rpc::transport::dds::RTPSProxyProcedureEndpoint*>(m_ddsTransport->createProcedureEndpoint(Calculator_str,
                Calculator_requestPlugin.getName(),
                requesttopicName.c_str(),
                Calculator_replyPlugin.getName(),
                replytopicName.c_str(),
                std::bind(&Calculator_ReplyPubSubType::createData, &Calculator_replyPlugin),
                std::bind(&Calculator_ReplyPubSubType::copyData, &Calculator_replyPlugin, std::placeholders::_1, std::placeholders::_2),
                std::bind(&Calculator_ReplyPubSubType::deleteData, &Calculator_replyPlugin, std::placeholders::_1),
                NULL,
                sizeof(Calculator_Reply)
                ));
            }
            if(behaviour == ::transport::SERVER_BEHAVIOUR)
            {
                Calculator_se = dynamic_cast<eprosima::rpc::transport::dds::RTPSServerProcedureEndpoint*>(m_ddsTransport->createProcedureEndpoint(Calculator_str,
                    Calculator_replyPlugin.getName(),
                    replytopicName.c_str(),
                    Calculator_requestPlugin.getName(),
                    requesttopicName.c_str(),
                    std::bind(&Calculator_RequestPubSubType::createData, &Calculator_requestPlugin),
                    std::bind(&Calculator_RequestPubSubType::copyData, &Calculator_requestPlugin, std::placeholders::_1, std::placeholders::_2),
                    std::bind(&Calculator_RequestPubSubType::deleteData, &Calculator_requestPlugin, std::placeholders::_1),
                    CalculatorProtocol::Calculator_serve,
                    sizeof(Calculator_Request)));
            }
        }
        
        return true;
    }
    else
    {
      // TODO Trace.
    }
    
    return false;
}

void CalculatorProtocol::Calculator_serve(eprosima::rpc::protocol::Protocol &protocol,
    void *_data , eprosima::rpc::transport::Endpoint *endpoint)
{
    CalculatorProtocol &_protocol = dynamic_cast<CalculatorProtocol&>(protocol);
    Calculator_Request &requestData = *(Calculator_Request*)_data;

    switch(requestData.data()._d())
    {
                case 0xCBC6CEAA:
                {
                int32_t  value1 = 0;
                int32_t  value2 = 0;
                int32_t  return_ = 0;   
                Calculator_Reply replyData;
                replyData.header().relatedRequestId(requestData.header().requestId());
                replyData.header().relatedInstanceName(requestData.header().instanceName());
                replyData.header().remoteEx(eprosima::rpc::protocol::REMOTE_EX_OK);

                replyData.data()._d() = 0xCBC6CEAA;


                value1 = requestData.data().addition().value1();
                value2 = requestData.data().addition().value2();

                try
                {
                    if(_protocol._Calculator_impl != NULL)
                    {
                        return_ = _protocol._Calculator_impl->addition(value1, value2);

                        replyData.data().addition()._d() = 0;

                        replyData.data().addition().result().return_(return_);

                        _protocol.Calculator_se->sendReply(&replyData);
                    }
                }
                catch(const ServerInternalException &)
                {
                    replyData.header().remoteEx(eprosima::rpc::protocol::REMOTE_EX_UNSUPPORTED);

                    _protocol.Calculator_se->sendReply(&replyData);
                }



                }
                break;
                
                case 0xCA019A14:
                {
                int32_t  value1 = 0;
                int32_t  value2 = 0;
                int32_t  return_ = 0;   
                Calculator_Reply replyData;
                replyData.header().relatedRequestId(requestData.header().requestId());
                replyData.header().relatedInstanceName(requestData.header().instanceName());
                replyData.header().remoteEx(eprosima::rpc::protocol::REMOTE_EX_OK);

                replyData.data()._d() = 0xCA019A14;


                value1 = requestData.data().subtraction().value1();
                value2 = requestData.data().subtraction().value2();

                try
                {
                    if(_protocol._Calculator_impl != NULL)
                    {
                        return_ = _protocol._Calculator_impl->subtraction(value1, value2);

                        replyData.data().subtraction()._d() = 0;

                        replyData.data().subtraction().result().return_(return_);

                        _protocol.Calculator_se->sendReply(&replyData);
                    }
                }
                catch(const ServerInternalException &)
                {
                    replyData.header().remoteEx(eprosima::rpc::protocol::REMOTE_EX_UNSUPPORTED);

                    _protocol.Calculator_se->sendReply(&replyData);
                }



                }
                break;
                
    };        
}
int32_t CalculatorProtocol::Calculator_addition(/*in*/ int32_t value1, /*in*/ int32_t value2)
{
    ReturnMessage retcode = CLIENT_INTERNAL_ERROR;
    int32_t  return_ = 0;
    Calculator_Request instance;
    Calculator_Reply retInstance;



    instance.data()._d() = 0xCBC6CEAA;
    
    instance.data().addition().value1(value1);
    instance.data().addition().value2(value2);

    retcode = Calculator_pe->send(&instance, &retInstance);
    
    if(retcode == OK)
    {
        if(retInstance.header().remoteEx() == eprosima::rpc::protocol::REMOTE_EX_OK)
        {
            switch (retInstance.data().addition()._d())
            {
                case 0:
		            return_ = retInstance.data().addition().result().return_();
                    break;
                default:
                    throw ClientInternalException("Error extracting information from server");
            }
        }
        else
            retcode = SERVER_INTERNAL_ERROR;
    }
      
    switch (retcode)
    {
        case CLIENT_INTERNAL_ERROR:
            throw ClientInternalException("Error in client side");
            break;
        case SERVER_NOT_FOUND:
            throw ServerNotFoundException("Cannot connect to the server");
            break;
        case TIMEOUT:
            throw ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case SERVER_INTERNAL_ERROR:
            throw ServerInternalException("");
            break;
        default:
            break;
    };
    

    return return_;
}
void CalculatorProtocol::Calculator_addition_async(Calculator_additionCallbackHandler &obj, /*in*/ int32_t value1, /*in*/ int32_t value2)
{
    ReturnMessage retcode = CLIENT_INTERNAL_ERROR;
    Calculator_Request instance;
    Calculator_additionTask *task = new Calculator_additionTask(obj);

    instance.data()._d() = 0xCBC6CEAA;
    
    instance.data().addition().value1(value1);
    instance.data().addition().value2(value2);

    retcode = Calculator_pe->send_async(&instance, task);
    
    switch (retcode)
    {
        case CLIENT_INTERNAL_ERROR:
            throw ClientInternalException("Error in client side");
            break;
        case SERVER_NOT_FOUND:
            throw ServerNotFoundException("Cannot connect to the server");
            break;
        default:
            break;
    }
}

int32_t CalculatorProtocol::Calculator_subtraction(/*in*/ int32_t value1, /*in*/ int32_t value2)
{
    ReturnMessage retcode = CLIENT_INTERNAL_ERROR;
    int32_t  return_ = 0;
    Calculator_Request instance;
    Calculator_Reply retInstance;



    instance.data()._d() = 0xCA019A14;
    
    instance.data().subtraction().value1(value1);
    instance.data().subtraction().value2(value2);

    retcode = Calculator_pe->send(&instance, &retInstance);
    
    if(retcode == OK)
    {
        if(retInstance.header().remoteEx() == eprosima::rpc::protocol::REMOTE_EX_OK)
        {
            switch (retInstance.data().subtraction()._d())
            {
                case 0:
		            return_ = retInstance.data().subtraction().result().return_();
                    break;
                default:
                    throw ClientInternalException("Error extracting information from server");
            }
        }
        else
            retcode = SERVER_INTERNAL_ERROR;
    }
      
    switch (retcode)
    {
        case CLIENT_INTERNAL_ERROR:
            throw ClientInternalException("Error in client side");
            break;
        case SERVER_NOT_FOUND:
            throw ServerNotFoundException("Cannot connect to the server");
            break;
        case TIMEOUT:
            throw ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case SERVER_INTERNAL_ERROR:
            throw ServerInternalException("");
            break;
        default:
            break;
    };
    

    return return_;
}
void CalculatorProtocol::Calculator_subtraction_async(Calculator_subtractionCallbackHandler &obj, /*in*/ int32_t value1, /*in*/ int32_t value2)
{
    ReturnMessage retcode = CLIENT_INTERNAL_ERROR;
    Calculator_Request instance;
    Calculator_subtractionTask *task = new Calculator_subtractionTask(obj);

    instance.data()._d() = 0xCA019A14;
    
    instance.data().subtraction().value1(value1);
    instance.data().subtraction().value2(value2);

    retcode = Calculator_pe->send_async(&instance, task);
    
    switch (retcode)
    {
        case CLIENT_INTERNAL_ERROR:
            throw ClientInternalException("Error in client side");
            break;
        case SERVER_NOT_FOUND:
            throw ServerNotFoundException("Cannot connect to the server");
            break;
        default:
            break;
    }
}



