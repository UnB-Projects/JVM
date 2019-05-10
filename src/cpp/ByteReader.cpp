#include "../hpp/ByteReader.hpp"

#define NEUTRAL_BYTE_FOR_OR 0x00

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