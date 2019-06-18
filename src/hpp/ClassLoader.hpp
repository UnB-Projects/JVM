#ifndef __CLASSLOADER_H_INCLUDED__
#define __CLASSLOADER_H_INCLUDED__

#include "ClassFile.hpp"
#include "MethodArea.hpp"

class ClassLoader {
private:
    MethodArea * methodArea;
public:
    ClassFile loadClassFile(FILE * fp);
    void loadSuperClasses(ClassFile*, string);
    void setMethodArea(MethodArea* methodArea) {
        this->methodArea = methodArea;
    }
};

#endif