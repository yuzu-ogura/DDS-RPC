#include <client/Proxy.h>
#include <exceptions/InitializeException.h>
#include <transports/ProxyTransport.h>
#include <protocols/Protocol.h>

static const char* const CLASS_NAME ="eprosima::rpc::proxy::Proxy";

using namespace eprosima::rpc;
using namespace ::proxy;
using namespace ::transport;
using namespace ::protocol;
using namespace ::exception;

Proxy::Proxy(ProxyTransport &transport, Protocol &protocol) : m_transport(transport), m_protocol(protocol)
{
    protocol.setTransport(transport);
}
