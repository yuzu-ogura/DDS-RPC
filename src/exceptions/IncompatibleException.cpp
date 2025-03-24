

#include <exceptions/IncompatibleException.h>

using namespace eprosima::rpc::exception;

IncompatibleException::IncompatibleException(const IncompatibleException &ex) : SystemException(ex)
{
}

IncompatibleException::IncompatibleException(IncompatibleException&& ex) : SystemException(std::move(ex))
{
}

IncompatibleException& IncompatibleException::operator=(const IncompatibleException &ex)
{
    if(this != &ex)
    {
        SystemException::operator=(ex);
    }

    return *this;
}

IncompatibleException& IncompatibleException::operator=(IncompatibleException&& ex)
{
    if(this != &ex)
    {
        SystemException::operator=(std::move(ex));
    }

    return *this;
}

void IncompatibleException::raise() const
{
    throw *this;
}
