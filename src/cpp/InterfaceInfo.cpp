#include "../hpp/InterfaceInfo.hpp"

InterfaceInfo::~InterfaceInfo() {
    //Nada alocado dinamicamente
}

void InterfaceInfo::read(FILE *fp) {
    ByteReader<uint16_t> twoByteReader;
    interfaceIndex = twoByteReader.byteCatch(fp);
}