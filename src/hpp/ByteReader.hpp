/** @file ByteReader.hpp
 *  @brief Declarações das funções do ByteReader para leitura dos bytes no arquivo .class.
 *  @bug No known bugs.
 */
#ifndef __BYTEREADER_H__
#define __BYTEREADER_H__

#include <fstream>
#define NEUTRAL_BYTE_FOR_OR 0x00

template <class T>

/** @class ByteReader
*   @brief Contém o método byteCatch - busca fazer a leitura dos bytes do .class;
*   @bug No known bugs.
*/

class ByteReader {
    public:
    T byteCatch(FILE *fp);
};

/** @class ByteReader<T>::byteCatch
 * @brief byteCatch(FILE * fp) busca o binário correspondendo ao tipo T.
 * @param FILE * fp : arquivo de acesso.
 * @return T
 */
template <class T>
T ByteReader<T>::byteCatch(FILE * fp) {
    int num_of_bytes = sizeof(T);
    T toReturn = NEUTRAL_BYTE_FOR_OR;
    toReturn = getc(fp);
    if (num_of_bytes > 1) {
        for (int i = 0; i < num_of_bytes - 1; i++) {
            toReturn = ((toReturn << 8 ) | getc(fp));
        }
    }
    return toReturn;
}

#endif