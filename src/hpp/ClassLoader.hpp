#ifndef __CLASSLOADER_H_INCLUDED__
#define __CLASSLOADER_H_INCLUDED__

#include "ClassFile.hpp"

class ClassLoader {
public:
    ClassFile loadClassFile(FILE * fp);
};

#endif