#ifndef FIELDINFO_H_INCLUDED
#define FIELDINFO_H_INCLUDED

#include <cstdint>
#include <vector>
#include "AttributeInfo.hpp"
#include "Frame.hpp"


using namespace std;

class FieldInfo {
private:
    uint16_t accessFlags;
    uint16_t nameIndex;
    uint16_t descriptorIndex;
    uint16_t attributesCount;
    vector<AttributeInfo*> attributes;
public:
    JavaType staticValue;
    static const uint16_t ACC_PUBLIC = 0x0001;
    static const uint16_t ACC_PRIVATE = 0x0002;
    static const uint16_t ACC_PROTECTED = 0x0004;
    static const uint16_t ACC_STATIC = 0x0008;
    static const uint16_t ACC_FINAL = 0x0010;
    static const uint16_t ACC_VOLATILE = 0x0040;
    static const uint16_t ACC_TRANSIENT = 0x0080;
    static const uint16_t ACC_SYNTHETIC = 0x1000;
    static const uint16_t ACC_ENUM = 0x4000;
    ~FieldInfo();
    void read(FILE *fp, vector<CPInfo*> constantPool);

    uint16_t getAccessFlags(){
        return accessFlags;
    }
    uint16_t getNameIndex(){
        return nameIndex;
    }
    uint16_t getDescriptorIndex(){
        return descriptorIndex;
    }
    uint16_t getAttributesCount(){
        return attributesCount;
    }
};

#endif