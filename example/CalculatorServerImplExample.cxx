#include "CalculatorServerImplExample.h"

int32_t CalculatorServerImplExample::addition(/*in*/ int32_t value1, /*in*/ int32_t value2)
{
    int32_t  addition_ret = value1 + value2;

    return addition_ret;
}

int32_t CalculatorServerImplExample::subtraction(/*in*/ int32_t value1, /*in*/ int32_t value2)
{
    int32_t  subtraction_ret = value1 - value2;

    return subtraction_ret;
}



