#include "UI_Baker.h"

UI_Baker::UI_Baker()
{
    //ctor
}

UI_Baker::~UI_Baker()
{
    //dtor
}

void bakerMenu()
{
    int location, orderNumber;
    char orderMark;
    cout << "Please choose your location." << endl;
    cout << "Choose B to go back." << endl;

    cin >> location;
    /// Here the user inputs their location and the program will print out the unfinished orders for that location and their status

    cout << "Input a number of an order to make." << endl;
    cin >> orderNumber;

    cout << "Please mark the order appropriately." << endl;
    cout << "Input P when the order is in progress." << endl;
    cout << "Input F when the order is finished." << endl;
    cout << "Choose B to go back." << endl;
    cin >> orderMark;
    if (orderMark == 'P')
    {
        /// The number of order they choose gets marked "in progress" in the file.
    }
    else if (orderMark == 'F')
    {
        /// The number of order they choose gets marked "in progress" in the file.
    }
}
