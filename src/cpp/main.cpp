#include <iostream>
#include <fstream>
#include "../hpp/ClassFile.hpp"
#include "../hpp/ClassLoader.hpp"
#include "../hpp/ClassPrinter.hpp"
#include "../hpp/ExecutionEngine.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Numero incorreto de argumentos especificado" << endl;
    }
    else {
        FILE *fp;
        ClassLoader classLoader;
        ClassFile classFile;
        fp = fopen(argv[2], "rb");
        classFile = classLoader.loadClassFile(fp);

        string option = argv[1];

        if (option.compare("-e") == 0) {
            ClassPrinter classPrinter(classFile);
            classPrinter.print();
        }
        else if (option.compare("-i") == 0) {
            ExecutionEngine executionEngine(&classFile);
        }
        else {
            cout << "O segundo argumento deve ser -e para exibidor ou -i para interpredaor" << endl;
        }
        fclose(fp);
    }
    return 0;
}