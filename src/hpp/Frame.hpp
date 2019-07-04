#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include <cstdint>
#include <vector>
#include <stack>
#include "CPInfo.hpp"
#include "MethodInfo.hpp"

const uint8_t CAT_NULL = 0;
const uint8_t CAT1 = 1;
const uint8_t CAT2 = 2;
struct JavaType {
    uint8_t tag;
    union {
        uint32_t type_empty;
        uint32_t type_boolean;
        uint32_t type_byte;
        uint32_t type_char;
        uint32_t type_short;
        uint32_t type_int;
        uint32_t type_float;
        uint64_t type_reference;
        uint32_t type_returnAddress;
        uint64_t type_long;
        uint64_t type_double;
    };
};

class Frame {
private:
    MethodInfo* method;
    CodeAttribute codeAttribute;
public:
    vector<CPInfo*> constantPool;
    stack<JavaType> operandStack;
    vector<JavaType> localVariables;
    stack<Frame>* jvmStack;
    uint32_t localPC;
    // Frame(vector<JavaType>, stack<JavaType>, vector<CPInfo*>);
    Frame(vector<CPInfo*>, MethodInfo*, stack<Frame>*);
    uint8_t* getCode() {
        return this->codeAttribute.getCode();
    }
    uint32_t getCodeLength() {
        return this->codeAttribute.getCodeLength();
    }
};

#endif