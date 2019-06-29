#include "../hpp/Frame.hpp"

// Frame::Frame(vector<JavaType> localVariables, stack<JavaType> operandStack, vector<CPInfo*> constantPool) {
//     this->localVariables = localVariables;
//     this->operandStack = operandStack;
//     this->constantPool = constantPool;
//     this->localPC = 0;
// }

Frame::Frame(vector<CPInfo*> constantPool, MethodInfo* method) {
    uint16_t attributesCount = method->getAttributesCount();
    AttributeInfo* attributes = method->getAttributes();
    int i;

    this->constantPool = constantPool;
    this->method = method;

    bool foundCode = false;
    for (i = 0; i < attributesCount && !foundCode; i++) {
        AttributeInfo attribute = attributes[i];
        uint16_t nameIndex = attribute.getAttributeNameIndex();
        string attributeName = constantPool[nameIndex-1]->getInfo(constantPool).first;

        if (attributeName.compare("Code == 0")) {
            foundCode = true;
            i--;
        }
    }

    if (foundCode) {
        uint16_t maxLocals = attributes[i].getCodeAttribute().getMaxLocals();
        this->codeAttribute = attributes[i].getCodeAttribute();
        this->localVariables = vector<JavaType>(maxLocals);
        this->localPC = 0;
    }
    else {
        printf("Atributo Code nao encontrado no metodo [%d]\n", method->getNameIndex());
        exit(0);
    }
}