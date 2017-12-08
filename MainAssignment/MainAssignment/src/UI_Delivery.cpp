#include "UI_Delivery.h"

UI_Delivery::UI_Delivery()
{
    //ctor
}

UI_Delivery::~UI_Delivery()
{
    //dtor
}

void UI_Delivery::deliveryMenu()
{
    int location, orderID;
    char orderMark;
    bool noID = false, goBack = false;

    cout << string(50, '\n');
    locations = locationService.getLocations();
    int locSize = locations.size();

    do
    {
        cout << "Please choose your location." << endl;
        cout << "Choose 0 to go back." << endl;

        for(unsigned int i = 0; i < locations.size(); i++)
        {
            cout << (i + 1) << ": " << locations.at(i).getAddress() << " - " << locations.at(i).getCity() << endl;
        }
        cin >> location;
    } while(location < 0 || location > locSize);

    if(location == 0)
    {
        goBack = true;
    }

    /// Here the user inputs their location and the program will print out the orders for that location and their status
    /// The orders will be sorted by their status.

    if(!goBack)
    {
        orderService.getOrders();

        cout << "Input the ID of an order to deliver." << endl;
        cin >> orderID;
        //orderID = locations[orderID-1].getId();
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
        while(toupper(orderMark) != 'B')
        {
            if(noID)
            {
                cin >> orderMark;
                break;
            }
            cout << "Please choose a payment method." << endl;
            // card or cash.

            cout << "Please mark the order appropriately." << endl;
            cout << "Input O when the order is on its way" << endl;
            cout << "Input D when the order is delivered." << endl;
            cout << "Choose B to go back." << endl;
            cin >> orderMark;
            if (orderMark == 'O')
            {
                /// The number of order they choose gets marked "on its way" in the file.
            }
            else if (orderMark == 'D')
            {
                /// The number of order they choose gets marked "delivered" in the file.
            }
            else
            {
                // Error message
                cout << "Invalid input!" << endl;
            }
        }
    }

    /*
    /// Here it would be kind of cool to get the "O" option only if the orer is to be home delivered. If it's picked up, only the D option would show.
    /// Also, if it's picked up, they payment method choice would appear first, but if it's home delivered, thar option would appear after the order is market "on its way"
    cout << "Please choose a payment method." << endl;
    // card or cash.

    cout << "Please mark the order appropriately." << endl;
    cout << "Input O when the order is on its way" << endl;
    cout << "Input D when the order is delivered." << endl;
    cout << "Choose B to go back." << endl;
    cin >> orderMark;
    if (orderMark == 'O')
    {
        /// The number of order they choose gets marked "on its way" in the file.
    }
    else if (orderMark == 'D')
    {
        /// The number of order they choose gets marked "delivered" in the file.
    }*/
}
