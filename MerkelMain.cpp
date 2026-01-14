#include "MerkelMain.h"

MerkelMain::MerkelMain()
{
}

void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu()
{
    // 1 print help
    cout << "1: Print help " << endl;
    // 2 print exchange stats
    cout << "2: Print exchange stats" << endl;
    // 3 make an offer
    cout << "3: Make an ask " << endl;
    // 4 make a bid
    cout << "4: Make a bid " << endl;
    // 5 print wallet
    cout << "5: Print wallet " << endl;
    // 6 continue
    cout << "6: Continue " << endl;

    cout << "============== " << endl;

    cout << "Current time is: " << currentTime << endl;
}

void MerkelMain::printHelp()
{
    cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << endl;
}

void MerkelMain::printMarketStats()
{
    for (string const &p : orderBook.getKnownProducts())
    {
        cout << "Product: " << p << endl;
        vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
                                                             p, currentTime);
        cout << "Asks seen: " << entries.size() << endl;
        cout << "Max ask: " << OrderBook::getHighPrice(entries) << endl;
        cout << "Min ask: " << OrderBook::getLowPrice(entries) << endl;
    }
}

void MerkelMain::enterAsk()
{
    cout << "Make an ask - enter the amount: product,price, amount, eg  ETH/BTC,200,0.5" << endl;
    string input;
    getline(cin, input);

    vector<string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        cout << "MerkelMain::enterAsk Bad input! " << input << endl;
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
                orderBook.insertOrder(obe);
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

void MerkelMain::enterBid()
{
    cout << "Placing an bid - enter the amount: product,price,amount eg ETH/BTC,200,0" << endl;
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
                OrderBookType::bid);
            obe.username = "simuser";
            if (wallet.canFulfillOrder(obe))
            {
                cout << "Wallet looks good. " << endl;
                orderBook.insertOrder(obe);
            }
            else
            {
                cout << "Wallet has insufficient funds. " << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "MerkelMain::placeBid Bad input " << endl;
        }
    }
}

void MerkelMain::printWallet()
{
    cout << wallet.toString() << endl;
}

void MerkelMain::gotoNextTimeframe()
{
    cout << "Going to next time frame. " << endl;
    for (string p : orderBook.getKnownProducts())
    {
        cout << "matching" << p << endl;
        vector<OrderBookEntry> sales = orderBook.matchAsksToBids(p, currentTime);
        cout << "Sales: " << sales.size() << endl;
        for (OrderBookEntry &sale : sales)
        {
            cout << "Sale price: " << sale.price << " amount " << sale.amount << endl;
            if (sale.username == "simuser")
            {
                wallet.processSale(sale);
            }
        }
    }
    currentTime = orderBook.getNextTime(currentTime);
}

int MerkelMain::getUserOption()
{
    int userOption = 0;
    string line;
    cout << "Type in 1-6" << endl;
    getline(cin, line);
    try
    {
        userOption = stoi(line);
    }
    catch (const exception &e)
    {
        //
    }
    cout << "You chose: " << userOption << endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption)
{
    if (userOption == 0) // bad input
    {
        cout << "Invalid choice. Choose 1-6" << endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterAsk();
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
        gotoNextTimeframe();
    }
}
