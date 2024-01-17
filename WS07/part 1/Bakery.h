#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H
#include <vector>
#include <iostream>
#include <algorithm>
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
    };
    std::ostream &operator<<(std::ostream &out, const BakedGood &b);
}
#endif