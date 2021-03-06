#include "Object.h"

Object::Object(std::string name){
    this->size = 1 + 2 + 0 + 4 + 2 + 2 + 2;
    this->setName(name);
}

void Object::setName(const std::string name){
    assert(this->name.size() < SHRT_MAX);
    this->nameLength = (short)name.size();
    this->name = toByte(name);
    this->size+=this->nameLength;
    this->fieldLength = 0;
    this->fieldNoNameLength = 0;
    this->arrayLength = 0;
}

void Object::push_field(field* field){
    this->fields.push_back(*field);
    this->size+=field->getSize();
    this->fieldLength++;
}

void Object::push_fieldNoName(FieldNoName* field){
    this->fieldNoNames.push_back(*field);
    this->size+=field->getSize();
    this->fieldNoNameLength++;
}

void Object::push_array(Array* array){
    this->arrays.push_back(*array);
    this->size+=array->getSize();
    this->arrayLength++;
}

unsigned int Object::getSize(){
    return this->size;
}

int Object::getBytes(std::vector<std::byte>* dest, int pointer){
    pointer = Serialization::writeBytes(dest, pointer, this->storageType);
    pointer = Serialization::writeBytes(dest, pointer, this->nameLength);
    pointer = Serialization::writeBytes(dest, pointer, this->name);
    pointer = Serialization::writeBytes(dest, pointer, this->getSize());
    pointer = Serialization::writeBytes(dest, pointer, this->fieldLength);
    for(auto& field : this->fields){
        pointer = field.getBytes(dest, pointer);
    }
    pointer = Serialization::writeBytes(dest, pointer, this->fieldNoNameLength);
    for(auto& field : this->fieldNoNames){
        pointer = field.getBytes(dest, pointer);
    }
    pointer = Serialization::writeBytes(dest, pointer, this->arrayLength);
    for(auto& array : this->arrays){
        pointer = array.getBytes(dest, pointer);
    }
    return pointer;
}