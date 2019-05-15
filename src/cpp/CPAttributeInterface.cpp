#include "../hpp/CPAttributeInterface.hpp"

#define CONSTANT_Utf8 1
#define CONSTANT_Integer 3
#define CONSTANT_Float 4
#define CONSTANT_Long 5
#define CONSTANT_Double 6
#define CONSTANT_Class 7
#define CONSTANT_String 8
#define CONSTANT_Fieldref 9
#define CONSTANT_Methodref 10
#define CONSTANT_InterfaceMethodref 11
#define CONSTANT_NameAndType 12
#define CONSTANT_Empty 0

string CPAttributeInterface::getUTF8(vector<CPInfo*> constantPoolTable, uint16_t index) {

    if(constantPoolTable[index]->getTag() == 1) return (char*)constantPoolTable[index]->getUTF8Info().bytes;

    switch(constantPoolTable[index]->getTag()) {
        
        case CONSTANT_Class:
            return getUTF8(constantPoolTable, constantPoolTable[index]->getClassInfo().name_index-1);
            break;

        case CONSTANT_Fieldref:
            return getUTF8(constantPoolTable, constantPoolTable[index]->getFieldrefInfo().class_index-1);
            return getUTF8(constantPoolTable, constantPoolTable[index]->getFieldrefInfo().name_and_type_index-1);
            break;

        case CONSTANT_Methodref:
            return getUTF8(constantPoolTable, constantPoolTable[index]->getMethodrefInfo().class_index-1);
            return getUTF8(constantPoolTable, constantPoolTable[index]->getMethodrefInfo().name_and_type_index -1);
            break;

        case CONSTANT_NameAndType:
            return getUTF8(constantPoolTable, constantPoolTable[index]->getNameAndTypeInfo().name_index -1);
            return getUTF8(constantPoolTable, constantPoolTable[index]->getNameAndTypeInfo().descriptor_index -1);
            break;

        case CONSTANT_InterfaceMethodref:
            return getUTF8(constantPoolTable, constantPoolTable[index]->getInterfaceMethodrefInfo().class_index -1);
            return getUTF8(constantPoolTable, constantPoolTable[index]->getInterfaceMethodrefInfo().name_and_type_index -1);
            break;

        case CONSTANT_String:
            return getUTF8(constantPoolTable, constantPoolTable[index]->getStringInfo().string_index -1);
            break;
        default:
            cout << "Tag nao reconhecida!" << endl;
            return "";
            break; /* Must Change default */
    }
} 
