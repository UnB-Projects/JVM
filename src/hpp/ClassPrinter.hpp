#ifndef ___CLASSPRINTER_H___
#define ___CLASSPRINTER_H___

#include <stdio.h>
#include <iomanip>
#include "ClassFile.hpp"
#include "CPAttributeInterface.hpp"

using namespace std;

class ClassPrinter {
private:
    ClassFile classFile;
    void printGeneralInformation();
    string interpretFlags(uint16_t);

public:
    ClassPrinter(ClassFile classFile);
    void print(ClassFile classloader);
    //nao mudei o nome da funcao de baixo, dps nois ve como fica
    string Flag_names(int flag_byte, int parametro);
};

#endif