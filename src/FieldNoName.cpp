#include "FieldNoName.h"

int FieldNoName::getSize(){
    assert(this->data.size() == Type::getSize(this->dataType));
    return 1 + 1 + this->data.size();
}

int FieldNoName::getBytes(std::vector<std::byte>* dest, int pointer){
    pointer = Serialization::writeBytes(dest, pointer, this->storageType);
    pointer = Serialization::writeBytes(dest, pointer, this->dataType);
    pointer = Serialization::writeBytes(dest, pointer, this->data);
    return pointer;
}

FieldNoName* FieldNoName::Byte(const std::string name, std::byte* value){
    FieldNoName* f = new FieldNoName();
    f->dataType = Type::BYTE;
    Serialization::writeBytes(&f->data, 0, *value);
    return f;
}

FieldNoName* FieldNoName::Short(const std::string name, short value){
    FieldNoName* f = new FieldNoName();
    f->dataType = Type::SHORT;
    Serialization::writeBytes(&f->data, 0, value);
    return f;
}

FieldNoName* FieldNoName::Char(const std::string name, char value){
    FieldNoName* f =new FieldNoName();
    f->dataType = Type::CHAR;
    f->data.reserve(Type::getSize(Type::CHAR));
    Serialization::writeBytes(&f->data, 0, value);
    return f;
}

FieldNoName* FieldNoName::Int(const std::string name, int value){
    FieldNoName* f =new FieldNoName();
    f->dataType = Type::INT;
    Serialization::writeBytes(&f->data, 0, value);
    return f;
}

FieldNoName* FieldNoName::Double(const std::string name, double value){
    FieldNoName* f =new FieldNoName();
    f->dataType = Type::DOUBLE;
    Serialization::writeBytes(&f->data, 0, value);
    return f;
}

FieldNoName* FieldNoName::Boolean(const std::string name, bool value){
    FieldNoName* f =new FieldNoName();
    f->dataType = Type::BOOLEAN;
    Serialization::writeBytes(&f->data, 0, value);
    return f;
}

FieldNoName* FieldNoName::Int64(const std::string name, int64_t value){
    FieldNoName* f =new FieldNoName();
    f->dataType = Type::INT64;
    Serialization::writeBytes(&f->data, 0, value);
    return f;
}