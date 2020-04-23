#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <assert.h>

#include "storageType.h"
#include "Field.h"
#include "Array.h"
#include "Object.h"
#include "Utils.h"

class Database{

    public:
        Database(std::string name);
        void push_field(field* field);
        void push_array(Array* array);
        void push_object(Object* object);
        unsigned int getSize();
        int getBytes(std::vector<std::byte>* dest, int pointer);
    private:
        std::vector<std::byte> HEADER;
        void setName(std::string name);
        std::byte storageType = storageType::DATABASE;
        short nameLength;
        std::vector<std::byte> name;
        short fieldLength;
        std::vector<field> fields;
        short arrayLength;
        std::vector<Array> arrays;
        short objectLength;
        std::vector<Object> objects;
        unsigned int size;
};

#endif