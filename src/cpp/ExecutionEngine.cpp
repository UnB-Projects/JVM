#include "../hpp/ExecutionEngine.hpp"

ExecutionEngine::ExecutionEngine(ClassFile* classFile, MethodArea* methodArea) {
    ClassFile objectClass;
    vector<CPInfo*>constantPool = classFile->getConstantPool();
    string name = constantPool[classFile->getThisClass()-1]->getInfo(constantPool).first;

    this->methodArea = methodArea;
    this->mainClassFileName = name;
    findMainMethod();
}

void ExecutionEngine::findMainMethod() {
    ClassFile* mainClassFile = methodArea->getClassFile(mainClassFileName);
    vector<CPInfo*> constantPool = mainClassFile->getConstantPool();
    vector<MethodInfo*> methods = mainClassFile->getMethods();
    int i;
    bool foundMain = false;

    for (i = 0; i < mainClassFile->getMethodsCount() && !foundMain; i++) {
        MethodInfo* method = methods[i];
        uint16_t nameIndex = method->getNameIndex();
        uint16_t descriptorIndex = method->getDescriptorIndex();
        string name = constantPool[nameIndex-1]->getInfo(constantPool).first;
        string descriptor = constantPool[descriptorIndex-1]->getInfo(constantPool).first;
        if (name.compare("main") == 0 && descriptor.compare("([Ljava/lang/String;)V") == 0) {
            foundMain = true;
            this->mainMethod = method;
        }
    }

    if (!foundMain) {
        printf("A main nao foi encontrada no arquivo especificado!\n");
        exit(0);
    }
}

void ExecutionEngine::execute() {
    ClassFile* mainClassFile = methodArea->getClassFile(mainClassFileName);
    vector<CPInfo*> constantPool = mainClassFile->getConstantPool();
    Frame mainFrame(constantPool, this->mainMethod);
    JavaVirtualMachineThread jvmThread;

    jvmThread.pushToJVMStack(mainFrame);
}