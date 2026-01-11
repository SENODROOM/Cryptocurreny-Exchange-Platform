#include <iostream>
#include <string>
#include <vector>

#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
using namespace std;

int main()
{
    // MerkelMain app{};
    // app.init();
    CSVReader reader;
    CSVReader::readCSV("20200317.csv");
    return 0;
}
