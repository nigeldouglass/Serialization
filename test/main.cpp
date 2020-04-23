#include "../src/Field.h"
#include "../src/Database.h"
#include "../src/File.h"

#include <iostream>
#include <vector>

int main(){
    fieldExample();
    databaseExample();
}

/*
Basic integer setup and output data.
*/
void fieldExample(){
    //Stream of bytes that will be added to.
    std::vector<std::byte> stream;

    /*  
        Create field object:
        Name: Test
        Integer: 8
    */
    field *f = field::Int("Test", 8);

    //Get field bytes and push to stream object
    f->getBytes(&stream, 0);

    //Output to console the stream of bytes
    Serialization::printBytes(&stream);
}

/*
Array setup and output data.
*/
void arrayExample(){
    //Stream of bytes that will be added to.
    std::vector<std::byte> stream;

    //Array of itegers that we want to save
    std::vector<int> arrayData{ 1, 3, 5, 7};

    /*  
        Create Array object:
        Name: T2
        Data: arrayData
    */
    Array *a = Array::Int("T2", arrayData);

    //Get array bytes and push to stream object
    a->getBytes(&stream, 0);

    //Output to console the stream of bytes
    Serialization::printBytes(&stream);
}

/*
Setup database and add an field and array then save data to file.
*/
void databaseExample(){
    //Stream of bytes that will be added to.
    std::vector<std::byte> stream;

    /*
        Create database object:
        Name: TestDB
    */
    Database* db = new Database("TestDB");
    
    //Create field as per field example and push it to the database
    field *f = field::Int("Test", 8);
    db->push_field(f);

    //Create array as per array example and push it to the database
    std::vector<int> arrayData{ 1, 3, 5, 7};
    Array *a = Array::Int("T2", arrayData);
    db->push_array(a);

    //Get database bytes and push to stream object
    db->getBytes(&stream, 0);

    //Save the stream of bytes to a text file
    File::save("C:\\Users\\Nigel\\Documents\\Serialization\\test\\test.txt", stream);    

}