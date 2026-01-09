#include <iostream>
using namespace std;

void PrintMenu()
{
    cout << "1: Print Help " << endl;
    cout << "2: Print Exchange stats " << endl;
    cout << "3: Make an offer " << endl;
    cout << "4: Make a bid " << endl;
    cout << "5: Print wallet " << endl;
    cout << "6: Continue " << endl;
    cout << "================" << endl;
}

int getUserOption()
{
    int userOption;
    cout << "Type in 1-6" << endl;
    cin >> userOption;
    cout << "You choose: " << userOption << endl;
    return userOption;
}
void printHelp()
{
    cout << "Invalid choice. Choose 1-6" << endl;
}
void printMarketStats()
{
    cout << "Help - your aim is to make money. Analyze the market and make bids and offers " << endl;
}
void enterOffer()
{
    cout << "Market looks good" << endl;
}
void enterOffer()
{
    cout << "Mark an offer - enter the amount" << endl;
}
void enterBid()
{
    cout << "Mark a bid - enter the amount" << endl;
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
    if (userOption == 0)
    {
        printHelp();
    }
    if (userOption == 1)
    {
        printMarketStats();
    }
    if (userOption == 2)
    {
        enterOffer();
    }
    if (userOption == 3)
    {
        enterOffer();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        nextTimeFrame();
    }
}

int main()
{
    while (true)
    {
        PrintMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }

    return 0;
}