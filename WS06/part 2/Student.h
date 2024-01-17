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
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#include <iostream>
#include<string>
#include <vector>
#include "Person.h"
namespace sdds
{
    class Student : public Person
    {
        std::string m_name{};
        std::string m_age{};
        std::string m_id{};
        std::string *m_courses{nullptr};
        int m_count{};

    public:
        Student(){};
        Student(std::istream &in);
        Student(Student &) = delete;
        Student &operator=(Student &) = delete;
        std::string status() const;
        std::string name() const;
        std::string age() const;
        std::string id() const;
        void display(std::ostream &out) const;
        ~Student();
    };
}
#endif