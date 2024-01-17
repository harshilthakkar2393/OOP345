#include "Bakery.h"
using namespace std;
namespace sdds
{
    Bakery::Bakery(const char *filename)
    {
        int j = 0;
        int start = 0;
        int end = 0;
        std::ifstream file(filename);
        if (file)
        {
            std::string line{};
            std::string proxyString{};
            while (file)
            {
                BakedGood good{};
                start = 0;
                end = 0;
                line.clear();
                getline(file, line, '\n');
                if (line.length() > 1)
                {

                    for (int i = 0; i < 5; i++)
                    {
                        // setting start and end point
                        start += end;
                        switch (i)
                        {
                        case 0:
                        {
                            end = 8;
                            break;
                        }
                        case 1:
                        {
                            end = 20;
                            break;
                        }
                        case 2:
                        {
                            end = 14;
                            break;
                        }
                        case 3:
                        {
                            end = 8;
                            break;
                        }
                        case 4:
                        {
                            end = 6;
                            break;
                        }
                        default:
                            break;
                        }
                        proxyString.clear();
                        proxyString = line.substr(start, end);
                        j = proxyString.length() - 1;
                        while (j >= 0 && proxyString[j] == ' ') // removing trailing spaces
                        {
                            proxyString.erase(j, 1);
                            j--;
                        }
                        j = 0;
                        while (proxyString[j] == ' ') // removing leading spaces
                        {
                            proxyString.erase(j, 1);
                        }
                        switch (i)
                        {
                        // setting Bake type
                        case 0:
                        {
                            good.type = proxyString == "Bread" ? BakedType::BREAD : BakedType::PASTERY;
                            break;
                        }
                        // setting description
                        case 1:
                        {
                            good.description = proxyString;
                            break;
                        }
                        // setting shelf life
                        case 2:
                        {
                            good.shelfLife = std::stoi(proxyString);
                            break;
                        }
                        // setting stocks
                        case 3:
                        {
                            good.stocks = std::stoi(proxyString);
                            break;
                        }
                        // setting price
                        case 4:
                        {
                            good.price = std::stod(proxyString);
                            break;
                        }
                        default:
                            break;
                        }
                    }
                    goods.push_back(good);
                }
            }
        }
        else
        {
            throw "error! invalid filename";
        }
        file.close();
    }
    void Bakery::showGoods(std::ostream &os) const
    {
        for_each(goods.begin(), goods.end(), [&os](BakedGood b)
                 { os << b << endl; });
    }
    std::ostream &operator<<(std::ostream &out, const BakedGood &b)
    {
        
        out << "* "<<left<<setw(10)<< (b.type == BakedType::BREAD ? "Bread" : "Pastry");
        out << " * "<<left<<setw(20)<< b.description;
        out << " * "<<left<<setw(5)<< b.shelfLife;
        out << " * "<<left<<setw(5)<<b.stocks;
        out << " * "<<right<<fixed<<setw(8)<<setprecision(2)<< b.price<<" * ";
        return out;
    }
}