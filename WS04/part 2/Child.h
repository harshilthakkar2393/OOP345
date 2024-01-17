/*
======================================
 Workshop 4 Part 2
======================================
Module : Child
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

#ifndef SDDS_CHILD_H_
#define SDDS_CHILD_H_
#include <iostream>
#include <string>
#include "Toy.h"

namespace sdds
{
    class Child
    {
        std::string name{};
        int age{0};
        const sdds::Toy **toys{nullptr};
        int noOfToys{0};

    public:
        Child(){};
        Child(std::string name, int age, const Toy *toys[], size_t count);
        Child(const Child &rightHand);
        Child(Child &&rightHand);
        Child &operator=(const Child &rightHand);
        Child &operator=(Child &&rightHand);
        size_t size() const;
        ~Child();
        friend std::ostream &operator<<(std::ostream &os, const Child &rightHand);
    };
}
#endif