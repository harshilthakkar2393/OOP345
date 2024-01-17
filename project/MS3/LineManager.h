// Name: Harshil Dineshbhai Thakkar
// Seneca Student ID: 160431219
// Seneca email: hthakkar8@myseneca.ca
// Date of completion: 1-04-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <iostream>
#include <vector>
#include<fstream>
#include<algorithm>
#include "Workstation.h"
namespace sdds
{
    class LineManager
    {
        std::vector<Workstation *> m_activeLine;
        size_t m_cntCustomerOrder{0};
        Workstation *m_firstStation{nullptr};

    public:
        LineManager(){};
        LineManager(const std::string &file, const std::vector<Workstation *> &stations);
        void reorderStations();
        bool run(std::ostream &os);
        void display(std::ostream &os) const;
    };
}
#endif