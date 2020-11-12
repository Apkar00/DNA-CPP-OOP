#ifndef DNA_MVP_DEMO_DNACREATE_H
#define DNA_MVP_DEMO_DNACREATE_H
#include "DNA.h"

class DnaCreate: DNA_seq{
public:
    DNA_seq dna;
    void createDNA(std::string seq, std::string name);
    void duplicateDNA(std::string existing_seq,std::string new_seq);
    void duplicateDNA(int seq_id);


};
#endif //DNA_MVP_DEMO_DNACREATE_H
