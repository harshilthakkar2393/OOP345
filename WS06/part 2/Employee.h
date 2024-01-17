/*
======================================
 Workshop 6 Part 2
======================================
Module : Employee
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
#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
#include <iostream>
#include "Person.h"
namespace sdds
{
    class Employee : public Person
    {
        std::string m_name{};
        std::string m_age{};
        std::string m_id{};

    public:
        Employee(){};
        Employee(std::istream &is);
        std::string status() const;
        std::string name() const;
        std::string id() const;
        std::string age() const;
        void display(std::ostream& out) const; 
    };
}
#endif