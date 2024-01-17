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
#include "Professor.h"
using namespace std;
namespace sdds
{
    // 1 arg constructor : reads data from the passed stream and stores into member variables
    Professor::Professor(std::istream &in) : Employee(in)
    {
        int j = 0;
        std::string proxyString{};
        getline(in, proxyString, '\n');
        j = proxyString.length() - 1;
        while (j >= 0 && proxyString[j] == ' ') // removing trailing spaces
        {
            proxyString.erase(j, 1);
            j--;
        }
        j = 0;
        while (proxyString[j] == ' ') // removing leading spaces
        {
            proxyString.erase(j, 1);
        }
        m_department = proxyString;
    }
    // displays the professor object 
    void Professor::display(std::ostream &out) const
    {
        Employee::display(out);
        out << m_department;
        out << "| " << this->status();
    }
    std::string Professor::status() const
    {
        return "Professor";
    }
    std::string Professor::department() const
    {
        return m_department;
    }
}