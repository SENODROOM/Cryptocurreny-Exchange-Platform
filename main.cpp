#include <iostream>
#include <string>
#include <vector>

#include "OrderBookEntry.h"
#include "MerkelMain.h"
using namespace std;
int main()
{
    MerkelMain app{};
    app.printMenu();
    // vector<OrderBookEntry> orders;

    // orders.push_back({0.02186299, 0.1,
    //                   "2020/03/17 17:01:24.884492",
    //                   "ETH/BTC",
    //                   OrderBookType::bid});

    // orders.push_back({0.02190000, 0.25,
    //                   "2020/03/17 17:01:30.000000",
    //                   "ETH/BTC",
    //                   OrderBookType::ask});

    // orders.push_back({0.02185000, 0.15,
    //                   "2020/03/17 17:01:40.000000",
    //                   "ETH/BTC",
    //                   OrderBookType::bid});

    // for (const OrderBookEntry &e : orders)
    //     cout << e.price << endl;

    // cout << "Average price: " << computeAveragePrice(orders) << endl;
    // cout << "Low price: " << computeLowPrice(orders) << endl;
    // cout << "High price: " << computeHighPrice(orders) << endl;
    // cout << "Price spread: " << computePriceSpread(orders) << endl;

    return 0;
}
