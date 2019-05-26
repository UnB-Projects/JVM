#include "../hpp/MethodInfo.hpp"

MethodInfo::~MethodInfo() {
    // for (auto a : attributes) {
    //     //TODO
    // }
}

void MethodInfo::read(FILE *fp, vector<CPInfo*> constantPool) {
    ByteReader<uint16_t> reader;

    accessFlags = reader.byteCatch(fp);
    nameIndex = reader.byteCatch(fp);
    descriptorIndex = reader.byteCatch(fp);
    attributesCount = reader.byteCatch(fp);

    attributes = (AttributeInfo*)calloc(attributesCount, sizeof(AttributeInfo));
    for(int i = 0; i < attributesCount; i++){
        AttributeInfo *attributeInfo = (AttributeInfo *)calloc(1, sizeof(AttributeInfo));
        attributeInfo->read(fp, constantPool);
        attributes[i] = *attributeInfo;
    }
}