#include <iostream>
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
        foodDesc[0] = 0;
        foodPrice = 0;
        isDailySpecial = false;
    }
    void FoodOrder::read(std::istream &is)
    {
        if (is.good())
        {
            char proxyBool = '\0';
            is.getline(custName, 9, ',');
            is.getline(foodDesc, 24, ',');
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

        if (custName[0] != '\0')
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