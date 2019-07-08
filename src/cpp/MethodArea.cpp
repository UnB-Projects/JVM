/** @file MethodArea.cpp
 *  @brief Contém métodos para manipulação da pilha de frames  
 *  @bug No known bugs.
 */
#include "../hpp/MethodArea.hpp"

/** @class MethodArea::insertClass
 *  @brief Método que insere uma classe no MethodArea
 *  @param classFile do tipo classFile
 *  @return
 */
void MethodArea::insertClass(ClassFile classFile) {
    vector<CPInfo*>constantPool = classFile.getConstantPool();
    string name = constantPool[classFile.getThisClass()-1]->getInfo(constantPool).first;
    this->classes.insert(make_pair(name, classFile));
}

/** @class MethodArea::getClassFile
 *  @brief Método que busca uma classe no MethodArea
 *  @param name do tipo string
 *  @return ClassFile type
 */

ClassFile* MethodArea::getClassFile(string name) {
    return &(classes[name]);
}

/** @class MethodArea::isClassInitialized
 *  @brief Método que inicializa uma classe
 *  @param name do tipo string
 *  @return TrueOrFalse boolean
 */
bool MethodArea::isClassInitialized(string name) {
    if (clinitWasExecuted.count(name)) {
        return true;
    }
    return false;
}

/** @class MethodArea::setClassAsInitialized
 *  @brief Método que insere a classe inicializada
 *  @param name do tipo string
 *  @return
 */

void MethodArea::setClassAsInitialized(string name) {
    this->clinitWasExecuted.insert(make_pair(name, true));
}