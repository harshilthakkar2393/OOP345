/*
======================================
 Workshop 6 Part 2
======================================
Module : Utilities
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
#include "Utilities.h"
using namespace std;
namespace sdds
{
    // reads the stream and creates an instance of object as per the tag . if tag is invalid , it returns nullptr
    Person *buildInstance(std::istream &in)
    {
        Person *temp = nullptr;
        if (in)
        {
            char c{};
            do
            {
                c = in.get();
            } while (c == ' ');
            if (c == 'E' || c == 'e')
            {
                in.ignore(1);
                temp = new Employee(in);
            }
            else if (c == 'S' || c == 's')
            {
                in.ignore(1);
                temp = new Student(in);
            }
            else if (c == 'P' || c == 'p')
            {
                in.ignore(1);
                temp = new Professor(in);
            }
            else
            {
                in.ignore(1000, '\n');
            }
        }
        return temp;
    }
}