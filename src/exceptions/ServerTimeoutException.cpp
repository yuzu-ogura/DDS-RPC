#include <exceptions/ServerTimeoutException.h>

using namespace eprosima::rpc::exception;

ServerTimeoutException::ServerTimeoutException(const ServerTimeoutException &ex) : SystemException(ex)
{
}

ServerTimeoutException::ServerTimeoutException(ServerTimeoutException&& ex) : SystemException(std::move(ex))
{
}

ServerTimeoutException& ServerTimeoutException::operator=(const ServerTimeoutException &ex)
{
    if(this != &ex)
    {
        SystemException::operator=(ex);
    }

    return *this;
}

ServerTimeoutException& ServerTimeoutException::operator=(ServerTimeoutException&& ex)
{
    if(this != &ex)
    {
        SystemException::operator=(std::move(ex));
    }

    return *this;
}

void ServerTimeoutException::raise() const
{
    throw *this;
}
