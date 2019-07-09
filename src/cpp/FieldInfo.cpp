/** @file FieldInfo.cpp
 *  @brief Métodos com o objetivo de armazenar toda a estrutura do FieldInfo
 *  @bug No known bugs.
 */
#include "../hpp/FieldInfo.hpp"

// FieldInfo::~FieldInfo() {   
//     for(auto a : this->attributes) {
//         // a->~AttributeInfo();
//     }
// }

/** @class FieldInfo::read
 *  @brief Método com o objetivo de fazer a leitura das fields do .class
 *  @param 
 *  @return 
 */
void FieldInfo::read(FILE *fp, vector<CPInfo*> constantPool){
    ByteReader<uint16_t> twoByteReader;

    accessFlags = twoByteReader.byteCatch(fp);
    nameIndex = twoByteReader.byteCatch(fp);
    descriptorIndex = twoByteReader.byteCatch(fp);
    attributesCount = twoByteReader.byteCatch(fp);
    
    for(int i = 0; i < attributesCount; i++) {
        AttributeInfo * attribute = (AttributeInfo *)calloc(1, sizeof(AttributeInfo));
        //TALVEZ ESTEJA ERRADA ESSA PARTE NAO ESQUECE
        attribute->read(fp,constantPool);
        attributes.push_back(attribute);
    }
}