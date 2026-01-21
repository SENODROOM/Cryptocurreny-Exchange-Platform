#include "Wallet.h"
#include <iostream>
#include "CSVReader.h"

Wallet::Wallet()
{
}

void Wallet::insertCurrency(string type, double amount)
{
    cout << "insertCurrencyMYK version. " << endl;
    double balance;
    if (amount < 0)
    {
        throw exception{};
    }
    if (currencies.count(type) == 0) // not there yet
    {
        balance = 0;
    }
    else
    { // is there
        balance = currencies[type];
    }
    balance += amount;
    currencies[type] = balance;
}

bool Wallet::removeCurrency(string type, double amount)
{
    cout << "removeCurrencyMYK version" << endl;
    if (amount < 0)
    {
        return false;
    }
    if (currencies.count(type) == 0) // not there yet
    {
        // cout << "No currency for " << type << endl;
        return false;
    }
    else
    {                                       // is there - do  we have enough
        if (containsCurrency(type, amount)) // we have enough
        {
            // cout << "Removing " << type << ": " << amount << endl;
            currencies[type] -= amount;
            return true;
        }
        else // they have it but not enough.
            return false;
    }
}

bool Wallet::containsCurrency(string type, double amount)
{
    cout << "containsCurrencyMYK version" << endl;
    if (currencies.count(type) == 0) // not there yet
        return false;
    else
        return currencies[type] >= amount;
}

string Wallet::toString()
{
    string s;
    for (pair<string, double> pair : currencies)
    {
        string currency = pair.first;
        double amount = pair.second;
        s += currency + " : " + to_string(amount) + "\n";
    }
    return s;
}

ostream &operator<<(ostream &os, Wallet &wallet)
{
    os << wallet.toString();
    return os;
}
bool Wallet::canFulfillOrder(OrderBookEntry order)
{
    vector<string> currs = CSVReader::tokenise(order.product, '/');
    if (order.orderType == OrderBookType::ask)
    {
        double amount = order.amount;
        string currency = currs[0];
        cout << "Wallet::canFulfillOrder " << currency << " : " << amount << endl;
        return containsCurrency(currency, amount);
    }
    if (order.orderType == OrderBookType::bid)
    {
        double amount = order.amount * order.price;
        string currency = currs[1];
        cout << "Wallet::canFulfillOrder " << currency << " : " << amount << endl;
        return containsCurrency(currency, amount);
    }

    return false;
}
void Wallet::processSale(OrderBookEntry &sale)
{
    vector<string> currs = CSVReader::tokenise(sale.product, '/');
    if (sale.orderType == OrderBookType::asksale)
    {
        double outgoingAmount = sale.amount;
        string outgoingCurrency = currs[0];
        double incomingAmount = sale.amount * sale.price;
        string incomingCurrency = currs[1];
        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
    if (sale.orderType == OrderBookType::bidsale)
    {
        double incomingAmount = sale.amount;
        string incomingCurrency = currs[0];
        double outgoingAmount = sale.amount * sale.price;
        string outgoingCurrency = currs[1];
        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
}