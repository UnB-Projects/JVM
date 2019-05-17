#include <iostream>

#include "../hpp/ClassFile.hpp"
#include "../hpp/ClassPrinter.hpp"

#include <map>


using namespace std;

/*struct Instance {
    std::string name;
    std::map< std::string, Operand* > * references;
    ClassLoader * classe;

    Instance(ClassLoader*);
};
*/
// esse metodo vem de um arquivo chamado GLOBAL_file.hpp
/*class MethodsArea {
    public:
    
    static std::map<std::string, Instance*> GLOBAL_loadedClasses;
    static std::map<std::string, Instance*> GLOBAL_staticClasses;
    static std::string path;
        
    static Operand * getStaticfield(std::string className, std::string varName);
    static MethodInfo * findMethodByNameOrDeor(ClassLoader*,std::string,std::string);
    static Operand    * copyOperand(Operand*);
};
*/
// metodo que ta na jvm.cpp
void getPath(char * toConvert) {

    //MethodsArea dump;
    std::string toEdit(toConvert);

    auto pos  = toEdit.find_last_of('/');
    auto path = toEdit.substr(0,pos+1);
    
    //dump.path = path;
}


int main(int argc, char * argv[]) {

    if(argc != 3) {
        cout << "Necerrário(s) argumentos.\n" << endl;
    }

    FILE * fp = fopen(argv[2],"rb");
    if (fp != NULL) {
    	
    	cout << endl << "Arquivo aberto" << endl;
        
    	ClassFile classloader(fp);
        cout << "@@@" <<endl;
        ClassPrinter a;
      if(classloader.getMagic() != 0xcafebabe) {
        std::cout <<  "Número magico incorreto.\n" << std::endl;
        return 0;
      }
        
    	//getPath(argv[2]);
    	fclose(fp);
    	switch(*argv[1]) {
        	//case 'i': classInterpreter(classloader); break;
        	//case 'e': classReader(classloader);      break;
            
        	case 'e': a.printer(classloader);      break;

    	}
    	exit(0);
    	
	} else {
		cout << "Nao foi possivel abrir o arquivo" << endl;
		return -1;
	}

    return 0;
    
}