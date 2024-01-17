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
#include "Employee.h"

using namespace std;
namespace sdds
{
    // 1 arg constructor : reads data from the passed stream and stores into member variables
    Employee::Employee(std::istream &is)
    {
        bool valid = true;
        char c{};
        int j = 0;
        std::string proxyString{};
        for (int i = 0; i < 3; i++) //reading from the stream
        {
            proxyString.clear();
            valid = true;
            while (valid && is)//extracting comma separated values  
            {
                c = is.get();
                if (c == '\n' || c == ',' || c == -1)
                {
                    valid = false;
                }
                else
                {
                    proxyString += c;
                }
            }
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

            switch (i)
            {
            case 0:
            {
                // setting name
                m_name = proxyString;
                break;
            }
            case 1:
            {
                // setting age
                m_age = proxyString;
                break;
            }
            case 2:
            {
                // setting employee id
                if (proxyString[0] == 'e' || proxyString[0] == 'E')// checking if id is valid
                {
                    m_id = proxyString;
                }
                else
                {
                    std::string message = m_name + "++Invalid record!";
                    throw message;
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
    std::string Employee::status() const
    {
        return "Employee";
    }
    std::string Employee::name() const
    {
        return m_name;
    }
    std::string Employee::id() const
    {
        return m_id;
    }
    std::string Employee::age() const
    {
        return m_age;
    }
    // displays the employee object 
    void Employee::display(std::ostream &out) const
    {
        out.setf(ios::left);
        out << "| ";
        out.width(10);
        out << "Employee";
        out << "| ";
        out.width(10);
        out << m_id;
        out << "| ";
        out.width(20);
        out << m_name;
        out << " | ";
        out.width(3);
        out << m_age;
        out << " |";
        out.unsetf(ios::left);
    }
}