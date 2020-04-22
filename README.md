# Serialiazation

## About

Based on the Java series by [The Cherno](https://www.youtube.com/playlist?list=PLlrATfBNZ98cCfmH0xPebdVVMSYRQfyKi) and ported to C++17.

## Usage

    std::vector<std::byte> data;
    field *f = field::Int("Test",8);
    f->getBytes(&data, 0);
    Serialization::printBytes(&data);

> Output: 
> | Output | Denotes | 
> | --- | --- |
> | 0x1 |Type
> | 0x0 |Name Length
> | 0x4 |
> | 0x54| Name
> | 0x65| 
> | 0x73| 
> | 0x74| 
> | 0x4| Data Type
> | 0x0| Data
> | 0x0| 
> | 0x0| 
> | 0x8| 