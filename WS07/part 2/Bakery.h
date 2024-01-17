/*
======================================
 Workshop 7 Part 2
======================================
Module : Bakery
-------------------------------------
Name: Harshil Dineshbhai Thakkar
Student ID: 160431219
Student Email: hthakkar8@myseneca.ca
Date: 19/03/2023
Section: NEE
-------------------------------------
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
======================================
*/
#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H
#include <vector>
#include<list>
#include <iostream>
#include <algorithm>
#include<numeric>
#include<iterator>
#include<fstream>
#include <iomanip>
namespace sdds
{
    enum class BakedType
    {
        BREAD,
        PASTERY
    };
    struct BakedGood
    {
        BakedType type{};
        std::string description{};
        int shelfLife{};
        int stocks{};
        double price{};
    };
    class Bakery
    {
        std::vector<BakedGood> goods{};

    public:
        Bakery(){};
        Bakery(const char *filename);
        void showGoods(std::ostream &os) const;
        void sortBakery(const std::string s);
        std::vector<BakedGood> combine(Bakery& b);
        bool inStock(const std::string desc,const BakedType t) const;
        std::list<BakedGood> outOfStock(const BakedType t) const;
    };
    std::ostream &operator<<(std::ostream &out, const BakedGood &b);
}
#endif