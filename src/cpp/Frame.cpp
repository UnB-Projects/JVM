#include "../hpp/Frame.hpp"

Frame::Frame(vector<JavaType> localVariables, stack<JavaType*> operandStack, vector<CPInfo*> constantPool) {
    this->localVariables = localVariables;
    this->operandStack = operandStack;
    this->constantPool = constantPool;
}

Frame::Frame(vector<CPInfo*> constantPool, MethodInfo* method) {
    this->constantPool = constantPool;
    this->method = method;
    // uint16_t maxLocals = method->getAttributes()->getCodeAttribute().getMaxLocals();
    // this->localVariables = vector<JavaType>(maxLocals);
    // Falta selecionar o code a partir de um loop!
}