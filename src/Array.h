#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <assert.h>

#include "storageType.h"
#include "type.h"
#include "Serialization.h"
#include "Utils.h"

class Array{

    public:
        void setName(const std::string name);
        int getBytes(std::vector<std::byte>* dest, int pointer);
        unsigned int getSize();
        int getDataSize();
        static Array* Byte(const std::string name,      std::vector<std::byte> value);
        static Array* Short(const std::string name,     std::vector<short> value);
        static Array* Char(const std::string name,      std::string value);
        static Array* Int(const std::string name,       std::vector<int> value);
        static Array* Double(const std::string name,    std::vector<double> value);
        static Array* Boolean(const std::string name,   std::vector<bool> value);
        static Array* Int64(const std::string name,     std::vector<int64_t> value);
        static Array* String(const std::string name,    std::vector<std::string> value);
    private:
        Array(){};
        std::byte storageType = storageType::ARRAY;
        short nameLength;
        std::vector<std::byte> name;
        std::byte dataType;
        unsigned int dataCount;
        std::vector<std::byte> data;
        unsigned int size;
};

#endif