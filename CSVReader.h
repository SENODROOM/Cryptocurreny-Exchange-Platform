#pragma once

#include <vector>

#include "OrderBookEntry.h"

class CSVReader
{
public:
    CSVReader();
    static std::vector<OrderBookEntry> readCSV();

private:
    static std::vector<std::string> tokenise(std::string csvline, char separator);
    OrderBookEntry stringToODB(std::vector<std::string> strings);
};
