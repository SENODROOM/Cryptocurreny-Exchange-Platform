#include <iostream>
#include <string>
#include <vector>

#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
#include "Wallet.h"
using namespace std;

int main()
{
    Wallet wallet;
    wallet.insertCurrency("BTC", 10);
    wallet.insertCurrency("USDT", 10000);
    cout << wallet.toString() << endl;
    wallet.removeCurrency("USDT", 1000);
    cout << wallet.toString() << endl;
    return 0;
}
