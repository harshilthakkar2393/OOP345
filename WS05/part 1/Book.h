#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include <string>

namespace sdds
{
    class Book
    {
        std::string bookAuthor{};
        std::string bookTitle{};
        std::string countryPublished{};
        size_t yearPublished{};
        double bookPrice{0};
        std::string bookDescription{};

    public:
        // default Constructor
        Book(){};

        // 1 arg constructor
        Book(const std::string &strBook);

        // a query that returns the title of the book
        const std::string &title() const;

        // a query that returns the publication country
        const std::string &country() const;

        // a query that returns the publication year
        const size_t &year() const;

        // a function that returns the price by reference, allowing the client code to update the price
        double &price();
        friend std::ostream &operator<<(std::ostream &os, const Book &rightHand);
    };
}

#endif