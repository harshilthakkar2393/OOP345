/*
======================================
 Workshop 1 Part 1
======================================
Module : foodorder
-------------------------------------
Name: Harshil Dineshbhai Thakkar
Student ID: 160431219
Student Email: hthakkar8@myseneca.ca
Date: 14/01/2023
Section: NEE
-------------------------------------
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
======================================
*/

#ifndef SDDS_FOODORDER_H__
#define SDDS_FOODORDER_H__
#include <iostream>
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds
{
    class FoodOrder
    {
        char custName[10];
        char foodDesc[25];
        double foodPrice;
        bool isDailySpecial;

    public:
        FoodOrder();
        void read(std::istream &is);
        void display();
    };
}
#endif