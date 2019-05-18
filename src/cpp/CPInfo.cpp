#include "../hpp/CPInfo.hpp"

CPInfo::~CPInfo() {
    //TODO
}

void CPInfo::setTag(uint8_t tag) {
    this->tag = tag;
}

void CPInfo::read(FILE * fp) {
    ByteReader<uint8_t> oneByteReader;
    ByteReader<uint16_t> twoByteReader;
    ByteReader<uint32_t> fourByteReader;

    this->tag = oneByteReader.byteCatch(fp);

    switch(this->tag) {
    case CONSTANT_Utf8:
        this->CONSTANT_Utf8_info.length = twoByteReader.byteCatch(fp);
        this->CONSTANT_Utf8_info.bytes = (uint8_t *) calloc(this->CONSTANT_Utf8_info.length+1,sizeof(uint8_t));
        for (int j = 0; j < this->CONSTANT_Utf8_info.length; j++) {
            uint8_t byte = oneByteReader.byteCatch(fp);
            this->CONSTANT_Utf8_info.bytes[j] = byte;
        }
        this->CONSTANT_Utf8_info.bytes[this->CONSTANT_Utf8_info.length] = '\0';
        break;
    case CONSTANT_Integer:
        this->CONSTANT_Integer_info.bytes = fourByteReader.byteCatch(fp);
        break;
    case CONSTANT_Float:
        this->CONSTANT_Float_info.bytes = fourByteReader.byteCatch(fp);
        break;
    case CONSTANT_Long:
        this->CONSTANT_Long_info.high_bytes = fourByteReader.byteCatch(fp);
        this->CONSTANT_Long_info.low_bytes  = fourByteReader.byteCatch(fp);
        break;
    case CONSTANT_Double:
        this->CONSTANT_Double_info.high_bytes = fourByteReader.byteCatch(fp);
        this->CONSTANT_Double_info.low_bytes  = fourByteReader.byteCatch(fp);
        break;
    case CONSTANT_Class:
        this->CONSTANT_Class_info.name_index = twoByteReader.byteCatch(fp);
        break;
    case CONSTANT_String:
        this->CONSTANT_String_info.string_index = twoByteReader.byteCatch(fp);
        break;
    case CONSTANT_Fieldref:
        this->CONSTANT_Fieldref_info.class_index = twoByteReader.byteCatch(fp);
        this->CONSTANT_Fieldref_info.name_and_type_index = twoByteReader.byteCatch(fp);
        break;
    case CONSTANT_Methodref:
        this->CONSTANT_Methodref_info.class_index = twoByteReader.byteCatch(fp);
        this->CONSTANT_Methodref_info.name_and_type_index = twoByteReader.byteCatch(fp);
        break;
    case CONSTANT_InterfaceMethodref:
        this->CONSTANT_InterfaceMethodref_info.class_index = twoByteReader.byteCatch(fp);
        this->CONSTANT_InterfaceMethodref_info.name_and_type_index = twoByteReader.byteCatch(fp);
        break;
    case CONSTANT_NameAndType:
        this->CONSTANT_NameAndType_info.name_index = twoByteReader.byteCatch(fp);
        this->CONSTANT_NameAndType_info.descriptor_index = twoByteReader.byteCatch(fp);
        break;
    default:
        cout << "Uma tag invalida foi detectada" << endl;
        exit(0);
    }
}

// string CPInfo::getUTF8(vector<CPInfo*> constantPool) {
//     return (char*)CONSTANT_Utf8_info.bytes;
// }

// string CPInfo::getClassUTF8(vector<CPInfo*> constantPool) {
//     CPInfo* utf8 = constantPool[CONSTANT_Class_info.name_index-1];
//     return utf8->getUTF8(constantPool);
// }

// string CPInfo::getNameAndTypeUTF8(vector<CPInfo*> constantPool) {

// }

// pair<string,string> CPInfo::getInfo(vector<CPInfo*> constantPool) {
//     switch(tag) {
//     case CONSTANT_Utf8:
//         return make_pair(getUTF8(constantPool), "");
//         break;
//     case CONSTANT_Class:
//         return make_pair(getClassUTF8(constantPool), "");
//         break;
//     case CONSTANT_Fieldref:
//         CPInfo *classInfo = constantPool[CONSTANT_Fieldref_info.class_index-1];
//         CPInfo *nameAndTypeInfo = constantPool[CONSTANT_Fieldref_info.name_and_type_index-1];
//         return make_pair(classInfo->getClassUTF8)

//         break;
//     case CONSTANT_Methodref:
//         return getUTF8(constantPool, constantPool[index]->CONSTANT_Methodref_info.class_index-1);
//         // return getUTF8(constantPool, constantPool[index]->getMethodrefInfo().name_and_type_index -1);
//         break;
//     case CONSTANT_NameAndType:
//         return getUTF8(constantPool, constantPool[index]->CONSTANT_NameAndType_info.name_index -1);
//         // return getUTF8(constantPool, constantPool[index]->getNameAndTypeInfo().descriptor_index -1);
//         break;
//     case CONSTANT_InterfaceMethodref:
//         return getUTF8(constantPool, constantPool[index]->CONSTANT_InterfaceMethodref_info.class_index -1);
//         // return getUTF8(constantPool, constantPool[index]->getInterfaceMethodrefInfo().name_and_type_index -1);
//         break;
//     case CONSTANT_String:
//         return getUTF8(constantPool, constantPool[index]->CONSTANT_String_info.string_index -1);
//         break;
//     default:
//         cout << "Erro! Tag nao reconhecida:" << constantPool[index]->tag << endl;
//         exit(0);
//         break;
//     }
// }