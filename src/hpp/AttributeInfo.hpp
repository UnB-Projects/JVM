#ifndef ATTRIBUTE_INFO_H_INCLUDED
#define ATTRIBUTE_INFO_H_INCLUDED

#include <cstdint>
#include <vector>

using namespace std;

class ConstantValue {
private:
    uint16_t constantValueIndex;
};

// class Code {
// private:
//     uint16_t max_stack;
//     uint16_t max_locals;
//     uint32_t code_length;
//     uint8_t *code;
//     uint16_t exception_table_length;
//     union {
//     uint16_t start_pc;
//     uint16_t end_pc;
//     uint16_t handler_pc;
//     uint16_t catch_type;
//     } exception_table[exception_table_length];
//     uint16_t attributes_count;
//     vector<AttributeInfo> attributes;
// };


class AttributeInfo {
private:
    uint16_t attributeNameIndex;
    uint32_t attributeLength;
    union {
        ConstantValue constantValue;
        Code code;
        // StackMapTable stackMapTable;
        Exceptions exceptions;
        InnerClasses innerClasses;
        // EnclosingMethod enclosingMethod;
        // Synthetic synthetic;
        // Signature signature;
        SourceFile sourceFile;
        // SourceDebugExtension sourceDebugExtension;
        LineNumberTable lineNumberTable;
        // LocalVariableTable localVariableTable;
        // LocalVariableTypeTable localVariableTypeTable;
        // Deprecated deprecated;
        // RuntimeVisibleAnnotations runtimeVisibleAnnotations;
        // RuntimeInvisibleAnnotations runtimeInvisibleAnnotations;
        // RuntimeVisibleParameterAnnotations runtimeVisibleParameterAnnotations;
        // RuntimeInvisibleParameterAnnotations runtimeInvisibleParameterAnnotations;
        // RuntimeVisibleTypeAnnotations runtimeVisibleTypeAnnotations;
        // RuntimeInvisibleTypeAnnotations runtimeInvisibleTypeAnnotations;
        // AnnotationDefault annotationDefault;
        // BootstrapMethods bootstrapMethods;
        // MethodParameters methodParameters;
    }
};

#endif