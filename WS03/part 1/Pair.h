#ifndef _SDDS_PAIR_H_
#define _SDDS_PAIR_H_
#include <iostream>

namespace sdds
{

    class Pair
    {
        std::string m_key{};
        std::string m_value{};

    public:
        const std::string &getKey()const { return m_key; }
        const std::string &getValue()const { return m_value; }
        Pair(){};
        Pair(const std::string &key, const std::string &value) : m_key{key}, m_value{value} {};
        bool operator==(const Pair &RightHand) const;
        friend std::ostream &operator<<(std::ostream &os,const Pair& p);
        // TODO: Add here the missing prototypes for the members
        //           that are necessary if this class is to be used
        //           with the template classes described below.
        //       Implement them in the Pair.cpp file.
    };
}

#endif