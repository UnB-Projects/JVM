#include "../hpp/JavaVirtualMachineThread.hpp"

JavaVirtualMachineThread::JavaVirtualMachineThread() {
    this->pc = 0;
}

void JavaVirtualMachineThread::pushToJVMStack(Frame frame) {
    this->javaVirtualMachineStack.push(frame);
}