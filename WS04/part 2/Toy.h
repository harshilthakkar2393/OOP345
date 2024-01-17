/*
======================================
 Workshop 4 Part 2
======================================
Module : Toy
-------------------------------------
Name: Harshil Dineshbhai Thakkar
Student ID: 160431219
Student Email: hthakkar8@myseneca.ca
Date: 12/02/2023
Section: NEE
-------------------------------------
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
======================================
*/

#ifndef SDDS_TOY_H_
#define SDDS_TOY_H_
#include <iostream>
namespace sdds
{
    class Toy
    {
        unsigned int orderId{};
        std::string name{};
        int noOfItems{};
        double price{};
        const double hst{0.13};

    public:
        Toy(){};
        Toy(const std::string &toy);
        void update(int numItems);
        friend std::ostream &operator<<(std::ostream &os, const Toy &rightHand);
    };
}
#endif