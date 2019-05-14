#include "../hpp/ClassFile.hpp"


ClassFile::ClassFile(FILE * fp) {
    this->setMagic(fp);

    if ((this->getMagic()) == 0xCAFEBABE) {
        this->setMinor(fp);
        this->setMinor(fp);
        this->setConstantPoolCount(fp);
        this->setConstantPool(fp);
        this->setAccessFlag(fp);
        this->setThisClass(fp);
        this->setSuperClass(fp);
        this->setInterfaceCount(fp);
        this->setInterface(fp);
        this->setFieldsCount(fp);
        this->setFields(fp);
        this->setMethodsCount(fp);
        this->setMethods(fp);
        this->setAttributesCount(fp);
        this->setAttributes(fp);
    }
    else {
        cout << "O magic number nao eh 0xCAFEBABE!" << endl;
    }
}

ClassFile::~ClassFile() {
    for (auto i : interfaces) {
        i.~InterfaceInfo();
    }

    for (auto a : attributes) {
        // a.~AttributeInfo();
    }
}


void ClassFile::setMagic(FILE * fp) {

}