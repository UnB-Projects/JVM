/** @file InterfaceInfo.hpp
 *  @brief Contém o armazenamento das informações das interfaces  
 *  @bug No known bugs.
 */
#ifndef __INTERFACEINFO_H__
#define __INTERFACEINFO_H__

#include <fstream>
#include <cstdint>
#include "ByteReader.hpp"

/** @class InterfaceInfo
*   @brief Classe que contém toda a estrutura das interfaces do .class
*   @bug No known bugs.
*/

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