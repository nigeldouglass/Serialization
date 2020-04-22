#include "File.h"

void File::save(const std::string file, std::vector<std::byte> data){
    std::ofstream outfile (file);
    outfile.write(reinterpret_cast<char*>(data.data()),data.size());
    outfile.close();
}

std::vector<std::byte> File::load(const std::string file){
    std::vector<std::byte> ret;
    return ret;
}