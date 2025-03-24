#ifndef _TRANSPORTS_COMPONENTS_ENDPOINT_H_
#define _TRANSPORTS_COMPONENTS_ENDPOINT_H_

namespace eprosima
{
    namespace rpc
    {
        namespace transport
        {
			/**
             * @brief This class represents an communication endpoint.
             * 
             */
            class Endpoint
            {
                protected:

					/// @brief Default constructor.
                    Endpoint() = default;

					/// @brief Default destructor.
                    virtual ~Endpoint() = default;
            };
        } // namespace eprosima
    } // namespace eprosima
} // namespace eprosima
#endif // _TRANSPORTS_COMPONENTS_ENDPOINT_H_
