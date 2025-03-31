#include <server/Server.h>
#include <exceptions/InitializeException.h>
#include <strategies/ServerStrategy.h>
#include <transports/ServerTransport.h>
#include <protocols/Protocol.h>

static const char* const CLASS_NAME ="eprosima::rpc::server::Server";

using namespace eprosima::rpc;
using namespace ::server;
using namespace ::strategy;
using namespace ::transport;
using namespace ::protocol;
using namespace ::exception;

Server::Server(ServerStrategy &strategy, ServerTransport &transport, Protocol &protocol) :
    m_strategy(strategy), m_transport(transport), m_protocol(protocol)
{
    const char* const METHOD_NAME ="Server";
    std::string errorMessage;

    protocol.setTransport(transport);
    transport.setStrategy(strategy);
    transport.linkProtocol(protocol);
}

void Server::serve()
{
    const char* const METHOD_NAME = "server";
    m_transport.run();
    printf("INFO<%s::%s>: Server is running\n", CLASS_NAME, METHOD_NAME);	
}

void Server::stop()
{
    const char* const METHOD_NAME = "stop";
    m_transport.stop();
    printf("INFO<%s::%s>: Server is stopped\n", CLASS_NAME, METHOD_NAME);
}
