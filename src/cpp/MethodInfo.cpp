/** @file MethodInfo.cpp
 *  @brief Contém métodos para manipulação da pilha de frames  
 *  @bug No known bugs.
 */
#include "../hpp/MethodInfo.hpp"

/** @fn ClassFile::ClassFile
 *  @brief Destrutor
 *  @param 
 *  @return
 */
MethodInfo::~MethodInfo() {
    // for (auto a : attributes) {
    //     //TODO
    // }
}


/** @class MethodInfo::read
 *  @brief Método que visa fazer leitura da estrutura do MethodInfo
 *  @param fp ponteiro para o arquivo .class @param constantPool do tipo vetor de CPInfo
 *  @return
 */
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