#ifndef ___CLASSPRINTER_H___
#define ___CLASSPRINTER_H___

#include <stdio.h>
#include <iomanip>
#include "ClassFile.hpp"
#include "CPAttributeInterface.hpp"



class ClassPrinter {
private:

public:
    void printer(ClassFile classloader);
    //nao mudei o nome da funcao de baixo, dps nois ve como fica
    string Flag_names(int flag_byte, int parametro);
};

#endif
