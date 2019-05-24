#include <iostream>
#include <fstream>
#include "../hpp/ClassFile.hpp"
#include "../hpp/ClassLoader.hpp"
#include "../hpp/ClassPrinter.hpp"


using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Numero incorreto de argumentos especificado" << endl;
    }
    else {
        FILE *fp;
        ClassLoader classLoader;
        ClassFile classFile;
        fp = fopen(argv[1], "rb");
        classFile = classLoader.loadClassFile(fp);
        
        ClassPrinter classPrinter(classFile);
        classPrinter.print();
        fclose(fp);
    }
    return 0;
}