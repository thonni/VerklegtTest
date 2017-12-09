#include "UI_Baker.h"

using namespace std;

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
    int orderID, location;
    char orderMark;
    bool noID = false, goBack = false;
    vector<Order> orders;
    //Clear the screen
    cout << string(50, '\n');
    cout << "Welcome baker" << endl << endl;

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
    if(!goBack)
    {
        vector<Pizza> pizzas;
        vector<Topping> toppings;
        orders = orderService.getOrders();
        for(unsigned int i = 0; i < orders.size(); i++)
        {
            if(orders[i].getLocation().getId() == locations[location - 1].getId())
            {
                cout << "Order ID: " << i << endl;
                cout << "Order state: " << orders[i].getState() << endl;
                pizzas = orders[i].getPizzas();
                cout << "- Pizzas: " << endl;
                for(unsigned int j = 0; j < pizzas.size(); j++)
                {
                    cout << "-- " << pizzas[j].getName() << endl;
                    toppings = pizzas[j].getToppings();
                    for(unsigned int y = 0; y < toppings.size(); y++)
                    {
                        cout << "--- " << toppings[y].getName() << endl;
                    }
                }
            }
        }

        cout << "Input the ID of an order to make." << endl;
        cin >> orderID;
        //orderID = locations[orderID-1].getId();
        try
        {
            order = orderService.getOrder(orders[orderID].getId());
        }
        catch(int e)
        {
            if(e == 0)
            {
                cout << "No Such ID could be found..." << endl;
                noID = true;
            }
        }
        orderMark = 'a';
        while(toupper(orderMark) != 'B')
        {
            if(noID)
            {
                cin >> orderMark;
                break;
            }
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

}
