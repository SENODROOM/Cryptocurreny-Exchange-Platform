#pragma once

#include <string>
#include <map>
#include <iostream>

#include "OrderBookEntry.h"

class Wallet
{
public:
    Wallet();
    void insertCurrency(std::string type, double amount);
    bool removeCurrency(std::string type, double amount);
    bool containsCurrency(std::string type, double amount);
    /** generate a string representation of the wallet */
    std::string toString();
    friend std::ostream &operator<<(std::ostream &os, Wallet &wallet);
    bool canFulfillOrder(OrderBookEntry order);
    void processSale(OrderBookEntry &sale);

private:
    std::map<std::string, double> currencies;
};
