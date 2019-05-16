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
        if(true) std::cout << "An invalid tag was detected" << std::endl;
}
}