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

    char choice;
    this->orders = orderService.getOrders();

    this->printOutOrders();
    cin >> choice;

















    /*int orderID, location;
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
<<<<<<< HEAD
        this->printOutOrders(orders);s
=======
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
>>>>>>> ad3360859cb85c13f11d2d09e18c4f23efd6e2ae

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
    }*/

}


void UI_Baker::printOutOrders()
{
    Order tempOrder;
    Pizza tempPizza;
    Extra tempExtra;
    Topping tempTopping;
    unsigned int amountOfPizzas = 0;
    unsigned int amountOfSideDishes = 0;

    //Loops through all orders.
    for(unsigned int i = 0; i < this->orders.size(); i++)
    {
        //Stores the current order in a temporary order variable.
        tempOrder = this->orders.at(i);

        //Gets the amount of pizzas.
        amountOfPizzas = tempOrder.getPizzas().size();

        //Gets the amount of sideDishes.
        for(unsigned int j = 0; j < tempOrder.getExtras().size(); j++)
        {
            tempExtra = tempOrder.getExtras().at(j);
            if(tempExtra.getType() == Extra::SideDish)
            {
                amountOfSideDishes++;
            }
        }

        //Print out the order info: Id, amount of pizzas, and amount of side dishes.
        cout << i << " - ID: " << tempOrder.getId() << " - " << amountOfPizzas << " Pizzas and " << amountOfSideDishes << " Side dishes" << endl;
        //Loop through all the pizzas if there are any.
        if(amountOfPizzas > 0)
        {
            cout << " PIZZAS: " << endl;
            for(unsigned int y = 0; y < tempOrder.getPizzas().size(); y++)
            {
                //Store the current pizza in a temporary pizza variable.
                tempPizza = tempOrder.getPizzas().at(y);

                //Prints out the current pizza name.
                cout << "  *" << tempPizza.getName() << " - ";
                //Prints out the current pizza size.
                if(tempPizza.getSize() == Pizza::Small)
                {
                    cout << "Small, ";
                }
                else if(tempPizza.getSize() == Pizza::Medium)
                {
                    cout << "Medium, ";
                }
                else if(tempPizza.getSize() == Pizza::Large)
                {
                    cout << "Large, ";
                }
                //Prints out the current pizza base.
                cout << tempPizza.getBase().getName() << endl;

                //Check if the current pizza is a custom pizza, and if so it prints out its toppings.
                if(tempPizza.getName() == "Custom Pizza")
                {
                    cout << "   -Toppings - ";
                    //Loop through all the toppings on the current pizza.
                    for(unsigned int j = 0; j < tempPizza.getToppings().size(); j++)
                    {
                        //Store the current topping in a temporary topping variable.
                        tempTopping = tempPizza.getToppings().at(j);

                        cout << tempTopping.getName();

                        if(j != tempPizza.getToppings().size() - 1)
                        {
                            cout << ", ";
                        }
                    }
                    cout << endl;
                }
            }
        }

        //Loop through all the side dishes if there are any.
        if(amountOfSideDishes > 0)
        {
            cout << " SIDE DISHES:" << endl;
            for(unsigned int j = 0; j < this->orders.at(i).getExtras().size(); j++)
            {
                //Store the current extra in a temporary extra variable.
                tempExtra = this->orders.at(i).getExtras().at(j);

                cout << "  *" << tempExtra.getName() << endl;
            }
        }

        cout << "----------------------------------------" << endl;

    }
}
