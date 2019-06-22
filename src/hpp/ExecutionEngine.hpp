#ifndef EXECUTION_ENGINE_H_INCLUDED
#define EXECUTION_ENGINE_H_INCLUDED

#include <string>
#include "ClassFile.hpp"
#include "ClassLoader.hpp"
#include "MethodArea.hpp"
#include "Heap.hpp"
#include "InstructionSet.hpp"
#include "JavaVirtualMachineThread.hpp"

class ExecutionEngine {
private:
    static InstructionSet instructionSet;
    string mainClassFileName;
    MethodInfo* mainMethod;
    MethodArea* methodArea;
    Heap heap;
    void findMainMethod();
public:
    ExecutionEngine(ClassFile*, MethodArea*);
    void execute();
};

#endif