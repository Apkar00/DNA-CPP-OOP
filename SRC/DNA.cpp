#include <cstring>
#include <stdexcept>
#include <sstream>
#include "DNA.h"

int DNA_seq::curr_id=1;
int DNA_seq::curr_name_id=1;
std::vector<DNA_seq*> DNA_seq::database;

DNA_seq::DNA_seq(const char *dna_str,std::string name) {

    my_name=name;
    my_id=curr_id++;
    my_name_id=curr_name_id++;
    if (name =="seq") {
        std::string result;
        std::ostringstream convert;
        convert << my_name_id;
        result = convert.str();
        my_name += result;
    }
    /* number of bts necessary to store dna_str as a bitset */
    /* Need 2 bits for every character */
    m_length = strlen(dna_str)*2;

    size_t j=0;
    /* for each base of the DNA sequence */
    for (size_t i=0 ; i < m_length; i+=2)
    {
        switch (dna_str[j])
        {
            case 'A':
                m_data[i]   =  0;
                m_data[i+1] =  0;
                break;
            case 'C':
                m_data[i]   =  0;
                m_data[i+1] =  1;
                break;
            case 'G':
                m_data[i]   =  1;
                m_data[i+1] =  0;
                break;
            case 'T':
                m_data[i]   =  1;
                m_data[i+1] =  1;
                break;
            default:
                throw std::invalid_argument("invalid DNA base");
        }
        j++;
    }
}


DNA_seq::DNA_seq(const std::string &dna_str, std::string name) {

    my_name=name;
    my_name_id=curr_name_id++;
    my_id=curr_id++;

    if (name =="seq") {
        curr_name_id++;
        std::string result;
        std::ostringstream convert;
        convert << my_name_id;
        result = convert.str();
        my_name += result;
    }

    /* number of bts necessary to store dna_str as a bitset */
    m_length = dna_str.length()*2;

    size_t j=0;
    /* for each base of the DNA sequence */
    for (size_t i = 0; i < m_length; i+=2)
    {
        switch (dna_str[j])
        {
            case 'A':
                m_data[i]   =  0;
                m_data[i+1] =  0;
                break;
            case 'C':
                m_data[i]   =  0;
                m_data[i+1] =  1;
                break;
            case 'G':
                m_data[i]   =  1;
                m_data[i+1] =  0;
                break;
            case 'T':
                m_data[i]   =  1;
                m_data[i+1] =  1;
                break;
            default:
                throw std::invalid_argument("invalid DNA base");
        }
        j++;
    }
}

DNA_seq::DNA_seq(const DNA_seq &d)
{
    m_data=d.m_data;
    m_length=d.m_length;
}


std::ostream &operator<<(std::ostream &os, const DNA_seq &obj) {
    for (size_t i = 0; i < obj.m_length; i+=2)
    if(obj.m_data[i]==0&&obj.m_data[i+1]==0)
        os<<'A';
    else if(obj.m_data[i]==0&&obj.m_data[i+1]==1)
        os<<'C';
    else if(obj.m_data[i]==1&&obj.m_data[i+1]==0)
        os<<'G';
    else if(obj.m_data[i]==1&&obj.m_data[i+1]==1)
        os<<'T';
    return os;
}

bool DNA_seq::search_in_database(DNA_seq &d1) {
    std::string curr_name= d1.my_name;
    for(std::vector<DNA_seq>::size_type i = 0; i != database.size(); i++) {
        if (database[i]->my_name == curr_name)
            return true;
    }
    return false;
}

std::string DNA_seq::find_seq_by_name(std::string name) {
    for(std::vector<DNA_seq>::size_type i = 0; i != database.size(); i++) {
        if (database[i]->my_name==name)
            return database[i]->switch_bits_to_DNA();
    }
    return " ";
}

std::string DNA_seq::switch_bits_to_DNA() {
    std:: string output;
    for (size_t i = 0; i < m_length; i+=2)
        if(m_data[i]==0&&m_data[i+1]==0)
            output+= 'A';
        else if(m_data[i]==0&&m_data[i+1]==1)
            output+='C';
        else if(m_data[i]==1&&m_data[i+1]==0)
            output+='G';
        else if(m_data[i]==1&&m_data[i+1]==1)
            output+='T';
    return output;
}
