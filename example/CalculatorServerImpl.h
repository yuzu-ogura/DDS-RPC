#ifndef _CalculatorSERVER_IMPL_H_
#define _CalculatorSERVER_IMPL_H_

#include <utils/Messages.h>
#include "Calculator.h"

/*
 * @brief This class is the skeleton of the servant and its remote procedures has to be implemented.
 * 
 */
class CalculatorServerImpl : public Calculator
{
    public:

        /// @brief The default constructor.
        CalculatorServerImpl() = default;

        /// @brief Destructor.
        virtual ~CalculatorServerImpl() = default;

};


#endif // _CalculatorSERVER_IMPL_H_