#include "CalculatorProxy.h"
#include <transports/ProxyTransport.h>
#include "CalculatorProtocol.h"

CalculatorProxy::CalculatorProxy(eprosima::rpc::transport::ProxyTransport &transport,
    eprosima::rpc::protocol::CalculatorProtocol &protocol) : Proxy(transport, protocol)
{
    protocol.activateInterface("Calculator");
}

CalculatorProxy::~CalculatorProxy()
{
}
 
int32_t CalculatorProxy::addition(/*in*/ int32_t value1, /*in*/ int32_t value2)
{
    int32_t return_ =
    dynamic_cast<eprosima::rpc::protocol::CalculatorProtocol&>(getProtocol()).Calculator_addition(value1, value2);
    return return_;
}

void CalculatorProxy::addition_async(Calculator_additionCallbackHandler &obj, /*in*/ int32_t value1, /*in*/ int32_t value2)
{
    dynamic_cast<eprosima::rpc::protocol::CalculatorProtocol&>(getProtocol()).Calculator_addition_async(obj, value1, value2);
}

int32_t CalculatorProxy::subtraction(/*in*/ int32_t value1, /*in*/ int32_t value2)
{
    int32_t return_ =
    dynamic_cast<eprosima::rpc::protocol::CalculatorProtocol&>(getProtocol()).Calculator_subtraction(value1, value2);
    return return_;
}

void CalculatorProxy::subtraction_async(Calculator_subtractionCallbackHandler &obj, /*in*/ int32_t value1, /*in*/ int32_t value2)
{
    dynamic_cast<eprosima::rpc::protocol::CalculatorProtocol&>(getProtocol()).Calculator_subtraction_async(obj, value1, value2);
}




