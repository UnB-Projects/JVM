#include <iostream>
#include <fstream>
#include "../hpp/ClassFile.hpp"
#include "../hpp/ClassLoader.hpp"
#include "../hpp/ClassPrinter.hpp"
#include "../hpp/ExecutionEngine.hpp"

using namespace std;

string getProjectPath(string commandLinePath) {
    int i = commandLinePath.size()-1;

    while (i >= 0 && commandLinePath[i] != '/') {
        i--;
    }

    return commandLinePath.substr(0, i);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Numero incorreto de argumentos especificado" << endl;
    }
    else {
        FILE *fp;
        ClassFile classFile;
        ClassLoader classLoader;
        fp = fopen(argv[2], "rb");
        classFile = classLoader.loadClassFile(fp);

        string option = argv[1];

        if (option.compare("-e") == 0) {
            ClassPrinter classPrinter(classFile);
            classPrinter.print();
        }
        else if (option.compare("-i") == 0) {
            MethodArea methodArea;
            string projectPath = getProjectPath(argv[2]);

            //Carregamento de todas as classes e suas dependências
            classLoader.setMethodArea(&methodArea);
            classLoader.loadSuperClasses(&classFile, projectPath);

            //Inicio da execucao do programa
            ExecutionEngine executionEngine(&classFile, &methodArea);
        }
        else {
            cout << "O segundo argumento deve ser -e para exibidor ou -i para interpredaor" << endl;
        }
        fclose(fp);
    }
    return 0;
}