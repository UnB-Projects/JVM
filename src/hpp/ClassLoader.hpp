#ifndef __CLASSLOADER_H_INCLUDED__
#define __CLASSLOADER_H_INCLUDED__

#include "ClassFile.hpp"
#include "MethodArea.hpp"

class ClassLoader {
private:
    MethodArea * methodArea;
    string projectPath;
public:
    ClassLoader(string);
    ClassFile loadClassFile(string);
    void loadSuperClasses(ClassFile*);
    void setMethodArea(MethodArea* methodArea) {
        this->methodArea = methodArea;
    }
};

#endif