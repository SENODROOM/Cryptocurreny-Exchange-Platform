#include <string>
#include <iostream>
#include "OrderBookEntry.h"
#include <map>
class Wallet
{
public:
    Wallet();
    void insertCurrency(std::string type, double amount);
    bool removeCurrency(std::string type, double amount);
    bool containsCurrency(std::string type, double amount);
    bool canFulfillOrder(OrderBookEntry order);
    void processSale(OrderBookEntry &sale);
    std::string toString();

private:
    std::map<std::string, double> currencies;
};