#ifndef _CONSTANTPOOL_ATTRIBUTEINTERFACE_H_
#define _CONSTANTPOOL_ATTRIBUTEINTERFACE_H_

#include <string>
#include <vector>
#include <iostream>
#include "CPInfo.hpp"

using namespace std;

class CPAttributeInterface {
public:
    string getUTF8(vector<CPInfo*>, uint16_t);
};

#endif