// Name: Harshil Dineshbhai Thakkar
// Seneca Student ID: 160431219
// Seneca email: hthakkar8@myseneca.ca
// Date of completion: 21-03-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>
#include <iomanip>
#include "Utilities.h"
namespace sdds
{
    class Station
    {
        int stationId{0};
        std::string itemName{};
        std::string description{};
        unsigned int serialNumber{};
        unsigned int noOfItems{};
        static size_t m_widthField;
        static unsigned int id_generator;

    public:
        Station(){};
        Station(const std::string str);
        const std::string &getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream &os, bool full) const;
    };

}
#endif