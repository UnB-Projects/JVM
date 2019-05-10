#ifndef __INTERFACEINFO_H__
#define __INTERFACEINFO_H__

#include<fstream>
#include<cstdint>

#include "ByteReader.hpp"

class InterfaceInfo {
    public:
        uint16_t interfaceTable;
        ~InterfaceInfo();
        void setInterfaceInfo(FILE*);
};

#endif