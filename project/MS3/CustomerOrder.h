// Name: Harshil Dineshbhai Thakkar
// Seneca Student ID: 160431219
// Seneca email: hthakkar8@myseneca.ca
// Date of completion: 29-03-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include<algorithm>
#include "Station.h"
namespace sdds
{
    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const std::string &src) : m_itemName(src){};
    };
    class CustomerOrder
    {
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{0};
        Item **m_lstItem{nullptr};
        static size_t m_widthField;
        void deallocate();

    public:
        // default constructor
        CustomerOrder(){};

        // 1 arg constructor
        CustomerOrder(const std::string &str);

        // copy constructor
        CustomerOrder(const CustomerOrder &rightHand);

        // move constructor
        CustomerOrder(CustomerOrder &&rightHand) noexcept;

        // destructor
        ~CustomerOrder();

        // copy assignment opeartor
        CustomerOrder &operator=(const CustomerOrder &rightHand)=delete;

        // move assignment operator
        CustomerOrder &operator=(CustomerOrder &&rightHand) noexcept;

        // returns true if all the items in the order have been filled; false otherwise
        bool isOrderFilled() const;

        //  returns true if all items specified by itemName have been filled. If the item doesn't exist in the order, this query returns true.
        bool isItemFilled(const std::string &itemName) const;

        //  this modifier fills one item in the current order that the Station specified in the first parameter handles.
        void fillItem(Station &station, std::ostream &os);

        //  this query displays the state of the current object in the format
        void display(std::ostream &os) const;
    };
}
#endif