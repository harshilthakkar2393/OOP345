#include "Movie.h"
using namespace std;
namespace sdds
{
    // 1 arg constructor
    Movie::Movie(const std::string &strMovie)
    {
        if (!strMovie.empty())
        {
            int start = 0;
            int end = 0;
            int j = 0;
            std::string proxyString{};
            for (int i = 0; i < 3; i++)
            {
                if (i == 2)
                {

                    end = strMovie.find('\n', start);
                }
                else
                {
                    end = strMovie.find(',', start);
                }
                proxyString.clear();
                proxyString = strMovie.substr(start, end - start);
                j = end - start - 1;
                while (j >= 0 && proxyString[j] == ' ')
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
                    // setting title
                    movieTitle = proxyString;
                    break;
                }
                case 1:
                {
                    // setting year
                    yearReleased = stoi(proxyString);
                    break;
                }
                case 2:
                {
                    // setting description
                    movieDescription = proxyString;
                    break;
                }
                default:
                    break;
                }
                start = end + 1;
            }
        }
        
    }

    const std::string& Movie::title() const
    {
        return movieTitle;
    }

    std::ostream &operator<<(std::ostream &os, const Movie &rightHand)
    {
        os.width(40);
        os << rightHand.movieTitle;
        os << " | ";
        os.width(4);
        os << rightHand.yearReleased;
        os << " | ";
        os << rightHand.movieDescription<<endl;
        return os;
    }
}