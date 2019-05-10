#ifndef CPINFO_H_INCLUDED
#define CPINFO_H_INCLUDED

#include <cstdint>

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

class CPInfo {
public:
    uint8_t tag;
    union {
        struct {
            /*
            The value of the name_index item must be a valid index into the
            constant_pool table. The constant_pool entry at that index must be a
            CONSTANT_Utf8_info structure (§4.4.7) representing a valid binary class or
            interface name encoded in internal form (§4.2.1).
            */
            uint16_t name_index;
        } CONSTANT_Class_info;

        /*
        The value of the class_index item must be a valid index into the
        constant_pool table. The constant_pool entry at that index must be a
        CONSTANT_Class_info structure (§4.4.1) representing a class or interface type
        that has the field or method as a member.

        The value of the name_and_type_index item must be a valid index into
        the constant_pool table. The constant_pool entry at that index must be a
        CONSTANT_NameAndType_info structure (§4.4.6). This constant_pool entry
        indicates the name and descriptor of the field or method.
        */
        struct {
            /*
            The class_index item of a CONSTANT_Fieldref_info structure may be either
            a class type or an interface type.
            */
            uint16_t class_index;
            uint16_t name_and_type_index;
        } CONSTANT_Fieldref_info;

        struct {
            /*
            The class_index item of a CONSTANT_Methodref_info structure must be a
            class type, not an interface type.
            */
            uint16_t class_index;
            uint16_t name_and_type_index;
        } CONSTANT_Methodref_info;

        struct {
            /*
            The class_index item of a CONSTANT_InterfaceMethodref_info structure
            must be an interface type.
            */   
            uint16_t class_index;
            uint16_t name_and_type_index;
        } CONSTANT_InterfaceMethodref_info;

        struct {
            /*
            The value of the string_index item must be a valid index into the
            constant_pool table. The constant_pool entry at that index must be a
            CONSTANT_Utf8_info structure (§4.4.7) representing the sequence of Unicode
            code points to which the String object is to be initialized.
            */
            uint16_t string_index;
        } CONSTANT_String_info;

        struct {
            /*
            The bytes item of the CONSTANT_Integer_info structure represents the value
            of the int constant. The bytes of the value are stored in big-endian (high byte
            first) order.
            */
            uint32_t bytes;
        } CONSTANT_Integer_info;

        struct {
            /*
            The bytes item of the CONSTANT_Float_info structure represents the value
            of the float constant in IEEE 754 floating-point single format (§2.3.2). The
            bytes of the single format representation are stored in big-endian (high byte
            first) order.

            Nao esquecer de olhar os valores de +inf -inf e NaN depois!!
            */
            uint32_t bytes;
        } CONSTANT_Float_info;


        /*
        All 8-byte constants take up two entries in the constant_pool table of the class
        file. If a CONSTANT_Long_info or CONSTANT_Double_info structure is the item
        in the constant_pool table at index n, then the next usable item in the pool is
        located at index n+2. The constant_pool index n+1 must be valid but is considered
        unusable.

        Nao esquecer de olhar os valores de +inf -inf e NaN depois!!
        */
        struct {
            uint32_t high_bytes;
            uint32_t low_bytes;
        } CONSTANT_Long_info;

        struct {
            uint32_t high_bytes;
            uint32_t low_bytes;
        } CONSTANT_Double_info;

        struct {
            /*
            The value of the name_index item must be a valid index into the
            constant_pool table. The constant_pool entry at that index must be a
            CONSTANT_Utf8_info structure (§4.4.7) representing either the special method
            name <init> (§2.9) or a valid unqualified name denoting a field or method
            (§4.2.2).
            */
            uint16_t name_index;
            /*
            The value of the descriptor_index item must be a valid index into the
            constant_pool table. The constant_pool entry at that index must be a
            CONSTANT_Utf8_info structure (§4.4.7) representing a valid field descriptor
            or method descriptor (§4.3.2, §4.3.3).
            */
            uint16_t descriptor_index;
        } CONSTANT_NameAndType_info;

        struct {
            /*
            The value of the length item gives the number of bytes in the bytes array (not
            the length of the resulting string).
            */
            uint16_t length;
            /*
            The bytes array contains the bytes of the string.
            No byte may have the value (byte)0 .
            No byte may lie in the range (byte)0xf0 to (byte)0xff .

            verificar depois se nao eh melhor declarar bytes apenas como ponteiro
            */
            uint8_t bytes[];
        } CONSTANT_Utf8_info;

        struct {
            /*
            The value of the reference_kind item must be in the range 1 to 9. The
            value denotes the kind of this method handle, which characterizes its bytecode
            behavior (§5.4.3.5).
            */
            uint8_t reference_kind;
            /*
            Olhar documentacao, muito grande
            */
            uint16_t reference_index;
        } CONSTANT_MethodHandle_info;

        struct {
            uint16_t descriptor_index;
        } CONSTANT_MethodType_info;

        struct {
            /*
            The value of the bootstrap_method_attr_index item must be a valid index
            into the bootstrap_methods array of the bootstrap method table (§4.7.23) of
            this class file.
            */
            uint16_t bootstrap_method_attr_index;
            /*
            The value of the name_and_type_index item must be a valid index into
            the constant_pool table. The constant_pool entry at that index must be a
            CONSTANT_NameAndType_info structure (§4.4.6) representing a method name
            and method descriptor (§4.3.3).
            */
            uint16_t name_and_type_index;
        } CONSTANT_InvokeDynamic_info;
    };
};

#endif