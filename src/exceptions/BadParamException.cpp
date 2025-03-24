#include <exceptions/BadParamException.h>

using namespace eprosima::rpc::exception;

BadParamException::BadParamException(const BadParamException &ex) : SystemException(ex)
{
}

BadParamException::BadParamException(BadParamException&& ex) : SystemException(std::move(ex))
{
}

BadParamException& BadParamException::operator=(const BadParamException &ex)
{
    if(this != &ex)
    {
        SystemException::operator=(ex);
    }

    return *this;
}

BadParamException& BadParamException::operator=(BadParamException&& ex)
{
    if(this != &ex)
    {
        SystemException::operator=(std::move(ex));
    }

    return *this;
}

void BadParamException::raise() const
{
    throw *this;
}

