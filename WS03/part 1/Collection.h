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
        Collection(){};
        int size() const
        {
            return noOfRecords;
        }
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
        bool add(const T &item)
        {
            bool sucess = false;
            if ((unsigned)noOfRecords < CAPACITY)
            {
                array[noOfRecords++] = item;
                sucess = true;
            }
            return sucess;
        }
        const T &operator[](const int index)
        {
            return index <= noOfRecords ? array[index] : dummy;
        }
    };
    template <typename T, unsigned int CAPACITY>
    T Collection<T, CAPACITY>::dummy{};

    template <>
    Pair Collection<Pair, 100>::dummy{"No Key", "No Value"};
}

#endif