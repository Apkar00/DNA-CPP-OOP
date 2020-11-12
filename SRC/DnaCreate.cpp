#include "DnaCreate.h"
#include <iostream>

void DnaCreate::createDNA(std::string seq, std::string name) {
 DNA_seq d1(seq,name);
 DNA_seq::database.push_back(&d1);
 std::cout << "[" << d1.getMyID() << "]" << " " << d1.getMyName() << " " << d1 << std::endl;
}

void DnaCreate::duplicateDNA(std::string existing_seq, std::string new_seq) {
    std::string my_seq=DNA_seq::find_seq_by_name(existing_seq);
    DNA_seq d1((my_seq+my_seq),new_seq);
    DNA_seq::database.push_back(&d1);
    std::cout << "[" << d1.getMyID() << "]" << " " << d1.getMyName() << " " << d1 << std::endl;
}

void DnaCreate::duplicateDNA(int seq_id) {
;
}

