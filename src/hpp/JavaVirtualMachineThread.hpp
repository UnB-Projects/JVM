#ifndef JAVA_VIRTUAL_MACHINE_THREAD_H_INCLUDED
#define JAVA_VIRTUAL_MACHINE_THREAD_H_INCLUDED

#include <stack>
#include "Frame.hpp"

using namespace std;

class JavaVirtualMachineThread {
private:
    stack<Frame> javaVirtualMachineStack;
public:
    uint32_t pc;
    JavaVirtualMachineThread();
    void pushToJVMStack(Frame);
    void incrementPcBy(uint32_t);

    Frame* getCurrentFrame() {
        return &(this->javaVirtualMachineStack.top());
    }
    bool isJVMStackEmpty() {
        return this->javaVirtualMachineStack.empty();
    }
    // uint32_t getPc() {
    //     return pc;
    // }
    // stack<Frame> getJavaVirtualMachineStack() {
    //     return javaVirtualMachineStack;
    // }
};

#endif