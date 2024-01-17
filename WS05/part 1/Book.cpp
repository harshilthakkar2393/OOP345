#include "Book.h"

using namespace std;
namespace sdds
{
    // 1 arg constructor
    Book::Book(const std::string &strBook)
    {
        if (!strBook.empty())
        {
            int start = 0;
            int end = 0;
            int j = 0;
            std::string proxyString{};
            for (int i = 0; i < 6; i++)
            {
                if(i==5)
                {
                    
                    end = strBook.find('\n', start);
                }
                else
                {
                    end = strBook.find(',', start);
                }
                proxyString.clear();
                proxyString = strBook.substr(start, end - start);
                j = end - start-1;
                while (j>=0 && proxyString[j] == ' ')
                {
                    proxyString.erase(j, 1);
                    j--;
                }
                j = 0;
                while (proxyString[j] == ' ')
                {
                    proxyString.erase(j, 1);
                }
                switch (i)
                {
                case 0:
                {
                    // setting Author

                    this->bookAuthor = proxyString;
                    break;
                }
                case 1:
                {
                    // setting title
                    bookTitle = proxyString;
                    break;
                }
                case 2:
                {
                    // setting country
                    countryPublished = proxyString;
                    break;
                }
                case 3:
                {
                    // setting price
                    bookPrice = stod(proxyString);
                    break;
                }
                case 4:
                {
                    // setting year
                    yearPublished = stoi(proxyString);
                    break;
                }
                case 5:
                {
                    // setting description
                    bookDescription = proxyString;
                    break;
                }
                default:
                    break;
                }
                start = end + 1;
            }
        }
    }

    // a query that returns the title of the book
    const std::string &Book::title() const
    {
        return this->bookTitle;
    }

    // a query that returns the publication country
    const std::string &Book::country() const
    {
        return this->countryPublished;
    }

    // a query that returns the publication year
    const size_t &Book::year() const
    {
        return this->yearPublished;
    }

    // a function that returns the price by reference, allowing the client code to update the price
    double &Book::price()
    {
        return this->bookPrice;
    }

    std::ostream &operator<<(std::ostream &os, const Book &rightHand)
    {
        os.width(20);
        os << rightHand.bookAuthor;
        os << " | ";
        os.width(22);
        os << rightHand.title();
        os << " | ";
        os.width(5);
        os << rightHand.country();
        os << " | ";
        os.width(4);
        os << rightHand.year();
        os << " | ";
        os.setf(ios::fixed);
        os.precision(2);
        os.width(6);
        os << rightHand.bookPrice;
        os.unsetf(ios::fixed);
        os << " | ";
        os << rightHand.bookDescription;
        return os;
    }
}