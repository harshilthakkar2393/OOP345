#ifndef SDDS_TOY_H_
#define SDDS_TOY_H_
#include <iostream>
namespace sdds
{
    class Toy
    {
        unsigned int orderId{};
        std::string name{};
        int noOfItems{};
        double price{};
        const double hst{0.13};
    public:
        Toy(){};
        Toy(const std::string& toy);
        void update(int numItems);
        friend std::ostream& operator<<(std::ostream &os,const Toy& rightHand);
    };
}
#endif