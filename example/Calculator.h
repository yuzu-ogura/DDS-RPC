#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <cstdint>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <bitset>

/**
 * @brief This class represents the interface Calculator defined by the user in the IDL file.
 * 
 */
class Calculator 
{
    public:

    virtual int32_t addition(/*in*/ int32_t value1, /*in*/ int32_t value2) = 0;

    virtual int32_t subtraction(/*in*/ int32_t value1, /*in*/ int32_t value2) = 0;

};

#endif // _CALCULATOR_H_