#include "DnaRead.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>

void FileReader::loadFromFile(std::string filename, std::string seq_name) {

    if (seq_name.empty()){
        seq_name = filename;
        size_t find = seq_name.find('.');
        seq_name.erase(find);
    }

    std::ifstream my_file(filename.c_str());

    std::string lines;

    while (getline(my_file, lines)) {
        std::istringstream buf(lines);
        std::string id;
        std::string name;
        std::string DNA;
        buf >> id  >> name >> DNA;

        if (name == seq_name){
            if (DNA.length()>40) {
                DNA.erase(32);
                DNA.push_back('.');
                DNA.push_back('.');
                DNA.push_back('.');
                std::cout << id << " " << name << " " << " " << DNA << std::endl;
            }
            else std::cout << lines << std::endl;
        }
    }
}