#include "Serialization.h"

void Serialization::printBytes(const std::vector<std::byte>* data) {
	std::cout << "Printing Bytes" << std::endl;
	for (size_t i = 0; i < data->size();i++) {
		std::cout << "0x" << std::hex << ((int)data->at(i)) << std::endl;
	}
	std::cout << "Finished Printing Bytes" << std::endl;
}

/*
*	Bytes
*/
int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, std::byte value) {
	dest->push_back(value);
	return pointer++;
}

int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<std::byte> value) {
	for (size_t i = 0; i < value.size();i++) {
		pointer = Serialization::writeBytes(dest, pointer, value[i]);
	}
	return pointer;
}

/*
*	Char
*/
int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, char value) {
	for (size_t i = 0; i < std::strlen(&value); i++) {
		dest->push_back((std::byte)value[&i]);
		pointer++;
	}
	return pointer;
}

/*
*	Short
*/
int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, short value) {
	dest->push_back((std::byte)((value >> 8) & 0xff));
	pointer++;
	dest->push_back((std::byte)((value >> 0) & 0xff));
	pointer++;
	return pointer;
}

int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<short> value) {
	for(size_t i = 0; i<value.size();i++){
		pointer = Serialization::writeBytes(dest, pointer, value.at(i));
	}
	return pointer;
}

/*
*	Int
*/
int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, int value) {
	dest->push_back((std::byte)((value >> 24) & 0xff));
	pointer++;
	dest->push_back((std::byte)((value >> 16) & 0xff));
	pointer++;
	dest->push_back((std::byte)((value >> 8) & 0xff));
	pointer++;
	dest->push_back((std::byte)((value >> 0) & 0xff));
	pointer++;
	return pointer;
}

int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<int> value) {
	for(size_t i = 0; i<value.size();i++){
		pointer = Serialization::writeBytes(dest, pointer, value.at(i));
	}
	return pointer;
}

int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, unsigned int value) {
	pointer = Serialization::writeBytes(dest, pointer, (int)value);
	return pointer;
}

int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<unsigned int> value) {
	for(size_t i = 0; i<value.size();i++){
		pointer = Serialization::writeBytes(dest, pointer, (int)value.at(i));
	}
	return pointer;
}

/*
*	Int64
*/
int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, int64_t value) {
	dest->push_back((std::byte)((value >> 56) & 0xff));
	pointer++;
	dest->push_back((std::byte)((value >> 48) & 0xff));
	pointer++;
	dest->push_back((std::byte)((value >> 40) & 0xff));
	pointer++;
	dest->push_back((std::byte)((value >> 32) & 0xff));
	pointer++;
	dest->push_back((std::byte)((value >> 24) & 0xff));
	pointer++;
	dest->push_back((std::byte)((value >> 16) & 0xff));
	pointer++;
	dest->push_back((std::byte)((value >> 8) & 0xff));
	pointer++;
	dest->push_back((std::byte)((value >> 0) & 0xff));
	pointer++;
	return pointer;
}

int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<int64_t> value) {
	for(size_t i = 0; i<value.size();i++){
		pointer = Serialization::writeBytes(dest, pointer, value.at(i));
	}
	return pointer;
}

/*
*	Double
*/
int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, double value) {
	//int64_t doub = value;
	//return Serialization::writeBytes(dest, pointer, doub);
	return 0;
}

/*
*	Bool
*/
int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, bool value) {
	dest->push_back((std::byte)(value ? 1 : 0));
	return pointer++;
}

int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<bool> value) {
	for(size_t i = 0; i<value.size();i++){
		pointer = Serialization::writeBytes(dest, pointer, value.at(i));
	}
	return pointer;
}

/*
*	String
*/
int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, std::string value) {
	pointer = Serialization::writeBytes(dest, pointer, (short)value.length());
	return Serialization::writeBytes(dest, pointer, value.c_str());
}

int Serialization::writeBytes(std::vector<std::byte>* dest, int pointer, std::vector<std::string> value) {
	for(size_t i = 0; i<value.size();i++){
		pointer = Serialization::writeBytes(dest, pointer, value.at(i));
	}
	return pointer;
}

std::byte Serialization::readByte(std::vector<std::byte> src, int pointer) {
	return src[pointer];
}

char Serialization::readChar(std::vector<std::byte> src, int pointer) {
	return (char)(src[pointer + 2] << 8 | src[pointer + 3] << 0);
}

short Serialization::readShort(std::vector<std::byte> src, int pointer) {
	return (short)(src[pointer + 2] << 8 | src[pointer + 3] << 0);
}

int Serialization::readInt(std::vector<std::byte> src, int pointer) {
	return (int)(src[pointer] << 24 | src[pointer + 1] << 16 | src[pointer + 2] << 8 | src[pointer + 3] << 0);
}

int64_t Serialization::readInt64(std::vector<std::byte> src, int pointer) {
	return (int)(src[pointer] << 56 | src[pointer] << 48 | src[pointer] << 40 | src[pointer] << 32 | src[pointer] << 24 | src[pointer + 1] << 16 | src[pointer + 2] << 8 | src[pointer + 3] << 0);
}

