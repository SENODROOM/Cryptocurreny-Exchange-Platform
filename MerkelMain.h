class MerkelMain
{
public:
    MerkelMain();
    void init();
    void printMenu();
    int getUserOption();
    void printHelp();
    void printMarketStats();
    void placeAsk();
    void placeBid();
    void printWallet();
    void nextTimeFrame();
    void processUserOption(int userOption);
};