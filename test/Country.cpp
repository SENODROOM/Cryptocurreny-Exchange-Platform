#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>
#include "CountryData.h"

int main()
{
    std::ifstream file("countries.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file.\n";
        return 1;
    }

    std::vector<CountryData> countries;
    std::string line;
    int lineNumber = 0;
    int validLines = 0;

    // Read header line
    std::getline(file, line);

    while (std::getline(file, line))
    {
        lineNumber++;
        std::stringstream ss(line);
        std::string country, yearStr, popStr, gdpStr;

        try
        {
            // Tokenize CSV by comma
            if (!std::getline(ss, country, ','))
                throw std::runtime_error("Missing country");
            if (!std::getline(ss, yearStr, ','))
                throw std::runtime_error("Missing year");
            if (!std::getline(ss, popStr, ','))
                throw std::runtime_error("Missing population");
            if (!std::getline(ss, gdpStr, ','))
                throw std::runtime_error("Missing GDP");

            // Convert strings to numbers
            int year = std::stoi(yearStr);
            long long population = std::stoll(popStr);
            long long gdp = std::stoll(gdpStr);

            // Create object and add to vector
            CountryData data(country, year, population, gdp);
            countries.push_back(data);
            validLines++;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error in line " << lineNumber << ": " << e.what() << std::endl;
        }
    }

    std::cout << "Total valid lines: " << validLines << std::endl;
    std::cout << "Total entries read: " << countries.size() << std::endl;

    // Optionally, print all data
    for (auto &c : countries)
    {
        c.print();
    }

    return 0;
}
