#ifndef FILE_H
#define FILE_H

#include <filesystem>
#include <fstream> 
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

class File{

    public:
        static void save(const std::string file,      std::vector<std::byte> data);
        static std::vector<std::byte> load(const std::string file);
    private:
};

#endif