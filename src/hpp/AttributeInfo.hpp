#ifndef ATTRIBUTE_INFO_H_INCLUDED
#define ATTRIBUTE_INFO_H_INCLUDED

#include <cstdint>
#include <vector>

using namespace std;

class ConstantValueAttribute {
private:
    uint16_t constantValueIndex;
public:
    void read(FILE*);
    void print(vector<CPInfo>);
};

class CodeAttribute {
private:
    class ExceptionHandler {
    private:
        uint16_t start_pc;
        uint16_t end_pc;
        uint16_t handler_pc;
        uint16_t catch_type;
    };

    uint16_t maxStack;
    uint16_t maxLocals;
    uint32_t codeLength;
    vector<uint8_t> code;
    uint16_t exceptionTableLength;
    vector<ExceptionHandler>exceptionTable;
    uint16_t attributesCount;
    vector<AttributeInfo> attributes;
public:
    void read(FILE*, vector<CPInfo>);
    void print(vector<CPInfo>);
};

class ExceptionsAttribute {
private:
    uint16_t numberOfExceptions;
    vector<uint16_t> exceptionIndexTable;
public:
    void read(FILE *);
    void print(std::vector<CPInfo>);
};

class InnerClassesAttribute {
private:
    class ClassInfo {
    private:
        uint16_t innerClassInfoIndex;
        uint16_t outerClassInfoIndex;
        uint16_t innerNameIndex;
        uint16_t innerClassAccessFlags;
    };

    uint16_t numberOfClasses;
    vector<ClassInfo> classes;
public:
    void read(FILE*);
    void print(vector<CPInfo>);
};

class SourceFileAttribute {
private:
    uint16_t sourcefileIndex;
public:
    void read(FILE*);
    void print(vector<CPInfo>);
};

class LineNumberTableAttribute {
private:
    class LineNumber {
        uint16_t startPC;
        uint16_t lineNumber;
    };

    uint16_t lineNumberTableLength;
    vector<LineNumber> lineNumberTable;
public:
    void read(FILE*);
    void print(vector<CPInfo>);
};

class AttributeInfo {
private:
    uint16_t attributeNameIndex;
    uint32_t attributeLength;
    union {
        ConstantValueAttribute constantValue;
        CodeAttribute code;
        // StackMapTable stackMapTable;
        ExceptionsAttribute exceptions;
        InnerClassesAttribute innerClasses;
        // EnclosingMethod enclosingMethod;
        // Synthetic synthetic;
        // Signature signature;
        SourceFileAttribute sourceFile;
        // SourceDebugExtension sourceDebugExtension;
        LineNumberTableAttribute lineNumberTable;
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
    };
public:
    ~AttributeInfo();
};

#endif