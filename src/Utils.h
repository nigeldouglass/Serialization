#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

inline std::vector<std::byte> toByte(const std::string str) {
    std::vector<std::byte> ret;
    for (size_t i = 0; i < str.size(); i++) {
        uint8_t x = str.at(i);
        ret.push_back((std::byte)x);
    }
    return ret;
}

inline std::vector<std::byte> toByte(const int integer) {
    std::vector<std::byte> ret;
    ret.push_back((std::byte)integer);
    return ret;
}
#endif