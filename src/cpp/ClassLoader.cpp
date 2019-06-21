#include "../hpp/ClassLoader.hpp"

ClassFile ClassLoader::loadClassFile(FILE * fp) {
    if (fp != NULL) {
        ClassFile classFile(fp);
        return classFile;
    }
    cout << "Nao foi possivel abrir o arquivo! Programa terminado!" << endl;
    exit(0);
}

void ClassLoader::loadSuperClasses(ClassFile* classFile, string projectPath) {
    #if defined(_WIN32)
        printf("Faltou implementar no windows!\n");
    #else
        vector<CPInfo*> constantPool = classFile->getConstantPool();
        FILE * fp;

        methodArea->insertClass(*classFile);
        if (classFile->getSuperClass() == 0) {
            return;
        }

        string superClassPath = constantPool[classFile->getSuperClass()-1]->getInfo(constantPool).first.c_str();

        if (superClassPath.compare("java/lang/string") == 0 ||
            superClassPath.compare("java/lang/System.out") == 0 ||
            superClassPath.compare("java/lang/System.in") == 0) {
            return;
        }

        if (superClassPath.compare("java/lang/Object") == 0) {
            fp = fopen((superClassPath+".class").c_str(), "rb");
        }
        else {
            fp = fopen((projectPath+superClassPath+".class").c_str(), "rb");
        }
        ClassFile superClassFile = loadClassFile(fp);
        loadSuperClasses(&superClassFile, projectPath);
        fclose(fp);
    #endif
}