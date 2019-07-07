#include <iostream>
#include <fstream>
#include "../hpp/ClassFile.hpp"
#include "../hpp/ClassLoader.hpp"
#include "../hpp/ClassPrinter.hpp"
#include "../hpp/ExecutionEngine.hpp"

using namespace std;

string getProjectPath(string commandLinePath) {
    int i = commandLinePath.size()-1;

    #if defined(_WIN32)
    while (i >= 0 && commandLinePath[i] != '\\') {
        i--;
    }
    #else
    while (i >= 0 && commandLinePath[i] != '/') {
        i--;
    }
    #endif

    return commandLinePath.substr(0, i+1);
}

string getClassName(string commandLinePath) {
    int i = commandLinePath.size()-1;

    #if defined(_WIN32)
    while (i >= 0 && commandLinePath[i] != '\\') {
        i--;
    }
    #else
    while (i >= 0 && commandLinePath[i] != '/') {
        i--;
    }
    #endif

    return commandLinePath.substr(i+1, commandLinePath.size());
}

int main(int argc, char *argv[]) {
    if (argc != 3)  {
        cout << "Numero incorreto de argumentos especificado" << endl;
    }
    else {
        ClassFile classFile;
        string projectPath = getProjectPath(argv[2]);
        string className = getClassName(argv[2]);
        ClassLoader classLoader(getProjectPath(argv[2]));
        MethodArea methodArea;

        classLoader.setMethodArea(&methodArea);
        classFile = classLoader.loadClassFile(className);

        string option = argv[1];
        InstructionSet instructionSet(&classLoader);

        if (option.compare("-e") == 0) {
            ClassPrinter classPrinter(classFile, &instructionSet);
            classPrinter.print();
        }
        else if (option.compare("-i") == 0) {
            string projectPath = getProjectPath(argv[2]);

            classLoader.loadSuperClasses(&classFile);

            //Inicio da execucao do programa
            ExecutionEngine executionEngine(&classFile, &methodArea, &instructionSet);
            executionEngine.execute();
        }
        else {
            cout << "O segundo argumento deve ser -e para exibidor ou -i para interpredaor" << endl;
        }
    }
    return 0;
}