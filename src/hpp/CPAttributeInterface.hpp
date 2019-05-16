#ifndef _CONSTANTPOOLATTRIBUTE_H_
#define _CONSTANTPOOLATTRIBUTE_H_

#include <string>
#include <vector>
#include <iostream>
#include "CPInfo.hpp"

using namespace std;

/**
* @class CpAttributeInterface
* @brief Declarações da interface entre ConstantPool e AttributeInfo para traduzir as strings UTF8
*/

class CPAttributeInterface {
public:
    string getUTF8(vector<CPInfo*>, uint16_t);
};

#endif // _CONSTANTPOOLATTRIBUTE_H_