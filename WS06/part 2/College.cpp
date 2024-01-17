/*
======================================
 Workshop 6 Part 2
======================================
Module : College
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
#include "College.h"
using namespace std;
namespace sdds
{
    // adds the person passed as arguement to the m_persons array
    College &College::operator+=(Person *thePerson)
    {
        m_persons.push_back(thePerson);
        return *this;
    }

    // Displays the m_persons
    void College::display(std::ostream &out) const
    {
        std::vector<Person *>::iterator it{};
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        out << "|                                        Test #1 Persons in the college!                                               |" << endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        for (auto it = m_persons.begin(); it != m_persons.end(); it++)
        {
            (*it)->display(out);
            out << endl;
        }
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        out << "|                                        Test #2 Persons in the college!                                               |" << endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        for (auto it = m_persons.begin(); it != m_persons.end(); it++)
        {
            out.setf(ios::left);
            out << "| ";
            out.width(10);
            out << (*it)->status();
            out << "| ";
            out.width(10);
            out << (*it)->id();
            out << "| ";
            out.width(20);
            out << (*it)->name();
            out << " | ";
            out.width(3);
            out << (*it)->age();
            out << " |" << endl;
            out.unsetf(ios::left);
        }
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }

    // destructor
    College::~College()
    {
        // deallocates the dynamically allocated memory
        for (auto it = m_persons.begin(); it != m_persons.end(); it++)
        {
            delete (*it);
            (*it) = nullptr;
        }
    }
}