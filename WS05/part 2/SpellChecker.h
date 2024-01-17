#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

namespace sdds
{
    class SpellChecker
    {

        std::string m_badWords[6]{};
        std::string m_goodWords[6]{};
        int replaceCount[6]{0};

    public:
        SpellChecker(){};
        SpellChecker(const char *filename);
        void operator()(std::string &text);
        void showStatistics(std::ostream &out) const;
    };

}
#endif