#ifndef ATTRIBUTE_INFO_H_INCLUDED
#define ATTRIBUTE_INFO_H_INCLUDED

#include <cstdint>
#include <vector>

using namespace std;

class ConstantValueAttribute {
private:
    /*
    The value of the constantvalue_index item must be a valid index into
    the constant_pool table. The constant_pool entry at that index gives the
    constant value represented by this attribute. The constant_pool entry must be
    of a type appropriate to the field, as specified in Table 4.7.2-A.
    */
    uint16_t constantValueIndex;
};

class CodeAttribute {
private:
    /*
    The value of the max_stack item gives the maximum depth of the operand
    stack of this method (§2.6.2) at any point during execution of the method.
    */
    uint16_t max_stack;

    /*
    The value of the max_locals item gives the number of local variables in
    the local variable array allocated upon invocation of this method (§2.6.1),
    including the local variables used to pass parameters to the method on its
    invocation.
    The greatest local variable index for a value of type long or double is
    max_locals - 2 . The greatest local variable index for a value of any other
    type is max_locals - 1 .
    */
    uint16_t max_locals;

    /*
    The value of the code_length item gives the number of bytes in the code array
    for this method.
    The value of code_length must be greater than zero (as the code array must
    not be empty) and less than 65536.
    */
    uint32_t code_length;

    /*
    The code array gives the actual bytes of Java Virtual Machine code that
    implement the method.
    When the code array is read into memory on a byte-addressable machine, if
    the first byte of the array is aligned on a 4-byte boundary, the tableswitch and
    lookupswitch 32-bit offsets will be 4-byte aligned. (Refer to the descriptions
    of those instructions for more information on the consequences of code array
    alignment.)
    The detailed constraints on the contents of the code array are extensive and are
    given in a separate section (§4.9).
    */
    uint8_t *code;
    uint16_t exception_table_length;
    {
    uint16_t start_pc;
    uint16_t end_pc;
    uint16_t handler_pc;
    uint16_t catch_type;
    } exception_table[exception_table_length];
    uint16_t attributes_count;
    vector<AttributeInfo> attributes;
};


class AttributeInfo {
private:
    /*
    attribute_name_index must be a valid unsigned 16-
    bit index into the constant pool of the class.
    The constant_pool entry
    at attribute_name_index must be a CONSTANT_Utf8_info structure (§4.4.7)
    representing the name of the attribute.
    */
    uint16_t attribute_name_index;

    /*
    The value of the attribute_length item
    indicates the length of the subsequent information in bytes. The length does
    not include the initial six bytes that contain the attribute_name_index and
    attribute_length items.
    */
    uint32_t attribute_length;
    // vector<uint8_t> info;
};

#endif