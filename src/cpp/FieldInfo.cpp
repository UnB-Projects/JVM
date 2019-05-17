#include "../hpp/FieldInfo.hpp"

FieldInfo::~FieldInfo() {   
    for(auto a : this->attributes) {
        a->~AttributeInfo();
        free(a);
    }
}

void FieldInfo::read(FILE *fp, std::vector<CPInfo*> trueCpInfo){
    ByteReader<uint16_t> twoByteReader;

    accessFlags = twoByteReader.byteCatch(fp);
    nameIndex = twoByteReader.byteCatch(fp);
    descriptorIndex = twoByteReader.byteCatch(fp);
    attributesCount = twoByteReader.byteCatch(fp);
    
    for(int i = 0; i < attributesCount; i++) {
        AttributeInfo * attribute = (AttributeInfo *)calloc(1, sizeof(*attribute));
        //TALVEZ ESTEJA ERRADA ESSA PARTE NAO ESQUECE
        attribute->read(fp,trueCpInfo);
        attributes.push_back(attribute);
    }
}