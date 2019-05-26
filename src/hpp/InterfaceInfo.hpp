#ifndef __INTERFACEINFO_H__
#define __INTERFACEINFO_H__

#include <fstream>
#include <cstdint>
#include "ByteReader.hpp"

class InterfaceInfo {
private:
    uint16_t interfaceIndex;
    ~InterfaceInfo();
public:
    void read(FILE *fp);
    uint16_t getInterfaceIndex() {
        return interfaceIndex;
    }
};

#endif