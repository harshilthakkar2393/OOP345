// Name: Harshil Dineshbhai Thakkar
// Seneca Student ID: 160431219
// Seneca email: hthakkar8@myseneca.ca
// Date of completion: 1-04-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iostream>
#include <deque>
#include "CustomerOrder.h"
namespace sdds
{
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;
    class Workstation : public Station
    {
        std::deque<CustomerOrder> m_orders{};
        Workstation *m_pNextStation{nullptr};

    public:
        Workstation(){};
        Workstation(const std::string &str) : Station(str){};
        Workstation(const Workstation &rightHand) = delete;
        Workstation(Workstation &&rightHand) = delete;
        Workstation &operator=(const Workstation &rightHand) = delete;
        Workstation &operator=(Workstation &&rightHand) = delete;
        void fill(std::ostream &os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation *station = nullptr);
        Workstation *getNextStation() const;
        void display(std::ostream &os) const;
        Workstation &operator+=(CustomerOrder &&newOrder);
    };
}
#endif