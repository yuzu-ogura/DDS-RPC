#ifndef _CalculatorSERVER_H_
#define _CalculatorSERVER_H_

#include <server/Server.h>
#include "CalculatorServerImpl.h"

namespace eprosima
{
    namespace rpc
    {
        namespace protocol
        {
            class CalculatorProtocol;
        }
    }
}

/*
 * @brief This class implements a specific server for the defined interface Calculator by user.
 * 
 */
class CalculatorServer : public eprosima::rpc::server::Server
{
    public:

        /*
         * @brief This constructor sets the transport that will be used by the server.
         *
         * @param strategy Strategy used by server to work with new requests.
         *        This class doesn't delete this object in its destructor. Cannot be NULL.
         * @param transport The network transport that the server has to use.
         *        This transport's object is not deleted by this class in its destructor. Cannot be NULL.
         * @param protocol Generated protocol that the server has to use.
         *        This class has the information to process requests and build responses for this application environment. 
         * @param servant Servant that the server will use to invoke user's functions.
         * 
         */
        CalculatorServer(eprosima::rpc::strategy::ServerStrategy &strategy, eprosima::rpc::transport::ServerTransport &transport,
            eprosima::rpc::protocol::CalculatorProtocol &protocol, CalculatorServerImpl &servant);

        /// @brief Destructor.
        virtual ~CalculatorServer();

     private:
        
        /// @brief Pointer to the server's servant implemented by the user.
        CalculatorServerImpl &_impl;
};


#endif // _CalculatorSERVER_H_