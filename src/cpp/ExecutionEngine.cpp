#include "../hpp/ExecutionEngine.hpp"

ExecutionEngine::ExecutionEngine(ClassFile* classFile) {
    FILE * fp;
    ClassFile objectClass;
    string path;
    vector<CPInfo*>constantPool = classFile->getConstantPool();
    string name = constantPool[classFile->getThisClass()-1]->getInfo(constantPool).first.c_str();

    this->methodArea.insertClass(*classFile);
    this->mainClassFileName = name;
    findMainMethod();

    #if defined(_WIN32)
    //Definir depois
    printf("Falta implementar!\n");
    exit(0);
    #else
    path = "java/lang/Object.class";
    #endif

    //Carregando classe object
    fp = fopen(path.c_str(), "rb");
    objectClass = boostrapClassLoader.loadClassFile(fp);
    fclose(fp);
    this->methodArea.insertClass(objectClass);
}

void ExecutionEngine::findMainMethod() {
    ClassFile* mainClassFile = methodArea.getClassFile(mainClassFileName);
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