#include "../hpp/MethodArea.hpp"

void MethodArea::insertClass(ClassFile classFile) {
    vector<CPInfo*>constantPool = classFile.getConstantPool();
    string name = constantPool[classFile.getThisClass()-1]->getInfo(constantPool).first;
    this->classes.insert(make_pair(name, classFile));
}

ClassFile* MethodArea::getClassFile(string name) {
    return &(classes[name]);
}

bool MethodArea::isClassInitialized(string name) {
    if (clinitWasExecuted.count(name)) {
        return true;
    }
    return false;
}

void MethodArea::setClassAsInitialized(string name) {
    this->clinitWasExecuted.insert(make_pair(name, true));
}