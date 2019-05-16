#include <iostream>
#include <fstream>
#include "../hpp/ClassLoader.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Numero incorreto de argumentos especificado" << endl;
    }
    else {
        ClassLoader classLoader;
        ClassFile classFile;
        FILE *fp;

        fp = fopen(argv[1], "rb");
        classFile = classLoader.loadClassFile(fp);
        
        printf("Magic: %#010x\n", classFile.getMagic());
        printf("Minor: %d\n", classFile.getMinorVersion());
        printf("Major: %d\n", classFile.getMajorVersion());
        printf("CP Count: %d\n", classFile.getConstantPoolCount());
        printf("Access Flag: %#010x\n", classFile.getAccessFlags());
        printf("This Class: %d\n", classFile.getThisClass());
        printf("Super Class: %d\n", classFile.getSuperClass());
        printf("Interfaces Count: %d\n", classFile.getInterfacesCount());
        printf("Fields Count: %d\n", classFile.getFieldsCount());
        printf("Methods Count: %d\n", classFile.getMethodsCount());
        printf("Attributes Count: %d\n", classFile.getAttributesCount());
    }
    return 0;
}