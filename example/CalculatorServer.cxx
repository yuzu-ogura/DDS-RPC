#include "CalculatorServer.h"
#include <strategies/ServerStrategy.h>
#include <transports/ServerTransport.h>
#include "CalculatorProtocol.h"
#include <exceptions/ServerInternalException.h>

CalculatorServer::CalculatorServer(eprosima::rpc::strategy::ServerStrategy &strategy, eprosima::rpc::transport::ServerTransport &transport,
            eprosima::rpc::protocol::CalculatorProtocol &protocol, CalculatorServerImpl &servant) :
    Server(strategy, transport, protocol), _impl(servant)
{
   protocol.activateInterface("Calculator");
   protocol.linkCalculatorImpl(servant);
}

CalculatorServer::~CalculatorServer()
{
    //TODO Unlink an deactivate.
}



