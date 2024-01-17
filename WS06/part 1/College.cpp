#include "College.h"
using namespace std;
namespace sdds
{
    College &College::operator+=(Person *thePerson)
    {
        m_persons.push_back(thePerson);
        return *this;
    }
    void College::display(std::ostream &out) const
    {
        std::vector<Person *>::iterator it{};
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        out << "|                                        Test #1 Persons in the college!                                               |" << endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        for (auto it = m_persons.begin(); it != m_persons.end(); it++)
        {
            (*it)->display(out);
        }
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        out << "|                                        Test #2 Persons in the college!                                               |" << endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        for (auto it = m_persons.begin(); it != m_persons.end(); it++)
        {
            out.setf(ios::left);
            out << "| ";
            out.width(10);
            out << (*it)->status();
            out << "| ";
            out.width(10);
            out << (*it)->id();
            out << "| ";
            out.width(20);
            out << (*it)->name();
            out << " | ";
            out.width(3);
            out << (*it)->age();
            out << " |" << endl;
            out.unsetf(ios::left);
        }
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    College::~College()
    {
        for (auto it = m_persons.begin(); it != m_persons.end(); it++)
        {
            delete (*it);
            (*it)=nullptr;
        }
    }
}