/*
======================================
 Workshop 3 Part 2
======================================
Module : Set
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
#ifndef _SDDS_SET_H_
#define _SDDS_SET_H_
#include <iostream>
#include "Collection.h"
namespace sdds
{
    template <class T>
    class Set : public Collection<T, 100>
    {
    public:
        // Adds new element to array only if doesnt exist already
        bool add(const T &item)
        {
            bool found = false;
            for (int i = 0; i < Collection<T, 100>::size() && !found; i++)
            {
                if ((*this)[i] == item) // checking if item already exists
                {
                    found = true;
                }
            }
            return found ? false : Collection<T, 100>::add(item);
        }
    };

    // Specialization: add function for diuble data type
    template <>
    bool Set<double>::add(const double &item)
    {
        bool found = false;
        for (int i = 0; i < Collection<double, 100>::size() && !found; i++)
        {
            // checking if item already exists
            if (abs((*this)[i] - item) <= 0.01) // considering numbers to be equal if difference between them is less than 0.01
            {
                found = true;
            }
        }
        return found ? false : Collection<double, 100>::add(item);
    }
}
#endif