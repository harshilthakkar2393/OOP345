#include "Employee.h"

using namespace std;
namespace sdds
{
    Employee::Employee(std::istream &is)
    {
        bool valid = true;
        char c{};
        int j = 0;
        std::string proxyString{};
        for (int i = 0; i < 3; i++)
        {
            proxyString.clear();
            valid = true;
            while (valid && is)
            {
                c = is.get();
                if (c == '\n' || c == ',' || c == -1)
                {
                    valid = false;
                }
                else
                {
                    proxyString += c;
                }
            }
            j =proxyString.length()-1;
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
            case 0:
            {
                // setting name
                // cout << proxyString << endl;
                m_name = proxyString;
                break;
            }
            case 1:
            {
                // setting age
                // cout << proxyString << endl;
                m_age = proxyString;
                break;
            }
            case 2:
            {
                // cout << proxyString << endl;
                // cout<<proxyString[0]<<endl;
                // setting employee id
                if (proxyString[0] == 'e' || proxyString[0] == 'E')
                {
                    m_id = proxyString;
                }
                else
                {
                    std::string message = m_name + "++Invalid record!";
                    throw message;
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
    std::string Employee::status() const
    {
        return "Employee";
    }
    std::string Employee::name() const
    {
        return m_name;
    }
    std::string Employee::id() const
    {
        return m_id;
    }
    std::string Employee::age() const
    {
        return m_age;
    }
    void Employee::display(std::ostream &out) const
    {
        out.setf(ios::left);
        out << "| ";
        out.width(10);
        out << "Employee";
        out << "| ";
        out.width(10);
        out << m_id;
        out << "| ";
        out.width(20);
        out << m_name;
        out << " | ";
        out.width(3);
        out << m_age;
        out << " |" << endl;
        out.unsetf(ios::left);
    }
}