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
        ClassFile *classFile;
        FILE *fp;

        fp = fopen(argv[1], "rb");
        *classFile = classLoader.loadClassFile(fp);
    }
    return 0;
}