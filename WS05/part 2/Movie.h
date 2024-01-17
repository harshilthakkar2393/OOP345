#ifndef SDDS_MOVIE_H_
#define SDDS_MOVIE_H_
#include <iostream>
#include <string>

namespace sdds
{
    class Movie
    {
        std::string movieTitle{};
        size_t yearReleased{};
        std::string movieDescription{};

    public:
        // default Constructor
        Movie(){};

        // 1 arg constructor
        Movie(const std::string &strMovie);
        const std::string& title() const;
        friend std::ostream &operator<<(std::ostream &os, const Movie &rightHand);

        template<typename T>
        void fixSpelling(T& spellChecker)
        {
            spellChecker(movieTitle);
            spellChecker(movieDescription);
        }
    };
}

#endif