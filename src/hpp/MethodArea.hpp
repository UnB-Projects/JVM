/** @file MethodArea.hpp
 *  @brief Contém o armazenamento das informações do MethodArea  
 *  @bug No known bugs.
 */
#ifndef METHOD_AREA_H_INCLUDED
#define METHOD_AREA_H_INCLUDED

#include <vector>
#include <map>
#include "ClassFile.hpp"

using namespace std;

/** @class MethodArea
*   @brief Classe que contém toda a estrutura do MethodArea
*   @bug No known bugs.
*/

class MethodArea {
private:
    map<string, ClassFile> classes;
    map<string, bool> clinitWasExecuted;
public:
    void insertClass(ClassFile);
    ClassFile* getClassFile(string name);
    bool isClassInitialized(string name);
    void setClassAsInitialized(string name);
};

#endif