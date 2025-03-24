#include <exceptions/ServerNotFoundException.h>

using namespace eprosima::rpc::exception;

ServerNotFoundException::ServerNotFoundException(const ServerNotFoundException &ex) : SystemException(ex)
{
}

ServerNotFoundException::ServerNotFoundException(ServerNotFoundException&& ex) : SystemException(std::move(ex))
{
}

ServerNotFoundException& ServerNotFoundException::operator=(const ServerNotFoundException &ex)
{
    if(this != &ex)
    {
        SystemException::operator=(ex);
    }

    return *this;
}

ServerNotFoundException& ServerNotFoundException::operator=(ServerNotFoundException&& ex)
{
    if(this != &ex)
    {
        SystemException::operator=(std::move(ex));
    }

    return *this;
}

void ServerNotFoundException::raise() const
{
    throw *this;
}
