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
        printf("Minor: %d\n", classFile.getMinor());
        printf("Major: %d\n", classFile.getMajor());
        printf("CP Count: %d\n", classFile.getConstantPoolCount());
        printf("Access Flag: %#010x\n", classFile.getFlag());
        printf("This Class: %d\n", classFile.getThisClass());
        printf("Super Class: %d\n", classFile.getSuper());
        printf("Interfaces Count: %d\n", classFile.getInterCounter());
        printf("Fields Count: %d\n", classFile.getFieldCount());
        printf("Methods Count: %d\n", classFile.getMethoCount());
        printf("Attributes Count: %d\n", classFile.getAttriCount());
    }
    return 0;
}