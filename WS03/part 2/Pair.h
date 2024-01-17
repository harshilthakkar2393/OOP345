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
#ifndef _SDDS_PAIR_H_
#define _SDDS_PAIR_H_
#include <iostream>

namespace sdds
{

    class Pair
    {
        std::string m_key{};
        std::string m_value{};

    public:
        // ===================================
        // Constructors and Destructors
        // ===================================

        // default constructor
        Pair(){};

        // 2 arg constructor : takes key and value as arguements and assigns to the data members
        Pair(const std::string &key, const std::string &value) : m_key{key}, m_value{value} {};

        // ===================================
        // Public member functions
        // ===================================

        // Returns key
        const std::string &getKey() const { return m_key; }

        // Returns Value
        const std::string &getValue() const { return m_value; }

        // ===================================
        // Operator Overloads
        // ===================================

        // equal to operator
        bool operator==(const Pair &RightHand) const;

        // << operator
        friend std::ostream &operator<<(std::ostream &os, const Pair &p);
    };
}

#endif