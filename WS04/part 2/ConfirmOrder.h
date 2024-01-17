/*
======================================
 Workshop 4 Part 2
======================================
Module : ConfirmOrder
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
#ifndef SDDS_CONFIRMORDER_H_
#define SDDS_CONFIRMORDER_H_
#include <iostream>
#include <string>
#include "Toy.h"

namespace sdds
{
    class ConfirmOrder
    {
        const Toy **toys{nullptr};
        int noOfToys{0};

    public:
        ConfirmOrder(){};
        ConfirmOrder(const ConfirmOrder &rightHand);
        ConfirmOrder(ConfirmOrder &&rightHand);
        ConfirmOrder &operator=(const ConfirmOrder &rightHand);
        ConfirmOrder &operator=(ConfirmOrder &&rightHand);
        ConfirmOrder& operator+=(const Toy& toy);
        ConfirmOrder& operator-=(const Toy& toy);
        size_t size() const;
        int findIndex(const Toy& toy);
        ~ConfirmOrder();
        friend std::ostream &operator<<(std::ostream &os, const ConfirmOrder &rightHand);
    };
}

#endif