#ifndef _CalculatorSERVER_IMPL_EXAMPLE_H_
#define _CalculatorSERVER_IMPL_EXAMPLE_H_

#include "CalculatorServerImpl.h"

/*
 * @brief This class is an example of a servant and it implements the remote procedures of the servant.
 * 
 */
class CalculatorServerImplExample : public CalculatorServerImpl
{
    public:

        /// @brief The default constructor.
        CalculatorServerImplExample() = default;

        /// @brief Destructor.
        virtual ~CalculatorServerImplExample() = default;
 
        /// @brief Implementation of the remote procedure addition
        int32_t addition(/*in*/ int32_t value1, /*in*/ int32_t value2);
        
        /// @brief Implementation of the remote procedure subtraction
        int32_t subtraction(/*in*/ int32_t value1, /*in*/ int32_t value2);
                
};


#endif // _CalculatorSERVER_IMPL_EXAMPLE_H_
