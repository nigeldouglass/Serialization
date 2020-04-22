#include "Array.h"

std::vector<std::byte> toByte(const std::string str){
    std::vector<std::byte> ret;
    for(size_t i = 0; i < str.size(); i++){
        uint8_t x = str.at(i);
        ret.push_back((std::byte)x);
    }
    return ret;
}

void Array::setName(const std::string name){
    assert(this->name.size() < SHRT_MAX);
    this->nameLength = (short)name.size();
    this->name = toByte(name);
}

int Array::getBytes(std::vector<std::byte>* dest, int pointer){
    pointer = Serialization::writeBytes(dest, pointer, this->storageType);
    pointer = Serialization::writeBytes(dest, pointer, this->nameLength);
    pointer = Serialization::writeBytes(dest, pointer, this->name);
    pointer = Serialization::writeBytes(dest, pointer, this->dataType);
    pointer = Serialization::writeBytes(dest, pointer, this->dataCount);
    pointer = Serialization::writeBytes(dest, pointer, this->data);
    return pointer;
}

int Array::getSize(){
    assert(this->data.size() == Type::getSize(this->dataType));
    return 1 + 2 + this->name.size() + 1 + 8 + this->getDataSize();
}

int Array::getDataSize(){
    switch (this->dataType){
        case Type::BYTE:      return this->data.size*Type::getSize(Type::BYTE);
        case Type::SHORT:     return this->data.size*Type::getSize(Type::SHORT);
        case Type::CHAR:      return this->data.size*Type::getSize(Type::CHAR);
        case Type::INT:       return this->data.size*Type::getSize(Type::INT);
        case Type::INT64:     return this->data.size*Type::getSize(Type::INT64);
        case Type::DOUBLE:    return this->data.size*Type::getSize(Type::DOUBLE);
        case Type::BOOLEAN:   return this->data.size*Type::getSize(Type::BOOLEAN);
        default: assert(false);
    }
}

Array* Array::Byte(const std::string name, std::vector<std::byte> value){
    Array* a = new Array();
    a->setName(name);
    a->dataCount = value.size();
    a->dataType = Type::BYTE;
    a->data = value;
    return a;
}

Array* Array::Short(const std::string name, std::vector<short> value){
    Array* a = new Array();
    a->setName(name);
    a->dataCount = value.size();
    a->dataType = Type::SHORT;
    Serialization::writeBytes(&a->data, 0, value);
    return a;
}

Array* Array::Char(const std::string name, std::string value){
    Array* a = new Array();
    a->setName(name);
    a->dataCount = value.size();
    a->dataType = Type::CHAR;
    Serialization::writeBytes(&a->data, 0, value);
    return a;
}

Array* Array::String(const std::string name, std::vector<std::string> value){
    Array* a = new Array();
    a->setName(name);
    a->dataCount = value.size();
    a->dataType = Type::CHAR;
    Serialization::writeBytes(&a->data, 0, value);
    return a;
}

Array* Array::Int(const std::string name, std::vector<int> value){
    Array* a = new Array();
    a->setName(name);
    a->dataCount = value.size();
    a->dataType = Type::INT;
    Serialization::writeBytes(&a->data, 0, value);
    return a;
}

Array* Array::Double(const std::string name, std::vector<double> value){
    Array* a = new Array();
    a->setName(name);
    a->dataCount = value.size();
    a->dataType = Type::DOUBLE;
    Serialization::writeBytes(&a->data, 0, value);
    return a;
}

Array* Array::Boolean(const std::string name, std::vector<bool> value){
    Array* a = new Array();
    a->setName(name);
    a->dataCount = value.size();
    a->dataType = Type::BOOLEAN;
    Serialization::writeBytes(&a->data, 0, value);
    return a;
}

Array* Array::Int64(const std::string name, std::vector<int64_t> value){
    Array* a = new Array();
    a->setName(name);
    a->dataCount = value.size();
    a->dataType = Type::INT64;
    Serialization::writeBytes(&a->data, 0, value);
    return a;
}