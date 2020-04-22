#include "Field.h"

std::vector<std::byte> toByte(const std::string str){
    std::vector<std::byte> ret;
    for(size_t i = 0; i < str.size(); i++){
        uint8_t x = str.at(i);
        ret.push_back((std::byte)x);
    }
    return ret;
}

std::vector<std::byte> toByte(const int integer){
    std::vector<std::byte> ret;
    ret.push_back((std::byte)integer);
    return ret;
}

int field::getSize(){
    assert(this->data.size() == Type::getSize(this->dataType));
    return 1 + 2 + this->name.size() + 1 + this->data.size();
}

void field::setName(const std::string name){
    assert(this->name.size() < SHRT_MAX);
    this->nameLength = (short)name.size();
    this->name = toByte(name);
}

int field::getBytes(std::vector<std::byte>* dest, int pointer){
    pointer = Serialization::writeBytes(dest, pointer, this->storageType);
    pointer = Serialization::writeBytes(dest, pointer, this->nameLength);
    pointer = Serialization::writeBytes(dest, pointer, this->name);
    pointer = Serialization::writeBytes(dest, pointer, this->dataType);
    pointer = Serialization::writeBytes(dest, pointer, this->data);
    return pointer;
}

field* field::Byte(const std::string name, std::byte* value){
    field* f = new field();
    f->setName(name);
    f->dataType = Type::BYTE;
    Serialization::writeBytes(&f->data, 0, *value);
    return f;
}

field* field::Short(const std::string name, short value){
    field* f = new field();
    f->setName(name);
    f->dataType = Type::SHORT;
    Serialization::writeBytes(&f->data, 0, value);
    return f;
}

field* field::Char(const std::string name, char value){
    field* f =new field();
    f->setName(name);
    f->dataType = Type::CHAR;
    f->data.reserve(Type::getSize(Type::CHAR));
    Serialization::writeBytes(&f->data, 0, value);
    return f;
}

field* field::Int(const std::string name, int value){
    field* f =new field();
    f->setName(name);
    f->dataType = Type::INT;
    Serialization::writeBytes(&f->data, 0, value);
    return f;
}

field* field::Double(const std::string name, double value){
    field* f =new field();
    f->setName(name);
    f->dataType = Type::DOUBLE;
    Serialization::writeBytes(&f->data, 0, value);
    return f;
}

field* field::Boolean(const std::string name, bool value){
    field* f =new field();
    f->setName(name);
    f->dataType = Type::BOOLEAN;
    Serialization::writeBytes(&f->data, 0, value);
    return f;
}

field* field::Int64(const std::string name, int64_t value){
    field* f =new field();
    f->setName(name);
    f->dataType = Type::INT64;
    Serialization::writeBytes(&f->data, 0, value);
    return f;
}