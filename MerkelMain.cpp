#include "MerkelMain.h"
#include <iostream>
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
    cout << "Market stats: Prices are moving..." << endl;
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
