#include "Database.h"

Database::Database(std::string name){
    this->HEADER = toByte("DB");
    //HEADER + Type + nameLenght + name + size + fieldSize + arraySize + objectSize
    this->size = 2 + 1 + 2 + 0 + 4 + 2 + 2 + 2;
    this->setName(name);
}

void Database::setName(const std::string name){
    assert(this->name.size() < SHRT_MAX);
    this->nameLength = (short)name.size();
    this->name = toByte(name);
    this->size+=this->nameLength;
}

void Database::push_field(field* field){
    this->fields.push_back(*field);
    this->size+=field->getSize();
    this->fieldLength++;
}

void Database::push_array(Array* array){
    this->arrays.push_back(*array);
    this->size+=array->getSize();
    this->arrayLength++;
}

void Database::push_object(Object* object){
    this->objects.push_back(*object);
    this->size+=object->getSize();
    this->objectLength++;
}

unsigned int Database::getSize(){
    return this->size;
}

int Database::getBytes(std::vector<std::byte>* dest, int pointer){
    pointer = Serialization::writeBytes(dest, pointer, this->HEADER);
    pointer = Serialization::writeBytes(dest, pointer, this->storageType);
    pointer = Serialization::writeBytes(dest, pointer, this->nameLength);
    pointer = Serialization::writeBytes(dest, pointer, this->name);
    pointer = Serialization::writeBytes(dest, pointer, this->getSize());
    pointer = Serialization::writeBytes(dest, pointer, this->fieldLength);
    for(auto& field : this->fields){
        pointer = field.getBytes(dest, pointer);
    }
    pointer = Serialization::writeBytes(dest, pointer, this->arrayLength);
    for(auto& array : this->arrays){
        pointer = array.getBytes(dest, pointer);
    }
    pointer = Serialization::writeBytes(dest, pointer, this->objectLength);
    for(auto& object : this->objects){
        pointer = object.getBytes(dest, pointer);
    }
    
    return pointer;
}