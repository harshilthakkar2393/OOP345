// Name: Harshil Dineshbhai Thakkar
// Seneca Student ID: 160431219
// Seneca email: hthakkar8@myseneca.ca
// Date of completion: 1-04-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "CustomerOrder.h"
using namespace std;
namespace sdds
{
    size_t CustomerOrder::m_widthField = 0;
    // 1 arg constructor
    CustomerOrder::CustomerOrder(const std::string &str)
    {
        Utilities temp{};
        size_t next_pos = 0;
        bool more = false;
        m_cntItem = std::count(str.begin(), str.end(), Utilities::getDelimiter());
        m_cntItem--;
        m_lstItem = new Item *[m_cntItem];
        m_name = temp.extractToken(str, next_pos, more);
        m_product = temp.extractToken(str, next_pos, more);
        for (size_t i = 0; i < m_cntItem && more; i++)
        {
            m_lstItem[i] = new Item(temp.extractToken(str, next_pos, more));
            CustomerOrder::m_widthField = CustomerOrder::m_widthField < temp.getFieldWidth() ? temp.getFieldWidth() : CustomerOrder::m_widthField;
        }
    }

    // copy constructor
    CustomerOrder::CustomerOrder(const CustomerOrder &rightHand)
    {
        throw "error";
    }

    // move constructor
    CustomerOrder::CustomerOrder(CustomerOrder &&rightHand) noexcept
    {
        *this = std::move(rightHand);
    }

    // destructor
    CustomerOrder::~CustomerOrder()
    {
        deallocate();
    }

    // deallocates the resources
    void CustomerOrder::deallocate()
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            delete m_lstItem[i];
            m_lstItem[i] = nullptr;
        }
        delete[] m_lstItem;
        m_lstItem = nullptr;
    }

    // move assignment operator
    CustomerOrder &CustomerOrder::operator=(CustomerOrder &&rightHand) noexcept
    {
        if (this != &rightHand)
        {
            m_name = rightHand.m_name;
            m_product = rightHand.m_product;
            m_widthField = rightHand.m_widthField;
            deallocate();
            this->m_lstItem = rightHand.m_lstItem;
            rightHand.m_lstItem = nullptr;
            this->m_cntItem = rightHand.m_cntItem;
            rightHand.m_cntItem = 0;
        }
        return *this;
    }

    // returns true if all the items in the order have been filled; false otherwise
    bool CustomerOrder::isOrderFilled() const
    {
        bool isFilled = true;
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (m_lstItem[i]->m_isFilled == false)
            {
                isFilled = false;
            }
        }
        return isFilled;
    }

    //  returns true if all items specified by itemName have been filled. If the item doesn't exist in the order, this query returns true.
    bool CustomerOrder::isItemFilled(const std::string &itemName) const
    {
        bool isFilled = true;
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled == false)
            {
                isFilled = false;
            }
        }
        return isFilled;
    }

    //  this modifier fills one item in the current order that the Station specified in the first parameter handles.
    void CustomerOrder::fillItem(Station &station, std::ostream &os)
    {
        bool found = false;
        for (size_t i = 0; i < m_cntItem && !found; i++)
        {
            if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled && station.getQuantity() >= 1)
            {
                station.updateQuantity();
                m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                m_lstItem[i]->m_isFilled = true;
                os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
                found = true;
            }
            else if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled && station.getQuantity()<1)
            {
                os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
            }
        }
        
    }

    //  this query displays the state of the current object in the format
    void CustomerOrder::display(std::ostream &os) const
    {
        os << m_name << " - " << m_product << endl;
        for (size_t i = 0; i < m_cntItem; i++)
        {
            os << "[" << setw(6) << setfill('0') <<right<< m_lstItem[i]->m_serialNumber << "] " << setfill(' ') << setw(CustomerOrder::m_widthField) << left << m_lstItem[i]->m_itemName << "   - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
        }
    }
}