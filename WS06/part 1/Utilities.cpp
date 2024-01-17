#include "Utilities.h"
using namespace std;
namespace sdds
{
    Person *buildInstance(std::istream &in)
    {
        Person *temp = nullptr;
        if (in)
        {
            char c{};
            do
            {
                c = in.get();
            } while (c == ' ');
            if (c == 'E' || c == 'e')
            {
                in.ignore(1);
                temp = new Employee(in);
            }
            else
            {
                in.ignore(1000, '\n');
            }
        }
        return temp;
    }
}