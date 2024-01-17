/*
======================================
 Workshop 6 Part 2
======================================
Module : Professor
-------------------------------------
Name: Harshil Dineshbhai Thakkar
Student ID: 160431219
Student Email: hthakkar8@myseneca.ca
Date: 11/03/2023
Section: NEE
-------------------------------------
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
======================================
*/
#ifndef SDDS_PROFESSOR_H_
#define SDDS_PROFESSOR_H_
#include <iostream>
#include "Employee.h"
namespace sdds
{
    class Professor : public Employee
    {
        std::string m_department{};

    public:
        Professor(){};
        Professor(std::istream &in);
        void display(std::ostream &out) const;
        std::string status() const;
        std::string department() const;
    };
}
#endif