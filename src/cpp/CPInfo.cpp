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
        if ((char*)CONSTANT_Utf8_info.bytes == 0) {
            printf("\n\nO valor de bytes nao pode ser zero!\n\n");
        }
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

string CPInfo::getUTF8(vector<CPInfo*> constantPool) {
    return (char*)CONSTANT_Utf8_info.bytes;
}

string CPInfo::getClassUTF8(vector<CPInfo*> constantPool) {
    CPInfo *nameInfo = constantPool[CONSTANT_Class_info.name_index-1];
    return nameInfo->getUTF8(constantPool);
}

string CPInfo::getStringUTF8(vector<CPInfo*> constantPool) {
    CPInfo *stringInfo = constantPool[CONSTANT_String_info.string_index-1];
    return stringInfo->getUTF8(constantPool);
}

pair<string,string> CPInfo::getFieldrefUTF8(vector<CPInfo*> constantPool) {
    CPInfo *classInfo = constantPool[CONSTANT_Fieldref_info.class_index-1];
    CPInfo *nameAndTypeInfo = constantPool[CONSTANT_Fieldref_info.name_and_type_index-1];
    string className = classInfo->getClassUTF8(constantPool);
    string nameAndType = nameAndTypeInfo->getNameAndTypeUTF8(constantPool).first + " : " + nameAndTypeInfo->getNameAndTypeUTF8(constantPool).second;
    return make_pair(className, nameAndType);
}

pair<string,string> CPInfo::getMethodrefUTF8(vector<CPInfo*> constantPool) {
    CPInfo *classInfo = constantPool[CONSTANT_Methodref_info.class_index-1];
    CPInfo *nameAndTypeInfo = constantPool[CONSTANT_Methodref_info.name_and_type_index-1];
    string className = classInfo->getClassUTF8(constantPool);
    string nameAndType = nameAndTypeInfo->getNameAndTypeUTF8(constantPool).first + " : " + nameAndTypeInfo->getNameAndTypeUTF8(constantPool).second;
    return make_pair(className, nameAndType);
}

pair<string,string> CPInfo::getInterfaceMethodrefUTF8(vector<CPInfo*> constantPool) {
    CPInfo *classInfo = constantPool[CONSTANT_InterfaceMethodref_info.class_index-1];
    CPInfo *nameAndTypeInfo = constantPool[CONSTANT_InterfaceMethodref_info.name_and_type_index-1];
    string className = classInfo->getClassUTF8(constantPool);
    string nameAndType = nameAndTypeInfo->getNameAndTypeUTF8(constantPool).first + " : " + nameAndTypeInfo->getNameAndTypeUTF8(constantPool).second;
    return make_pair(className, nameAndType);
}

pair<string,string> CPInfo::getNameAndTypeUTF8(vector<CPInfo*> constantPool) {
    CPInfo *nameInfo = constantPool[CONSTANT_NameAndType_info.name_index-1];
    CPInfo *descriptorInfo = constantPool[CONSTANT_NameAndType_info.descriptor_index-1];
    string name = nameInfo->getUTF8(constantPool);
    string descriptor = descriptorInfo->getUTF8(constantPool);
    return make_pair(name, descriptor); 
}

pair<string,string> CPInfo::getInfo(vector<CPInfo*> constantPool) {
    pair<string,string> info;
    switch(tag) {
    case CONSTANT_Utf8:
        info =  make_pair(getUTF8(constantPool), "");
        break;
    case CONSTANT_Class:
        info = make_pair(getClassUTF8(constantPool), "");
        break;
    case CONSTANT_Fieldref:
        info = getFieldrefUTF8(constantPool);
        break;
    case CONSTANT_Methodref:
        info = getMethodrefUTF8(constantPool);
        break;
    case CONSTANT_NameAndType:
        info = getNameAndTypeUTF8(constantPool);
        break;
    case CONSTANT_InterfaceMethodref:
        info = getInterfaceMethodrefUTF8(constantPool);
        break;
    case CONSTANT_String:
        info = make_pair(getStringUTF8(constantPool), "");
        break;
    default:
        cout << "Erro! Tag nao reconhecida:" << tag << endl;
        exit(0);
        break;
    }

    return info;
}

int64_t CPInfo::getLongNumber() {
    return ((uint64_t)this->CONSTANT_Long_info.high_bytes << 32) | this->CONSTANT_Long_info.low_bytes;
}

double CPInfo::getDoubleNumber() {
    uint64_t aux = ((uint64_t)this->CONSTANT_Long_info.high_bytes << 32) | this->CONSTANT_Long_info.low_bytes;
    double num;
    memcpy(&num, &aux, sizeof(double));
    return num;
}