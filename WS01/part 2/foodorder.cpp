/*
======================================
 Workshop 1 Part 2
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

#include <iostream>
#include <string>
#include <cstring>
#include "foodorder.h"
using namespace std;
double g_taxrate = 0.0;
double g_dailydiscount;

namespace sdds
{
    FoodOrder::FoodOrder()
    {
        // setting data members to 0
        custName[0] = 0;
        foodDesc = nullptr;
        foodPrice = 0;
        isDailySpecial = false;
    }
    FoodOrder::FoodOrder(const FoodOrder &rightHand)
    {
        custName[0] = 0;
        foodDesc=nullptr;
        *this = rightHand;
    }
    FoodOrder &FoodOrder::operator=(const FoodOrder &rightHand)
    {
        if (rightHand.foodDesc && this !=&rightHand)
        {
            delete[] foodDesc;
            foodDesc = nullptr;

            foodDesc = new char[strlen(rightHand.foodDesc) + 1];
            strcpy(foodDesc, rightHand.foodDesc);
        }

        foodPrice = rightHand.foodPrice;
        strcpy(custName, rightHand.custName);
        isDailySpecial = rightHand.isDailySpecial;
        return (*this);
    }
    FoodOrder::~FoodOrder()
    {
        if (foodDesc != nullptr)
        {
            // deallocating memory
            delete[] foodDesc;
            foodDesc = nullptr;
        }
    }
    void FoodOrder::read(std::istream &is)
    {
        if (is.good()) // checking if istream object is valid
        {
            char proxyBool = '\0';
            std::string proxyString;

            // reading data and storing it
            is.getline(custName, 9, ',');
            getline(is, proxyString, ',');
            is >> foodPrice;
            is.ignore(1, ',');
            is >> proxyBool;
            is.ignore(1000, '\n');

            if (proxyBool == 'Y')
            {
                isDailySpecial = true;
            }
            else
            {
                isDailySpecial = false;
            }

            if (proxyString.length()>0)
            {
                // allocating memory for foodDesc and copying data
                delete[] foodDesc;
                foodDesc = nullptr;
                foodDesc = new char[proxyString.length() + 1];
                strcpy(foodDesc, proxyString.c_str());
            }
            else
            {
                delete[] foodDesc;
                foodDesc = nullptr;
            }
        }
    }
    void FoodOrder::display()
    {
        static int counter = 0;
        double taxedPrice = 0;

        // count
        cout.setf(ios::left);
        cout.width(2);
        cout << ++counter;
        cout.unsetf(ios::left);
        cout << ". ";

        if (custName[0] != '\0') // checking if name is valid
        {

            taxedPrice = (foodPrice + (foodPrice * g_taxrate));

            // name
            cout.setf(ios::left);
            cout.width(10);
            cout << custName;
            cout.unsetf(ios::left);
            cout << "|";

            // description
            cout.setf(ios::left);
            cout.width(25);
            cout << foodDesc;
            cout.unsetf(ios::left);
            cout << "|";

            // price w/Tax
            cout.setf(ios::left);
            cout.width(12);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << taxedPrice;
            cout.unsetf(ios::fixed);
            cout.unsetf(ios::left);
            cout << "|";

            // special price
            if (isDailySpecial)
            {

                cout.setf(ios::right);
                cout.width(13);
                cout.setf(ios::fixed);
                cout.precision(2);
                cout << taxedPrice - g_dailydiscount;
                cout.unsetf(ios::fixed);
                cout.unsetf(ios::right);
            }
        }
        else
        {
            cout << "No Order";
        }
        cout << endl;
    }
}