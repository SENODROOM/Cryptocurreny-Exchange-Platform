#include "MerkelMain.h"
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <iostream>
#include <vector>
using namespace std;

MerkelMain::MerkelMain()
{
}
void MerkelMain::init()
{
    int userOption;
    while (true)
    {
        printMenu();
        userOption = getUserOption();
        processUserOption(userOption);
    }
}
void MerkelMain::printMenu()
{
    cout << "1: Print help" << endl;
    cout << "2: Print exchange stats" << endl;
    cout << "3: Place an ask" << endl;
    cout << "4: Place a bid" << endl;
    cout << "5: Print wallet" << endl;
    cout << "6: Continue" << endl;
    cout << "================" << endl;
}

int MerkelMain::getUserOption()
{
    int userOption;
    cout << "Type in 1-6: ";
    cin >> userOption;
    return userOption;
}

void MerkelMain::printHelp()
{
    cout << "Help: Your aim is to make money. Analyze the market and make bids and offers."
         << endl;
}

void MerkelMain::printMarketStats()
{
    for (std::string const p : OrderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = OrderBook.getOrders(OrderBookType::ask,
                                                                  p,
                                                                  "2020/03/17 17:01:24.884492");
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
    }
}

void MerkelMain::placeAsk()
{
    cout << "Placing an ask - enter the amount" << endl;
}

void MerkelMain::placeBid()
{
    cout << "Placing a bid - enter the amount" << endl;
}

void MerkelMain::printWallet()
{
    cout << "Your wallet is empty" << endl;
}

void MerkelMain::nextTimeFrame()
{
    cout << "Going to next time frame" << endl;
}

void MerkelMain::processUserOption(int userOption)
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