// CSVReader.cpp
#include "CSVReader.h"
#include "OrderBookEntry.h"
#include <vector>
#include <string>

CSVReader::CSVReader()
{
    // Constructor implementation
}

std::vector<OrderBookEntry> CSVReader::readCSV()
{
    std::vector<OrderBookEntry> entries;
    // Implementation here
    return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvline, char separator)
{
    std::vector<std::string> tokens;
    return tokens;
}

OrderBookEntry CSVReader::stringToODB(std::vector<std::string> strings)
{
    OrderBookEntry obe{1,
                       0.5,
                       "",
                       "",
                       OrderBookType ::bid};
    return obe;
}