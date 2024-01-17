/*
======================================
 Workshop 3 Part 2
======================================
Module : Collection
-------------------------------------
Name: Harshil Dineshbhai Thakkar
Student ID: 160431219
Student Email: hthakkar8@myseneca.ca
Date: 05/02/2023
Section: NEE
-------------------------------------
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
======================================
*/
#ifndef _SDDS_COLLECTION_H_
#define _SDDS_COLLECTION_H_
#include <iostream>
#include "Pair.h"
namespace sdds
{
    template <typename T, unsigned int CAPACITY>
    class Collection
    {
        int noOfRecords{0};
        T array[CAPACITY]{};
        static T dummy;

    public:
        // ===================================
        // Constructors and Destructors
        // ===================================

        // Default Constructor
        Collection(){};

        // destructor
        virtual ~Collection(){};

        // ===================================
        // Public member functions
        // ===================================

        // Returns the no of records currently stored
        int size() const
        {
            return noOfRecords;
        }

        // Displays the content stored
        std::ostream &display(std::ostream &os = std::cout) const
        {
            os << "----------------------" << std::endl;
            os << "| Collection Content |" << std::endl;
            os << "----------------------" << std::endl;
            for (int i = 0; i < noOfRecords; i++)
            {
                os << array[i] << std::endl;
            }
            os << "----------------------" << std::endl;
            return os;
        }

        // adds a new element to the array
        virtual bool add(const T &item)
        {
            bool sucess = false;
            if ((unsigned)noOfRecords < CAPACITY)
            {
                array[noOfRecords++] = item;
                sucess = true;
            }
            return sucess;
        }

        // ===================================
        // Operator Overloads
        // ===================================

        // returns the element stored at the passed index , if not found returns dummy object
        const T &operator[](const int index)
        {
            return index < noOfRecords ? array[index] : dummy;
        }
    };
    // defining dummy object
    template <typename T, unsigned int CAPACITY>
    T Collection<T, CAPACITY>::dummy{};

    // specialization : defining dummy for Pair data type
    template <>
    Pair Collection<Pair, 100>::dummy{"No Key", "No Value"};
}

#endif