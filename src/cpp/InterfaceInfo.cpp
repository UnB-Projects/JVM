/** @file InterfaceInfo.cpp
 *  @brief Contém métodos para armazenar as interfaces  
 *  @bug No known bugs.
 */
#include "../hpp/InterfaceInfo.hpp"

// InterfaceInfo::~InterfaceInfo() {
//     //Nada alocado dinamicamente
// }

/** @class InterfaceInfo::read
 *  @brief Método que armazena o valor das informações das interfaces
 *  @param fp ponteiro para o arquivo .class
 *  @return
 */
void InterfaceInfo::read(FILE *fp) {
    ByteReader<uint16_t> twoByteReader;
    interfaceIndex = twoByteReader.byteCatch(fp);
}