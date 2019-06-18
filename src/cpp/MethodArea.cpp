#include "../hpp/MethodArea.hpp"

void MethodArea::insertClass(ClassFile classFile) {
    vector<CPInfo*>constantPool = classFile.getConstantPool();
    string name = constantPool[classFile.getThisClass()-1]->getInfo(constantPool).first;
    this->classes.insert(make_pair(name, classFile));
}

ClassFile* MethodArea::getClassFile(string name) {
    return &(classes[name]);
}