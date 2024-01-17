// Name: Harshil Dineshbhai Thakkar
// Seneca Student ID: 160431219
// Seneca email: hthakkar8@myseneca.ca
// Date of completion: 21-03-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Station.h"
using namespace std;
namespace sdds
{
    size_t Station::m_widthField = 0;
    unsigned int Station::id_generator = 0;
    Station::Station(const std::string str)
    {
        stationId = ++id_generator;
        Utilities temp{};
        size_t next_pos = 0;
        bool more = false;

        itemName = temp.extractToken(str, next_pos, more);
        if (more)
        {
            try
            {

                serialNumber = std::stoi(temp.extractToken(str, next_pos, more));
            }
            catch (...)
            {
                serialNumber = 0;
            }
        }
        if (more)
        {
            try
            {

                noOfItems = std::stoi(temp.extractToken(str, next_pos, more));
            }
            catch (...)
            {
            }
        }
        if (more)
        {
            m_widthField = this->m_widthField < temp.getFieldWidth() ? temp.getFieldWidth() : this->m_widthField;
            description = temp.extractToken(str, next_pos, more);
        }

    }
    const std::string &Station::getItemName() const
    {
        return itemName;
    }
    size_t Station::getNextSerialNumber()
    {
        return serialNumber++;
    }
    size_t Station::getQuantity() const
    {
        return noOfItems;
    }
    void Station::updateQuantity()
    {
        if (noOfItems > 0)
        {
            noOfItems--;
        }
    }
    void Station::display(std::ostream &os, bool full) const
    {
        os << setw(3) <<setfill('0')<<right<< stationId << " | ";
        os << setw(Station::m_widthField)<<setfill(' ') <<left<< itemName << "  | ";
        os << setw(6)<<setfill('0') <<right<< serialNumber <<setfill(' ')<< " | ";
        if (full)
        {
            os << right<<setw(4) << noOfItems << " | ";
            os << description;
        }
        os << endl;
    }
}