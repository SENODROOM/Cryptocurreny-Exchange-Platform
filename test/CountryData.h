#include <string>
#include <iostream>

class CountryData
{
public:
    std::string country;
    int year;
    long long population;
    long long gdp;

    // Constructor
    CountryData(const std::string &_country, int _year, long long _population, long long _gdp)
    {
        country = _country;
        year = _year;
        population = _population;
        gdp = _gdp;
    }

    void print()
    {
        std::cout << "Country: " << country
                  << ", Year: " << year
                  << ", Population: " << population
                  << ", GDP: " << gdp << std::endl;
    }
};
