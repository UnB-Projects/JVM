#include "../hpp/AttributeInfo.hpp"

void ConstantValueAttribute::read(FILE *fp) {
    ByteReader<uint16_t> twoByteReader;
    constantValueIndex = twoByteReader.byteCatch(fp);
}

void LineNumber::read(FILE * fp) {
    ByteReader<uint16_t> twoByteReader;
    startPC = twoByteReader.byteCatch(fp);
    lineNumber = twoByteReader.byteCatch(fp);
}

void LineNumberTableAttribute::read(FILE *fp) {
    ByteReader<uint16_t> twoByteReader;
    lineNumberTableLength = twoByteReader.byteCatch(fp);
    lineNumberTable = (LineNumber*)calloc(lineNumberTableLength, sizeof(LineNumber));

    for (int i = 0; i < lineNumberTableLength; i++) {
        lineNumberTable[i].read(fp);
    }
}

void ExceptionHandler::read(FILE *fp) {
    ByteReader<uint8_t> oneByteReader;


    startPC = oneByteReader.byteCatch(fp);
    endPC = oneByteReader.byteCatch(fp);
    handlerPC = oneByteReader.byteCatch(fp);
    catchType = oneByteReader.byteCatch(fp);
}

void CodeAttribute::read(FILE *fp, vector<CPInfo*> constantPool) {
    ByteReader<uint8_t> oneByteReader;
    ByteReader<uint16_t> twoByteReader;
    ByteReader<uint32_t> fourByteReader;

    maxStack = twoByteReader.byteCatch(fp);
    maxLocals = twoByteReader.byteCatch(fp);
    codeLength = fourByteReader.byteCatch(fp);

    code = (uint8_t *)calloc(codeLength, sizeof(uint8_t));
    for (int i = 0; i < codeLength; i++){
        code[i] = oneByteReader.byteCatch(fp);
    }

    exceptionTableLength = twoByteReader.byteCatch(fp);

    exceptionTable = (ExceptionHandler*)calloc(exceptionTableLength, sizeof(ExceptionHandler));
    for (int i = 0; i < exceptionTableLength; i++){
        exceptionTable[i].read(fp);
    }

    attributesCount = twoByteReader.byteCatch(fp);
    attributes = (AttributeInfo *)calloc(attributesCount, sizeof(AttributeInfo));
    for (int i = 0; i < attributesCount; i++){
        attributes[i].read(fp, constantPool);
    }
}

void ClassInfo::read(FILE * fp) {
    ByteReader<uint16_t> twoByteReader;
    innerClassInfoIndex = twoByteReader.byteCatch(fp);
    outerClassInfoIndex = twoByteReader.byteCatch(fp);
    innerNameIndex = twoByteReader.byteCatch(fp);
    innerClassAccessFlags = twoByteReader.byteCatch(fp);
}

void InnerClassesAttribute::read(FILE *fp) {
    ByteReader<uint16_t> twoByteReader;
    numberOfClasses = twoByteReader.byteCatch(fp);
    classes = (ClassInfo*)calloc(numberOfClasses, sizeof(ClassInfo));

    for (int i = 0; i < numberOfClasses; i++) {
        classes[i].read(fp);
    }   
}

void InnerClassesAttribute::print(std::vector<CPInfo*> trueCpInfo) {
    // cout << "Class length: " << this->class_length<<endl;
}

void ExceptionsAttribute::read(FILE *fp) {
    ByteReader<uint16_t> twoByteReader;
    numberOfExceptions = twoByteReader.byteCatch(fp);
    execeptionIndexTable = (uint16_t *)calloc(numberOfExceptions, sizeof(uint16_t));
    for (int i = 0; i < numberOfExceptions; i++) {
        execeptionIndexTable[i] = twoByteReader.byteCatch(fp);
    }
}

void SourceFileAttribute::read(FILE * fp) {
    ByteReader<uint16_t> twoByteReader;
    sourcefileIndex = twoByteReader.byteCatch(fp);
}

AttributeInfo::~AttributeInfo() {
    //TODO
}

void LocalVariable::read(FILE * fp) {
    ByteReader<uint16_t> twoByteReader;

    startPC = twoByteReader.byteCatch(fp);
    length = twoByteReader.byteCatch(fp);
    nameIndex = twoByteReader.byteCatch(fp);
    descriptorIndex = twoByteReader.byteCatch(fp);
    index = twoByteReader.byteCatch(fp);
}

void LocalVariableTableAttribute::read(FILE *fp) {
    ByteReader<uint16_t> twoByteReader;
    localVariableTableLength = twoByteReader.byteCatch(fp);

    localVariableTable = (LocalVariable*)calloc(localVariableTableLength, sizeof(LocalVariable));

    for (int i = 0; i < localVariableTableLength; i++) {
        localVariableTable[i].read(fp);
    }
}

void AttributeInfo::read(FILE * fp, std::vector<CPInfo *> constantPool){
    CPInfo* cpInfo;
    ByteReader<uint8_t> oneByteReader;
    ByteReader<uint16_t> twoByteReader;
    ByteReader<uint32_t> fourByteReader;

    attributeNameIndex = twoByteReader.byteCatch(fp);
    attributeLength = fourByteReader.byteCatch(fp);
    cpInfo = constantPool[attributeNameIndex-1];
    string attributeName = cpInfo->getInfo(constantPool).first;

    if(attributeName == "Code"){
        code.read(fp, constantPool);
    }
    else if(attributeName == "ConstantValue") {
        constantValue.read(fp);
    }
    else if(attributeName == "Exceptions") {
        exceptions.read(fp);
    }
    else if(attributeName == "InnerClasses") {
        innerClasses.read(fp);
    }
    else if(attributeName == "SourceFile") {
        sourceFile.read(fp);
    }
    else if(attributeName == "LineNumberTable") {
        lineNumberTable.read(fp);
    }
    else if (attributeName == "LocalVariableTable") {
        localVariableTable.read(fp);
    }
    else {
        cout << "AttributeName not recognized: " << attributeName << endl;
        info = (uint8_t*)calloc(attributeLength, sizeof(uint8_t));
        /* Ignore attribute if it doesn't exist */
        for(int i = 0; i < attributeLength ; i++) {
            info[i] = oneByteReader.byteCatch(fp);
        }
    }
}

void AttributeInfo::print(std::vector<CPInfo *> trueCpInfo) {
    // CpAttributeInterface utf8Getter;
    // std::string attribute_name = utf8Getter.getUTF8(trueCpInfo, this->name_index-1);

    // cout << setw(2) << setfill('0') << "Attribute Name Index: cp info #" << this->name_index<< " <"<< attribute_name << ">" <<endl;
    // cout << setw(2) << setfill('0') << "Attribute Length: " << this->length<< endl;

    // if(attribute_name == "Code"){
    //     code.print(trueCpInfo);
    // }

    // else if(attribute_name == "ConstantValue"){
    //     constant_value.print(trueCpInfo);
    // }

    // else if(attribute_name == "Exceptions"){
    //     exception.print(trueCpInfo);
    // }
    // else if(attribute_name == "InnerClass"){
    //     inner_class.print(trueCpInfo);
    // }
    // else if(attribute_name == "SourceFile"){
    //     sourceFile.print(trueCpInfo);
    // }
    // else if(attribute_name == "LineNumberTable"){
    //     lineNumber.print();
    // }
}