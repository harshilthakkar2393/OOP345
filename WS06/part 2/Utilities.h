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
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Student.h"
#include "Professor.h"
namespace sdds
{
    Person *buildInstance(std::istream &in);
}
#endif