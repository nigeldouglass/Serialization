#include "Object.h"

std::vector<std::byte> toByte(const std::string str){
    std::vector<std::byte> ret;
    for(size_t i = 0; i < str.size(); i++){
        uint8_t x = str.at(i);
        ret.push_back((std::byte)x);
    }
    return ret;
}

Object::Object(std::string name){
    this->size = 1 + 2 + 0 + 2 + 2;
    this->setName(name);
}

void Object::setName(const std::string name){
    assert(this->name.size() < SHRT_MAX);
    this->nameLength = (short)name.size();
    this->name = toByte(name);
    this->size+=this->nameLength;
}

void Object::push_field(field field){
    this->fields.push_back(field);
    this->size+=field.getSize();
    this->fieldLength++;
}

void Object::push_array(Array array){
    this->arrays.push_back(array);
    this->size+=array.getSize();
    this->arrayLength++;
}

int Object::getSize(){
    this->size;
}

int Object::getBytes(std::vector<std::byte>* dest, int pointer){
    pointer = Serialization::writeBytes(dest, pointer, this->storageType);
    pointer = Serialization::writeBytes(dest, pointer, this->nameLength);
    pointer = Serialization::writeBytes(dest, pointer, this->name);
    pointer = Serialization::writeBytes(dest, pointer, this->fieldLength);
    for(auto& field : this->fields){
        pointer = field.getBytes(dest, pointer);
    }
    pointer = Serialization::writeBytes(dest, pointer, this->arrayLength);
    for(auto& array : this->arrays){
        pointer = array.getBytes(dest, pointer);
    }
    return pointer;
}