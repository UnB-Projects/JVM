#ifndef ATTRIBUTE_INFO_H_INCLUDED
#define ATTRIBUTE_INFO_H_INCLUDED

#include <cstdint>
#include <vector>
#include <fstream>
#include <iostream>
#include "ByteReader.hpp"
#include "CPInfo.hpp"
#include "CPAttributeInterface.hpp"

using namespace std;

class AttributeInfo;
class ConstantValueAttribute;
class CodeAttribute;


class ConstantValueAttribute {
private:
    uint16_t constantValueIndex;
public:
    void read(FILE*);
    void print(vector<CPInfo*>);
};


class ExceptionHandler {
private:
    uint16_t startPC;
    uint16_t endPC;
    uint16_t handlerPC;
    uint16_t catchType;
public:
    void read(FILE * fp);
};

class CodeAttribute {
private:
    uint16_t maxStack;
    uint16_t maxLocals;
    uint32_t codeLength;
    // vector<uint8_t> code;
    uint8_t *code;
    uint16_t exceptionTableLength;
    // vector<ExceptionHandler>exceptionTable;
    ExceptionHandler* exceptionTable;
    uint16_t attributesCount;
    // vector<AttributeInfo> attributes;
    AttributeInfo *attributes;
public:
    CodeAttribute();
    ~CodeAttribute();
    void read(FILE*, vector<CPInfo*>);
    void print(vector<CPInfo*>);
};

class ExceptionsAttribute {
private:
    uint16_t numberOfExceptions;
    // vector<uint16_t> exceptionIndexTable;
    uint16_t *execeptionIndexTable;
public:
    void read(FILE *);
    void print(vector<CPInfo*>);
};

class ClassInfo {
private:
    uint16_t innerClassInfoIndex;
    uint16_t outerClassInfoIndex;
    uint16_t innerNameIndex;
    uint16_t innerClassAccessFlags;
public:
    void read(FILE * fp);
};

class InnerClassesAttribute {
private:
    uint16_t numberOfClasses;
    // vector<ClassInfo> classes;
    ClassInfo *classes;
public:
    void read(FILE*);
    void print(vector<CPInfo*>);
};

class SourceFileAttribute {
private:
    uint16_t sourcefileIndex;
public:
    void read(FILE*);
    void print(vector<CPInfo*>);
};

class LineNumber {
private:
    uint16_t startPC;
    uint16_t lineNumber;
public:
    void read(FILE *fp);
};

class LineNumberTableAttribute {
private:
    uint16_t lineNumberTableLength;
    // vector<LineNumber> lineNumberTable;
    LineNumber* lineNumberTable;
public:
    void read(FILE*);
    void print();
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
        uint8_t *info;
    };
public:
    AttributeInfo();
    ~AttributeInfo();
    void read(FILE*, vector<CPInfo*>);
    void print(vector<CPInfo*>);

    uint16_t getAttributeNameIndex() {
        return attributeNameIndex;
    }

    uint16_t getAttributeLength() {
        return attributeLength;
    }
};

#endif