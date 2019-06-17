#ifndef METHOD_AREA_H_INCLUDED
#define METHOD_AREA_H_INCLUDED

#include <vector>
#include <map>
#include "ClassFile.hpp"

using namespace std;

class MethodArea {
private:
    map<string, ClassFile> classes;
public:
    void insertClass(ClassFile);
    ClassFile* getClassFile(string name);
};

#endif