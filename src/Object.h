#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <assert.h>

#include "storageType.h"
#include "Field.h"
#include "Array.h"

class Object{

    public:
        Object(std::string name);
        void push_field(field field);
        void push_array(Array array);
        int getSize();
        int getBytes(std::vector<std::byte>* dest, int pointer);
    private:
        void setName(std::string name);
        std::byte storageType = storageType::OBJECT;
        short nameLength;
        std::vector<std::byte> name;
        short fieldLength;
        std::vector<field> fields;
        short arrayLength;
        std::vector<Array> arrays;
        int size;
};

#endif