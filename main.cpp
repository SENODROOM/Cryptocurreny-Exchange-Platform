#include <iostream>
#include <string>
#include <vector>
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
enum class OrderBookType
{
    bid,
    ask
};

enum class OrderBookType
{
    bid,
    ask
};
class OrderBookEntry
{
public:
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType)
        : price(_price),
          amount(_amount),
          timestamp(_timestamp),
          product(_product),
          orderType(_orderType)
    {
    }
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};
int main()
{
    vector<double> price;
    vector<double> amount;
    vector<string> timestamp;
    vector<string> product;
    vector<OrderBookType> ordertype;

    price.push_back(5348.8502489);
    amount.push_back(0.46021);
    timestamp.push_back("2020/03/17 17:01:24.884492");
    product.push_back("BTC/USDT");
    ordertype.push_back(OrderBookType::bid);

    while (true)
    {
        PrintMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }
    vector<OrderBookEntry> orders;
    orders.push_back({1000,
                      0.02,
                      "2020/03/17 17:01:24.884492",
                      "BTC/USDT",
                      OrderBookType::bid});
    orders.push_back({2000,
                      0.02,
                      "2020/03/17 17:01:24.884492",
                      "BTC/USDT",
                      OrderBookType::bid});

    return 0;
}