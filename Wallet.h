#pragma once

#include <string>
#include <map>
#include <iostream>

#include "OrderBookEntry.h"

using namespace std;

class Wallet
{
public:
    Wallet();
    void insertCurrency(string type, double amount);
    bool removeCurrency(string type, double amount);
    bool containsCurrency(string type, double amount);
    /** generate a string representation of the wallet */
    string toString();
    friend ostream &operator<<(ostream &os, Wallet &wallet);
    bool canFulfillOrder(OrderBookEntry order);
    void processSale(OrderBookEntry &sale);

private:
    map<string, double> currencies;
};
