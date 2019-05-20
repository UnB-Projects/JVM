#ifndef ___CLASSPRINTER_H___
#define ___CLASSPRINTER_H___

#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <utility>
#include "ClassFile.hpp"
#include "CPAttributeInterface.hpp"

using namespace std;

class ClassPrinter {
private:
    ClassFile classFile;
    string interpretClassFlags(uint16_t);
    void printGeneralInformation();
    void printConstantPool();
    void printInterfaces();
    void printFields();
    void printMethods();
    void printAttributes();

public:
    ClassPrinter(ClassFile classFile);
    void print();
    //nao mudei o nome da funcao de baixo, dps nois ve como fica
    string Flag_names(int flag_byte, int parametro);
};

#endif