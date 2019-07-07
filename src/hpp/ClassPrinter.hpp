#ifndef ___CLASSPRINTER_H___
#define ___CLASSPRINTER_H___

#if defined(_WIN32)										/*definicoes para limpar a tela e promover ilusao de movimento*/
	#define CLEAR system("cls");
#else
	#define CLEAR system("clear");
#endif

#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <utility>
#include "ClassFile.hpp"
#include "InstructionSet.hpp"

using namespace std;

class ClassPrinter {
private:
    ClassFile classFile;
    InstructionSet * instructionSet;
    string interpretClassFlags(uint16_t);
    string interpretMethodFlags(uint16_t);
    string interpretFieldFlags(uint16_t);
    void printGeneralInformation();
    void printConstantPool();
    void printInterfaces();
    void printFields();
    void printMethods();
    void printAttributes(AttributeInfo*, uint16_t);
    void printClassFileAttributes();

    void printSourceFileInfo(SourceFileAttribute*);
    void printConstantValueInfo(ConstantValueAttribute*);
    void printCodeInfo(CodeAttribute*);
    void printCodeExceptionTableInfo(ExceptionHandler*, uint16_t);
    void printLineNumberTableInfo(LineNumberTableAttribute*);
    void printLocalVariableTableInfo(LocalVariableTableAttribute*);
    void printExceptionsInfo(ExceptionsAttribute*);
    void printInnerClassesInfo(InnerClassesAttribute*);

public:
    ClassPrinter(ClassFile classFile, InstructionSet * instructionSet);
    void print();
    //nao mudei o nome da funcao de baixo, dps nois ve como fica
    string Flag_names(int flag_byte, int parametro);
};

#endif