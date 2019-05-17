#ifndef CPINFO_H_INCLUDED
#define CPINFO_H_INCLUDED

#include <cstdint>
#include <fstream>
#include <iostream>
#include "ByteReader.hpp"

#define CONSTANT_Class 7
#define CONSTANT_Fieldref 9
#define CONSTANT_Methodref 10
#define CONSTANT_InterfaceMethodref 11
#define CONSTANT_String 8
#define CONSTANT_Integer 3
#define CONSTANT_Float 4
#define CONSTANT_Long 5
#define CONSTANT_Double 6
#define CONSTANT_NameAndType 12
#define CONSTANT_Utf8 1
#define CONSTANT_MethodHandle 15
#define CONSTANT_MethodType 16
#define CONSTANT_InvokeDynamic 18
#define CONSTANT_Empty 0

typedef struct {
    uint16_t name_index;
} ConstantClassInfo;

typedef struct {
    uint16_t class_index;
    uint16_t name_and_type_index;
} ConstantFieldrefInfo;

typedef struct {
    uint16_t class_index;
    uint16_t name_and_type_index;
} ConstantMethodrefInfo;

typedef struct {
    uint16_t class_index;
    uint16_t name_and_type_index;
} ConstantInterfaceMethodrefInfo;

typedef struct {
    uint16_t string_index;
} ConstantStringInfo;

typedef struct {
    uint32_t bytes;
} ConstantIntegerInfo;

typedef struct {
    uint32_t bytes;
} ConstantFloatInfo;

typedef struct {
    uint32_t high_bytes;
    uint32_t low_bytes;
} ConstantLongInfo;

typedef struct {
    uint32_t high_bytes;
    uint32_t low_bytes;
} ConstantDoubleInfo;

typedef struct {
    uint16_t name_index;
    uint16_t descriptor_index;
} ConstantNameAndTypeInfo;

typedef struct {
    uint16_t length;
    uint8_t *bytes;
} ConstantUTF8Info;

typedef struct {
    uint8_t reference_kind;
    uint16_t reference_index;
} ConstantMethodHandleInfo;

typedef struct {
    uint16_t descriptor_index;
} ConstantMethodTypeInfo;

typedef struct {
    uint16_t bootstrap_method_attr_index;
    uint16_t name_and_type_index;
} ConstantInvokeDynamicInfo;

class CPInfo {
public:
    uint8_t tag;
    union {
        ConstantClassInfo CONSTANT_Class_info;
        ConstantFieldrefInfo CONSTANT_Fieldref_info;
        ConstantMethodrefInfo CONSTANT_Methodref_info;
        ConstantInterfaceMethodrefInfo CONSTANT_InterfaceMethodref_info;
        ConstantStringInfo CONSTANT_String_info;
        ConstantIntegerInfo CONSTANT_Integer_info;
        ConstantFloatInfo CONSTANT_Float_info;
        ConstantLongInfo CONSTANT_Long_info;
        ConstantDoubleInfo CONSTANT_Double_info;
        ConstantNameAndTypeInfo CONSTANT_NameAndType_info;
        ConstantUTF8Info CONSTANT_Utf8_info;
        ConstantMethodHandleInfo CONSTANT_MethodHandle_info;
        ConstantMethodTypeInfo CONSTANT_MethodType_info;
        ConstantInvokeDynamicInfo CONSTANT_InvokeDynamic_info;
    };
public:
    CPInfo();
    ~CPInfo();
    void read(FILE *fp);
    void setTag(uint8_t tag);

    uint8_t getTag() {
        return this->tag;
    }

    ConstantClassInfo getClassInfo() {
        return this->CONSTANT_Class_info;
    }

    ConstantFieldrefInfo getFieldrefInfo() {
        return this->CONSTANT_Fieldref_info;
    }
    
    ConstantMethodrefInfo getMethodrefInfo() {
        return this->CONSTANT_Methodref_info;
    }

    ConstantInterfaceMethodrefInfo getInterfaceMethodrefInfo() {
        return this->CONSTANT_InterfaceMethodref_info;
    }

    ConstantStringInfo getStringInfo() {
        return this->CONSTANT_String_info;
    }

    ConstantIntegerInfo getIntegerInfo() {
        return this->CONSTANT_Integer_info;
    }

    ConstantFloatInfo getFloatInfo() {
        return this->CONSTANT_Float_info;
    }

    ConstantLongInfo getLongInfo() {
        return this->CONSTANT_Long_info;
    }

    ConstantDoubleInfo getDoubleInfo() {
        return this->CONSTANT_Double_info;
    }

    ConstantNameAndTypeInfo getNameAndTypeInfo() {
        return this->CONSTANT_NameAndType_info;
    }

    ConstantUTF8Info getUTF8Info() {
        return this->CONSTANT_Utf8_info;
    }

    ConstantMethodHandleInfo getMethodHandleInfo() {
        return this->CONSTANT_MethodHandle_info;
    }

    ConstantMethodTypeInfo getMethodTypeInfo() {
        return this->CONSTANT_MethodType_info;
    }

    ConstantInvokeDynamicInfo getInvokeDynamicInfo() {
        return this->CONSTANT_InvokeDynamic_info;
    }
};

#endif