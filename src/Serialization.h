#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <assert.h>

#include "type.h"

class Serialization{

    public:
        inline static const char HEADER[] = {0x44, 0x42};
        inline static const short VERSION = 0x0001;

        static void printBytes(const std::vector<std::byte>* data);

        static int writeBytes(std::vector<std::byte>* dest, int pointer, std::byte value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<std::byte> value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, char value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, short value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<short> value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, int value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<int> value);
                static int writeBytes(std::vector<std::byte>* dest, int pointer, unsigned int value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<unsigned int> value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, int64_t value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<int64_t> value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, double value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, bool value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<bool> value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, std::string value);
        static int writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<std::string> value);

        static std::byte readByte(std::vector<std::byte> src, int pointer);
        static char readChar(std::vector<std::byte> src, int pointer);
        static short readShort(std::vector<std::byte> src, int pointer);
        static int readInt(std::vector<std::byte> src, int pointer);
        static int64_t readInt64(std::vector<std::byte> src, int pointer);

    private:
};

#endif