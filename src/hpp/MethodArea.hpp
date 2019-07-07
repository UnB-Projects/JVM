#ifndef METHOD_AREA_H_INCLUDED
#define METHOD_AREA_H_INCLUDED

#include <vector>
#include <map>
#include "ClassFile.hpp"

using namespace std;

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