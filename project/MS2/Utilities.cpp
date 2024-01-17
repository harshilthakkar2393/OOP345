// Name: Harshil Dineshbhai Thakkar
// Seneca Student ID: 160431219
// Seneca email: hthakkar8@myseneca.ca
// Date of completion: 21-03-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
using namespace std;
namespace sdds
{
    char Utilities::m_delimiter = ',';
    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }
    size_t Utilities::getFieldWidth() const
    {
        return m_widthField;
    }
    std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more)
    {
        std::string proxyString{};
        size_t dlPos{};
        int j = 0;
        more = false;
        dlPos = str.find(Utilities::getDelimiter(), next_pos); // finding first token
        if(dlPos>str.size())
        {
            dlPos=str.size();
        }
        if (dlPos != size_t(-1))
        {
            if (dlPos == next_pos)
            {
                throw "error";
            }
            else
            {
                proxyString = str.substr(next_pos, dlPos - next_pos);
                j = proxyString.length() - 1;
                while (j >= 0 && proxyString[j] == ' ') // removing trailing spaces
                {
                    proxyString.erase(j, 1);
                    j--;
                }
                j = 0;
                while (proxyString[j] == ' ') // removing leading spaces
                {
                    proxyString.erase(j, 1);
                }
                next_pos += (dlPos - next_pos);
                next_pos++;
                if(next_pos< str.length())
                {
                    more=true;
                }
                if (m_widthField < proxyString.size())
                {
                    m_widthField = proxyString.size();
                }
            }
        }
        return proxyString;
    }
    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }
    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }
}