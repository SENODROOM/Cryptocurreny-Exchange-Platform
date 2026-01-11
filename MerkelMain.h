#pragma once

#include <vector>
#include "OrderBookEntry.h"

class MerkelMain
{
public:
    MerkelMain();
    void init();

private:
    vector<OrderBookEntry> orders;
    void printMenu();
    void loadOrderBook();
    int getUserOption();
    void printHelp();
    void printMarketStats();
    void placeAsk();
    void placeBid();
    void printWallet();
    void nextTimeFrame();
    void processUserOption(int userOption);
};