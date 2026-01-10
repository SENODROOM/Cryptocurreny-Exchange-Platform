#include <iostream>
#include <string>
#include <vector>

#include "OrderBookEntry.h"
using namespace std;

void printMenu();
int getUserOption();
void printHelp();
void printMarketStats();
void placeAsk();
void placeBid();
void printWallet();
void nextTimeFrame();
void processUserOption(int userOption);

double computeAveragePrice(const vector<OrderBookEntry> &entries)
{
    double sum = 0;
    for (const OrderBookEntry &e : entries)
        sum += e.price;

    return entries.empty() ? 0 : sum / entries.size();
}

double computeLowPrice(const vector<OrderBookEntry> &entries)
{
    double low = entries[0].price;
    for (const OrderBookEntry &e : entries)
        if (e.price < low)
            low = e.price;
    return low;
}

double computeHighPrice(const vector<OrderBookEntry> &entries)
{
    double high = entries[0].price;
    for (const OrderBookEntry &e : entries)
        if (e.price > high)
            high = e.price;
    return high;
}

double computePriceSpread(const vector<OrderBookEntry> &entries)
{
    return computeHighPrice(entries) - computeLowPrice(entries);
}

int main()
{
    vector<OrderBookEntry> orders;

    orders.push_back({0.02186299, 0.1,
                      "2020/03/17 17:01:24.884492",
                      "ETH/BTC",
                      OrderBookType::bid});

    orders.push_back({0.02190000, 0.25,
                      "2020/03/17 17:01:30.000000",
                      "ETH/BTC",
                      OrderBookType::ask});

    orders.push_back({0.02185000, 0.15,
                      "2020/03/17 17:01:40.000000",
                      "ETH/BTC",
                      OrderBookType::bid});

    for (const OrderBookEntry &e : orders)
        cout << e.price << endl;

    cout << "Average price: " << computeAveragePrice(orders) << endl;
    cout << "Low price: " << computeLowPrice(orders) << endl;
    cout << "High price: " << computeHighPrice(orders) << endl;
    cout << "Price spread: " << computePriceSpread(orders) << endl;

    return 0;
}

void printMenu()
{
    cout << "1: Print help" << endl;
    cout << "2: Print exchange stats" << endl;
    cout << "3: Place an ask" << endl;
    cout << "4: Place a bid" << endl;
    cout << "5: Print wallet" << endl;
    cout << "6: Continue" << endl;
    cout << "================" << endl;
}

int getUserOption()
{
    int userOption;
    cout << "Type in 1-6: ";
    cin >> userOption;
    return userOption;
}

void printHelp()
{
    cout << "Help: Your aim is to make money. Analyze the market and make bids and offers."
         << endl;
}

void printMarketStats()
{
    cout << "Market stats: Prices are moving..." << endl;
}

void placeAsk()
{
    cout << "Placing an ask - enter the amount" << endl;
}

void placeBid()
{
    cout << "Placing a bid - enter the amount" << endl;
}

void printWallet()
{
    cout << "Your wallet is empty" << endl;
}

void nextTimeFrame()
{
    cout << "Going to next time frame" << endl;
}

void processUserOption(int userOption)
{
    if (userOption == 1)
        printHelp();
    else if (userOption == 2)
        printMarketStats();
    else if (userOption == 3)
        placeAsk();
    else if (userOption == 4)
        placeBid();
    else if (userOption == 5)
        printWallet();
    else if (userOption == 6)
        nextTimeFrame();
    else
        cout << "Invalid choice. Please select 1-6." << endl;
}
