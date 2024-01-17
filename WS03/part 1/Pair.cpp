#include <iostream>
#include "Pair.h"

using namespace std;

namespace sdds
{

    bool Pair::operator==(const Pair &RightHand) const
    {
        return m_key==RightHand.m_key?true:false;
    }
    std::ostream &operator<<(std::ostream &os,const Pair& p)
    {
        os.width(20);
        os<<p.getKey();
        os<<": "<<p.getValue();
        return os;
    }
}