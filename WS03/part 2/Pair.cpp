/*
======================================
 Workshop 3 Part 2
======================================
Module : Pair
-------------------------------------
Name: Harshil Dineshbhai Thakkar
Student ID: 160431219
Student Email: hthakkar8@myseneca.ca
Date: 05/02/2023
Section: NEE
-------------------------------------
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
======================================
*/
#include <iostream>
#include "Pair.h"

using namespace std;

namespace sdds
{

    // ===================================
    // Operator Overloads
    // ===================================

    // equal to operator
    bool Pair::operator==(const Pair &RightHand) const
    {
        return m_key == RightHand.m_key ? true : false;
    }

    // << operator
    std::ostream &operator<<(std::ostream &os, const Pair &p)
    {
        os.width(20);
        os << p.getKey();
        os << ": " << p.getValue();
        return os;
    }
}