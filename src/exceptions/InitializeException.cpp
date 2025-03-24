#include <exceptions/InitializeException.h>

using namespace eprosima::rpc::exception;

InitializeException::InitializeException(const InitializeException &ex) : SystemException(ex)
{
}

InitializeException::InitializeException(InitializeException&& ex) : SystemException(std::move(ex))
{
}

InitializeException& InitializeException::operator=(const InitializeException &ex)
{
    if(this != &ex)
    {
        SystemException::operator=(ex);
    }

    return *this;
}

InitializeException& InitializeException::operator=(InitializeException&& ex)
{
    if(this != &ex)
    {
        SystemException::operator=(std::move(ex));
    }

    return *this;
}

void InitializeException::raise() const
{
    throw *this;
}
