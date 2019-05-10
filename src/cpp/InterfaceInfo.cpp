#include "../hpp/InterfaceInfo.hpp"

InterfaceInfo::~InterfaceInfo() {
    //Nada alocado dinamicamente
}

void InterfaceInfo::setInterfaceInfo(FILE *fp) {
    ByteReader<uint16_t> twoBytes;
    interfaceTable = twoBytes.byteCatch(fp);
}