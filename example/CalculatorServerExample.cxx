#include "CalculatorServer.h"
#include <strategies/ThreadPoolStrategy.h>
#include "CalculatorDDSProtocol.h"
#include <transports/dds/RTPSServerTransport.h>
#include <exceptions/Exceptions.h>
#include "CalculatorServerImplExample.h"

#include <iostream>

using namespace eprosima::rpc;
using namespace ::exception;
using namespace ::strategy;
using namespace ::transport::dds;
using namespace ::protocol::dds;

int main(void)
{
    unsigned int threadPoolSize = 5;
    ThreadPoolStrategy *pool = NULL;
    CalculatorProtocol *protocol = NULL;
    RTPSServerTransport *transport = NULL;
    CalculatorServer *server = NULL;
    CalculatorServerImplExample servant;
    
    // Create and initialize the server for interface "Calculator".
    try
    {
        pool = new ThreadPoolStrategy(threadPoolSize);
        protocol = new CalculatorProtocol();
        transport = new RTPSServerTransport("CalculatorService", "Instance");
        server = new CalculatorServer(*pool, *transport, *protocol, servant);
        server->serve();
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    while(1)
    {
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    
    // Stop and delete the server.
    server->stop();
    delete server;
    delete protocol;
    delete transport;
    delete pool;
    
    return 0;
}


