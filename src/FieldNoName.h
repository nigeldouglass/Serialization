#ifndef FIELD_NO_NAME_H
#define FIELD_NO_NAME_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <assert.h>

#include "storageType.h"
#include "type.h"
#include "Serialization.h"
#include "Utils.h"

std::vector<std::byte> toByte(const std::string str);
std::vector<std::byte> toByte(int integer);

class FieldNoName{

    public:
        int getBytes(std::vector<std::byte>* dest, int pointer);
        int getSize();
        static FieldNoName* Byte(const std::string name, std::byte* value);
        static FieldNoName* Short(const std::string name, short value);
        static FieldNoName* Char(const std::string name, char value);
        static FieldNoName* Int(const std::string name, int value);
        static FieldNoName* Double(const std::string name, double value);
        static FieldNoName* Boolean(const std::string name, bool value);
        static FieldNoName* Int64(const std::string name, int64_t value);
    private:
        FieldNoName(){};
        std::byte storageType = storageType::FIELD;
        short nameLength;
        std::vector<std::byte> name;
        std::byte dataType;
        int64_t elementCount;
        std::vector<std::byte> data;
};

#endif