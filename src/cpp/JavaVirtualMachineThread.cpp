/** @file JavaVirtualMachineThread.cpp
 *  @brief Contém métodos para manipulação da pilha de frames  
 *  @bug No known bugs.
 */
#include "../hpp/JavaVirtualMachineThread.hpp"

/** @fn JavaVirtualMachineThread::JavaVirtualMachineThread
 *  @brief Construtor do JavaVirtualMachineThread
 *  @param
 *  @return 
 */
JavaVirtualMachineThread::JavaVirtualMachineThread() {
    this->pc = 0;
}

/** @class JavaVirtualMachineThread::pushToJVMStack
 *  @brief Método que armazena o frame na pilha
 *  @param frame do tipo Frame
 *  @return
 */
void JavaVirtualMachineThread::pushToJVMStack(Frame frame) {
    this->javaVirtualMachineStack.push(frame);
}

/** @class JavaVirtualMachineThread::popFromJVMStack
 *  @brief Método que retira o frame do topo da pilha
 *  @param 
 *  @return
 */

void JavaVirtualMachineThread::popFromJVMStack() {
    this->javaVirtualMachineStack.pop();
}

/** @class JavaVirtualMachineThread::incrementPcBy
 *  @brief Método que incrementa o PC
 *  @param increment do tipo uint32_t
 *  @return
 */
void JavaVirtualMachineThread::incrementPcBy(uint32_t increment) {
    this->pc += increment;
}