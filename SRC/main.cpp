#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "DNA.h"
#include "DnaRead.h"
void process(std::string const & line){

    std::istringstream iss(line);
    std::vector<std::string> result;
    for(std::string s;iss>>s;)
        result.push_back(s);
    int n=result.size();

    for(int i=0;i<n;i++)
    {
        if (result[i] == "load"){
            FileReader f;
            f.loadFromFile(result[i+1], result[i+2]);
            break;
        }
        if (result[i]=="new") {
            if (n == 3) {
                DNA_seq d1(result[i + 1], result[i + 2]);
                DNA_seq::database.push_back(&d1);
                std::cout << "[" << d1.getMyID() << "]" << " " << d1.getMyName() << " " << d1 << std::endl;
            } else {
                DNA_seq d2(result[i + 1], "seq");
                DNA_seq::database.push_back(&d2);
                std::cout << "[" << d2.getMyID() << "]" << " " << d2.getMyName() << " " << d2
                          << std::endl;
            }
            break;
        }
        if (result[i]=="dup") {
            if (n == 3) {
                if (DNA_seq::search_in_database(reinterpret_cast<DNA_seq &>(result[i + 1]))) {
                    std::string my_seq = DNA_seq::find_seq_by_name(result[i + 1]);
                    DNA_seq d1((my_seq + my_seq), result[i + 2]);
                    DNA_seq::database.push_back(&d1);
                    std::cout << "[" << d1.getMyID() << "]" << " " << d1.getMyName() << " " << d1 << std::endl;
                }
            } else { ;/*if no name was given create a name from seq to be duplicated */
            }
            break;
        }
    }
}

int main(int argc, char * argv[]) {
    for (std::string line; std::cout << "> cmd >>> " && std::getline(std::cin, line); )
    {
        if (!line.empty()) {
            process(line);
            if (line == "quit" || line == "exit")
                break;
        }
    }

    std::cout << "Goodbye.\n";
    return 0;
}
