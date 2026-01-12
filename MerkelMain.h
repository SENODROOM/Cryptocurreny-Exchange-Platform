#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class MerkelMain
{
public:
    MerkelMain();
    void init();

private:
    void printMenu();
    int getUserOption();
    void printHelp();
    void printMarketStats();
    void placeAsk();
    void placeBid();
    void printWallet();
    void nextTimeFrame();
    void processUserOption(int userOption);
    std::string currentTime;
    OrderBook OrderBook{"20200317.csv"};
};