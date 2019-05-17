#include "../hpp/ClassLoader.hpp"

ClassFile ClassLoader::loadClassFile(FILE * fp) {
    if (fp != NULL) {
        ClassFile classFile(fp);
        return classFile;
    }
    cout << "Nao foi possivel abrir o arquivo! Programa terminado!" << endl;
    exit(0);
}