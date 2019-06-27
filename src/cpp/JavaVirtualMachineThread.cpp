#include "../hpp/JavaVirtualMachineThread.hpp"

JavaVirtualMachineThread::JavaVirtualMachineThread() {
    this->pc = 0;
}

void JavaVirtualMachineThread::pushToJVMStack(Frame frame) {
    this->javaVirtualMachineStack.push(frame);
}

void JavaVirtualMachineThread::incrementPcBy(uint32_t increment) {
    this->pc += increment;
}