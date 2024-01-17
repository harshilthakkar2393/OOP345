/*
======================================
 Workshop 6 Part 2
======================================
Module : Student
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
#include "Student.h"
using namespace std;
namespace sdds
{
    // 1 arg constructor : reads data from the passed stream and stores into member variables
    Student::Student(std::istream &in)
    {
        bool valid = true;
        char c{};
        int j = 0;
        int k = 0;
        bool flag = true;
        std::string proxyString{};
        for (int i = 0; in && flag; i++) // reading from the stream
        {
            proxyString.clear();
            valid = true;
            while (valid && in) // extracting comma separated values
            {
                c = in.get();
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
                try
                {

                    std::stoi(proxyString);
                    m_age = proxyString;
                }
                catch (std::invalid_argument const &ex)
                {
                    in.ignore(1000, '\n');
                    std::string message = m_name + "++Invalid record!";
                    throw message;
                }
                break;
            }
            case 2:
            {

                // setting id
                if (proxyString[0] == 's' || proxyString[0] == 'S')
                {
                    m_id = proxyString;
                }
                else
                {
                    in.ignore(1000, '\n');
                    std::string message = m_name + "++Invalid record!";
                    throw message;
                }
                break;
            }
            case 3:
            {
                // setting no of cources
                std::size_t pos{};
                try
                {

                    m_count = std::stoi(proxyString, &pos);
                    m_courses = new std::string[m_count];
                }
                catch (std::invalid_argument const &ex)
                {
                    std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
                }
                break;
            }
            default:
            {
                // extracting the courses
                if (i > 3)
                {

                    m_courses[k] = proxyString;
                    k++;
                    if (k == m_count)
                    {
                        flag = false;
                    }
                }
                break;
            }
            }
        }
    }
    std::string Student::status() const
    {
        return "Student";
    }
    std::string Student::name() const
    {
        return m_name;
    }
    std::string Student::age() const
    {
        return m_age;
    }
    std::string Student::id() const
    {
        return m_id;
    }
    // displays the employee object
    void Student::display(std::ostream &out) const
    {
        out.setf(ios::left);
        out << "| ";
        out.width(10);
        out << "Student";
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
        for (int i = 0; i < m_count; i++)
        {
            out << m_courses[i];
            if (i != m_count - 1)
            {
                out << ", ";
            }
        }
        out.unsetf(ios::left);
    }
    Student::~Student()
    {
        delete[] m_courses;
        m_courses = nullptr;
    }
}