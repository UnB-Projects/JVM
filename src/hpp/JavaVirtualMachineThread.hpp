#ifndef JAVA_VIRTUAL_MACHINE_THREAD_H_INCLUDED
#define JAVA_VIRTUAL_MACHINE_THREAD_H_INCLUDED

#include <stack>
#include "Frame.hpp"

using namespace std;

class JavaVirtualMachineThread {
private:
    uint32_t pc;
    stack<Frame*> javaVirtualMachineStack;
public:

};

#endif