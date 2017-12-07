#include "UI_Baker.h"

UI_Baker::UI_Baker()
{
    //ctor
}

UI_Baker::~UI_Baker()
{
    //dtor
}

void UI_Baker::startUI()
{
    int orderID;
    char location, orderMark;
    bool noID = false;
    //Clear the screen
    cout << string(50, '\n');
    cout << "Welcome baker" << endl << endl;

    cout << "Please choose your location." << endl;
    cout << "Choose B to go back." << endl;

    /// Here the user inputs their location and the program will print out the unfinished orders for that location and their status
    cin >> location;
    orderService.getOrders();

    cout << "Input the ID of an order to make." << endl;
    cin >> orderID;
    try
    {
        order = orderService.getOrder(orderID);
    }
    catch(int e)
    {
        if(e == 0)
        {
            cout << "No Such ID could be found...";
            noID = true;
        }
    }
    while(toupper(orderMark) != 'B' || noID)
    {
        cout << "Please mark the order appropriately." << endl;
        cout << "Input P when the order is in Prep." << endl;
        cout << "Input O when the order is in Oven." << endl;
        cout << "Input R when the order is Ready." << endl;
        cout << "Choose B to go Back." << endl;
        cin >> orderMark;
        if (toupper(orderMark) == 'P')
        {
            // The number of order they choose gets marked "Prep" in the file.
            order.setState(Order::Prep);
            orderService.setOrderState(order);
        }
        else if (toupper(orderMark) == 'O')
        {
            // The number of order they choose gets marked "InOven" in the file.
            order.setState(Order::InOven);
            orderService.setOrderState(order);
        }
        else if (toupper(orderMark) == 'R')
        {
            // The number of order they choose gets marked "Ready" in the file.
            order.setState(Order::Ready);
            orderService.setOrderState(order);
        }
        else
        {
            // Error message
            cout << "Invalid input!" << endl;
        }
    }
}
