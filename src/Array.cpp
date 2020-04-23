#include "Array.h"

void Array::setName(const std::string name){
    assert(this->name.size() < SHRT_MAX);
    this->size = 1 + 2 + 0 + 4 + 1 + 4;
    this->nameLength = (short)name.size();
    this->name = toByte(name);
    this->size += this->name.size();
}

int Array::getBytes(std::vector<std::byte>* dest, int pointer){
    pointer = Serialization::writeBytes(dest, pointer, this->storageType);
    pointer = Serialization::writeBytes(dest, pointer, this->nameLength);
    pointer = Serialization::writeBytes(dest, pointer, this->name);
    pointer = Serialization::writeBytes(dest, pointer, this->getSize());
    pointer = Serialization::writeBytes(dest, pointer, this->dataType);
    pointer = Serialization::writeBytes(dest, pointer, this->dataCount);
    pointer = Serialization::writeBytes(dest, pointer, this->data);
    return pointer;
}

unsigned int Array::getSize(){
    //Type + namelenght + name + size + dataType + dataCount + data
    return this->size+this->getDataSize();
}

int Array::getDataSize(){
    return this->data.size();
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
    //Serialization::writeBytes(&a->data, 0, value);
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