#ifndef DNA_MVP_DEMO_DNA_H
#define DNA_MVP_DEMO_DNA_H
#include <string>
#include <bitset>
#include <vector>

class DNA_seq {
public:

    explicit DNA_seq(const char *dna_str,std::string name="seq");
    explicit DNA_seq(const std::string &dna_str,std::string name="seq");
    DNA_seq(const DNA_seq &d);
    size_t getMyID(){return my_id;}
    std::string getMyName(){return my_name;}
    friend std::ostream& operator<<(std::ostream &os,const DNA_seq &obj);


    static std::vector<DNA_seq*> database;
    static bool search_in_database(DNA_seq & d1);
    static std::string find_seq_by_name(std::string name);
    std::string switch_bits_to_DNA();

private:

    std::string my_name;
    size_t my_name_id;
    static int curr_name_id;

    size_t my_id;
    static int curr_id;

    size_t m_length;
    std::bitset<500> m_data;
};
#endif //DNA_MVP_DEMO_DNA_H
