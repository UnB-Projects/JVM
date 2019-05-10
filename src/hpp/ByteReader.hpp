#ifndef __BYTEREADER_H__
#define __BYTEREADER_H__

#include <fstream>

template <class T>

class ByteReader {
    public:
    T byteCatch(FILE *fp);
};

#endif