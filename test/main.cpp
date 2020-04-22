#include "../src/Field.h"
#include <iostream>
#include <vector>

int main(){
    integer();
}

void integer(){
    field *f = field::Int("Test", 8);
    std::vector<std::byte> data;
    f->getBytes(&data, 0);
    Serialization::printBytes(&data);
}