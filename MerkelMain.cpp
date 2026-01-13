#include "MerkelMain.h"
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

MerkelMain::MerkelMain()
{
}
void MerkelMain::init()
{
    int userOption;
    currentTime = OrderBook.getEarliestTime();

    wallet.insertCurrency("BTC", 10);

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
    cout << "Current time is: " << currentTime << endl;
}

int MerkelMain::getUserOption()
{
    int userOption = 0;
    string line;
    cout << "Type in 1-6: ";
    getline(cin, line);
    try
    {
        userOption = stoi(line);
    }
    catch (const exception &e)
    {
    }

    return userOption;
}

void MerkelMain::printHelp()
{
    cout << "Help: Your aim is to make money. Analyze the market and make bids and offers."
         << endl;
}

void MerkelMain::printMarketStats()
{
    for (string const p : OrderBook.getKnownProducts())
    {
        cout << "Product: " << p << endl;
        vector<OrderBookEntry> entries = OrderBook.getOrders(OrderBookType::ask,
                                                             p,
                                                             currentTime);
        cout << "Asks seen: " << entries.size() << endl;
        cout << "Max ask: " << OrderBook::getHighPrice(entries) << endl;
    }
}

void MerkelMain::placeAsk()
{
    cout << "Placing an ask - enter the amount: product,price,amount eg ETH/BTC,200,0" << endl;
    string input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);
    vector<string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        cout << "Bad Input! " << input << endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::ask);
            if (wallet.canFulfillOrder(obe))
            {
                cout << "Wallet looks good. " << endl;
                OrderBook.insertOrder(obe);
            }
            else
            {
                cout << "Wallet has insufficient funds. " << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "MerkelMain::placeAsk Bad input " << endl;
        }
    }
    cout << "You typed: " << input << endl;
}

void MerkelMain::placeBid()
{
    cout << "Placing a bid - enter the amount" << endl;
}

void MerkelMain::printWallet()
{
    cout << "Your wallet is empty" << endl;
    cout << wallet.toString() << endl;
}

void MerkelMain::nextTimeFrame()
{
    cout << "Going to next time frame" << endl;
    vector<OrderBookEntry> sales = OrderBook.matchAsksToBids("ETH/BTC", currentTime);
    cout << "Sales: " << sales.size() << endl;
    for (OrderBookEntry &sale : sales)
    {
        cout << "Sale price: " << sale.price << " amount " << sale.amount << endl;
    }

    currentTime = OrderBook.getNextTime(currentTime);
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