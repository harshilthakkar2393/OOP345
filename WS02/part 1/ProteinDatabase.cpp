#include "./ProteinDatabase.h"
using namespace std;
namespace sdds
{
    ProteinDatabase::ProteinDatabase(const std::string fileName)
    {
        int i{};
        std::ifstream fin(fileName);

        // counting number of sequences
        while (fin)
        {
            char x = fin.get();
            if (x == '>')
            {
                noOfSequences++;
            }
        }
        // fin.seekg(0);
        fin.close();
        fin.open(fileName);
        // allocating memory
        sequences = new std::string[noOfSequences];

        // reading and storing values
        while (fin)
        {
            fin.ignore(1000, '\n');
            getline(fin, sequences[i], '>');
            i++;
        }
        fin.close();
    }
    ProteinDatabase::ProteinDatabase(const ProteinDatabase &rightHand)
    {
        *this = rightHand;
    }
    ProteinDatabase &ProteinDatabase::operator=(const ProteinDatabase &rightHand)
    {
        if (this != &rightHand)
        {
            delete[] sequences;
            sequences = nullptr;
            this->sequences = new std::string[rightHand.noOfSequences];
            noOfSequences = rightHand.noOfSequences;
            for (int i = 0; i < noOfSequences; i++)
            {
                sequences[i] = rightHand.sequences[i];
            }
        }
        return *this;
    }
    size_t ProteinDatabase::size() const
    {
        return noOfSequences;
    }
    std::string ProteinDatabase::operator[](size_t size) const
    {
        std::string empty{};
        return (this->size() != 0 && size <= this->size() - 1) ? sequences[size] : empty;
    }
    ProteinDatabase::~ProteinDatabase()
    {
        delete[] sequences;
    }
}