#ifndef DNA_MVP_DEMO_DNAREAD_H
#define DNA_MVP_DEMO_DNAREAD_H
#include <string>

class FileReader{
public:
    void loadFromFile(std::string filename, std::string seq_name="");

};
#endif //DNA_MVP_DEMO_DNAREAD_H
