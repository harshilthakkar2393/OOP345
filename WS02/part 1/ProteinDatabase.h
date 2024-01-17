#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_
#include <iostream>
#include <fstream>

namespace sdds
{
    class ProteinDatabase
    {
        std::string *sequences{};
        int noOfSequences{0};

    public:
        ProteinDatabase(){};
        ProteinDatabase(const std::string fileName);
        ProteinDatabase(const ProteinDatabase &rightHand);
        ProteinDatabase &operator=(const ProteinDatabase &rightHand);
        size_t size() const;
        std::string operator[](size_t) const;
        ~ProteinDatabase();
    };
}

#endif