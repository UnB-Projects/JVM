#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include <cstdint>
#include <vector>
#include <stack>
#include "CPInfo.hpp"

class JavaType {
    union {
        uint32_t type_empty;
        uint32_t type_boolean;
        uint32_t type_byte;
        uint32_t type_char;
        uint32_t type_short;
        uint32_t type_int;
        uint32_t type_float;
        uint32_t type_reference;
        uint32_t type_returnAddress;
        uint64_t type_long;
        uint64_t type_double;
    };
};

class Frame {
private:
    vector<JavaType*> localVariables;
    stack<JavaType*> operandStack;
    vector<CPInfo*> constantPool;
public:
};

#endif