#include <iostream>
using namespace std;
int main()
{
    cout << "1: Print Help " << endl;
    cout << "2: Print Exchange stats " << endl;
    cout << "3: Make an offer " << endl;
    cout << "4: Make a bid " << endl;
    cout << "5: Print wallet " << endl;
    cout << "6: Continue " << endl;
    cout << "================" << endl;
    cout << "Type in 1-6" << endl;

    int userOption;
    cin >> userOption;
    cout << "You choose: " << userOption << endl;
    if (userOption==0)
    {
        cout<<"Invalid choice. Choose 1-6"<<endl;
    }
    if (userOption==1)
    {
        cout<<"Help - your aim is to make money. Analyze the market and make bids and offers "<<endl;
    }
    if (userOption==2)
    {
        cout<<"Market looks good"<<endl;
    }
    if (userOption==3)
    {
        cout<<"Mark an offer - enter the amount"<<endl;
    }
    if (userOption==4)
    {
        cout<<"Mark a bid - enter the amount"<<endl;
    }
    if (userOption==5)
    {
        cout<<"Your wallet is empty"<<endl;
    }
    if (userOption==6)
    {
        cout<<"Going to next time frame"<<endl;
    }
    
    return 0;
}