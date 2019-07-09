/** @file JavaVirtualMachineThread.hpp
 *  @brief Contém toda a estrutura da manipulação da pilha de frame;
 *  @bug No known bugs.
 */
#ifndef JAVA_VIRTUAL_MACHINE_THREAD_H_INCLUDED
#define JAVA_VIRTUAL_MACHINE_THREAD_H_INCLUDED

#include <stack>
#include "Frame.hpp"

using namespace std;
/** @class JavaVirtualMachineThread
*   @brief Classe que contém toda a estrutura de manipulação da pilha de frames
*   @bug No known bugs.
*/
class JavaVirtualMachineThread {
private:
    stack<Frame> javaVirtualMachineStack;
public:
    uint32_t pc;
    JavaVirtualMachineThread();
    void pushToJVMStack(Frame);
    void popFromJVMStack();
    void incrementPcBy(uint32_t);

    Frame* getCurrentFrame() {
        return &(this->javaVirtualMachineStack.top());
    }
    bool isJVMStackEmpty() {
        return this->javaVirtualMachineStack.empty();
    }
    stack<Frame>* getJVMStack() {
        return &javaVirtualMachineStack;
    }
    // uint32_t getPc() {
    //     return pc;
    // }
    // stack<Frame> getJavaVirtualMachineStack() {
    //     return javaVirtualMachineStack;
    // }
};

#endif