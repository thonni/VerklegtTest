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
    string location;
    unsigned int choiceToInt;
    bool validInput = false;
    vector<Location> availableLocations = locationService.getLocations();
    string choice;

    do
    {
        //Clear the screen
        cout << string(50, '\n');

        for(unsigned int i = 0; i < availableLocations.size(); i++)
        {
            this->deliveryLocation = availableLocations.at(i);
            cout << (i) << ": " << deliveryLocation.getAddress() << ", " << deliveryLocation.getCity() << endl;
        }

        cout << "Please choose your location." << endl;
        cout << "Choose B to go Back." << endl;
        cin >> location;

        //Change the location to int and store in another variable
        choiceToInt = 0;
        for(unsigned int i = 0; i < location.length(); i++)
        {
            choiceToInt *= 10;
            choiceToInt += (int)location[i] - '0';
        }

        if(choiceToInt < availableLocations.size())
        {
                this->deliveryLocation = availableLocations.at(choiceToInt);
                validInput = true;
        }

        if(toupper(location[0]) == 'B')
        {
            validInput = true;
        }
    } while(validInput != true );

    /// Here the program prints out all orders to be delivered
    //orderService.getOrders();
    if (toupper(location[0]) != 'B')
    {
        do
        {
            //Clear the screen
            cout << string(50, '\n');

            cout << "Welcome Delivery person" << endl << endl;

            cout << "Choose R to see orders Ready to be delivered or being delivered" << endl;
            cout << "Choose O to see all Orders for this location" << endl;
            cout << "Choose Q to Quit" << endl;
            cout << ": ";
            cin >> choice;
            if (toupper(choice[0]) == 'R')
            {
                this->seeOrdersToBeDelivered();
            }
            else if(toupper(choice[0]) == 'O')
            {
                this->seeAllOrders();
            }
        } while(toupper(choice[0]) != 'Q');
    }
}


void UI_Delivery::seeOrdersToBeDelivered()
{
    string choice;
    unsigned int choiceToInt;
    bool validInput;
    unsigned int numberOfOrders;
    vector<Order> allOrders = orderService.getOrders();
    vector<Order> validOrders;
    Order tempOrder;

    //Count the amount of orders for the chosen location and in a valid state,
    //and store those orders in the validOrders vector.
    numberOfOrders = 0;
    for(unsigned int i = 0; i < allOrders.size(); i++)
    {
        //Stores the current order in a temporary order variable.
        tempOrder = allOrders.at(i);

        //Check if the current order is at the chosen location and in a valid state for the baker.
        if(tempOrder.getLocation().getId() == this->deliveryLocation.getId() && (int)tempOrder.getState() >= 3 && (int)tempOrder.getState() < 5 && tempOrder.getHomeDelivery())
        {
            validOrders.push_back(tempOrder);
            numberOfOrders++;
        }
    }

    do
    {
        validInput = false;

        //Clear the screen
        cout << string(50, '\n');
        //Use printOutOrders to print out all the orders on the screen
        //in a nice fashion, and store the number of orders that it returns.
        this->printOutOrders(validOrders);

        if(numberOfOrders > 0)
        {
            cout << "Select an order to view" << endl;
            cout << "Or choose B to go Back" << endl;
            cout << ": ";
            cin >> choice;

            //Change the choice to int and store in another variable
            choiceToInt = 0;
            for(unsigned int i = 0; i < choice.length(); i++)
            {
                choiceToInt *= 10;
                choiceToInt += (int)choice[i] - '0';
            }

            //Check if the choice was in range of validOrders
            if(choiceToInt < numberOfOrders)
            {
                //Store the chosen order in a temporary Order variable and use it
                //as an argument in this->changeActiveOrder.
                tempOrder = validOrders.at(choiceToInt);
                this->changeDeliveryOrder(tempOrder);

                validInput = true;
            }
            else if(toupper(choice[0]) == 'B')
            {
                validInput = true;
            }
        }
        else
        {
            //If there are no orders waiting this message comes up.
            do
            {
                //Clear the screen
                cout << string(50, '\n');

                cout << "Nothing here!" << endl << endl;
                cout << "----------------------------------------" << endl;
                cout << "Choose B to go Back" << endl;
                cout << ": ";
                cin >> choice;
            } while(toupper(choice[0]) != 'B');
            validInput = true;
        }

    } while(!validInput);

}

void UI_Delivery::changeDeliveryOrder(Order tempOrder)
{
    char choice;
    do
    {
        //Clear the screen
        cout << string(50, '\n');

        this->printOutOrder(tempOrder);
        if(tempOrder.getState() == Order::Delivered && !tempOrder.getPaidFor())
        {
            char paymentMethod;
            cout << "Do you wish to pay with card or cash?" << endl;
            cout << "Choose 1 to pay with card" << endl;
            cout << "Choose 2 to pay with cash" << endl;
            cin >> paymentMethod;
            orderService.setOrderPaid(tempOrder.getId());
            tempOrder.setPaidFor(true);
            choice = 'M';
        }
        else
        {
            cout << "Choose M to Move the order to the next state" << endl;
            cout << "READY -> ON ITS WAY -> DELIVERED" << endl;
            cout << "Or choose B to go Back" << endl;
            cout << ": ";
            cin >> choice;
        }

        //Check if the choice was in range of validOrders
        if(toupper(choice) == 'M')
        {
            //Change the order state depending on what it is.
            if(tempOrder.getState() == Order::Ready)
            {
                orderService.setOrderState(tempOrder.getId(), Order::OnItsWay);
                tempOrder.setState(Order::OnItsWay);
            }
            else if(tempOrder.getState() == Order::OnItsWay)
            {
                orderService.setOrderState(tempOrder.getId(), Order::Delivered);
                tempOrder.setState(Order::Delivered);
            }
        }
    } while(toupper(choice) != 'B');
}


void UI_Delivery::printOutOrders(vector<Order> validOrders)
{
    Order tempOrder;
    Pizza tempPizza;
    Extra tempExtra;
    Topping tempTopping;
    unsigned int amountOfPizzas = 0;
    unsigned int amountOfSideDishes = 0;
    unsigned int amountOfDrinks = 0;
    unsigned int amountOfSauces = 0;

    //Loops through all orders, if there are any.
    if(validOrders.size() > 0)
    {
        for(unsigned int i = 0; i < validOrders.size(); i++)
        {
            //Stores the current order in a temporary order variable.
            tempOrder = validOrders.at(i);

            //Gets the amount of pizzas.
            amountOfPizzas = tempOrder.getPizzas().size();

            //Gets the amount of extras.
            for(unsigned int j = 0; j < tempOrder.getExtras().size(); j++)
            {
                tempExtra = tempOrder.getExtras().at(j);
                if(tempExtra.getType() == Extra::SideDish)
                {
                    amountOfSideDishes++;
                }
                if(tempExtra.getType() == Extra::Drink)
                {
                    amountOfDrinks++;
                }
                if(tempExtra.getType() == Extra::Sauce)
                {
                    amountOfSauces++;
                }
            }

            //Print out the order info: Id, amount of pizzas, and amount of side dishes.
            cout << "#" << i <</* " - ID: " << tempOrder.getId() <<*/ " - " << "Pizzas: " << amountOfPizzas << ", Side dishes: " << amountOfSideDishes << ", Drinks: "  << amountOfDrinks << ", Sauces: " << amountOfSauces << ", " ;
            //Print out the state of the order.
            if(tempOrder.getState() == Order::Ready && tempOrder.getHomeDelivery())
            {
                cout << " READY TO DELIVER,";
            }
            else if(tempOrder.getState() == Order::Ready)
            {
                cout << " READY,";
            }
            else if(tempOrder.getState() == Order::OnItsWay)
            {
                cout << " ON ITS WAY,";
            }
            else if(tempOrder.getState() == Order::Delivered)
            {
                cout << " DELIVERED,";
            }
            if(tempOrder.getPaidFor())
            {
                cout << " PAID" << endl;
            }
            else
            {
                cout << " NOT PAID" << endl;
            }

            cout << "--------------------------------------------------------------------------------" << endl;
        }
    }
}

void UI_Delivery::printOutOrder(Order tempOrder)
{
    unsigned int amountOfPizzas = 0;
    unsigned int amountOfSideDishes = 0;
    unsigned int amountOfDrinks = 0;
    unsigned int amountOfSauces = 0;
    Pizza tempPizza;
    Topping tempTopping;
    Extra tempExtra;

    //Stores the current order in a temporary order variable.
    amountOfPizzas = tempOrder.getPizzas().size();

    //Gets the amount of extras.
    for(unsigned int j = 0; j < tempOrder.getExtras().size(); j++)
    {
        tempExtra = tempOrder.getExtras().at(j);
        if(tempExtra.getType() == Extra::SideDish)
        {
            amountOfSideDishes++;
        }
        if(tempExtra.getType() == Extra::Drink)
        {
            amountOfDrinks++;
        }
        if(tempExtra.getType() == Extra::Sauce)
        {
            amountOfSauces++;
        }
    }

    //Print out the order info: Id, amount of pizzas, and amount of side dishes.
    cout << "ID: " << tempOrder.getId() << " - " << "Pizzas: " << amountOfPizzas << ", Side dishes: " << amountOfSideDishes << ", Drinks: "  << amountOfDrinks << ", Sauces: " << amountOfSauces << ", " ;
    //Print out the state of the order.
    if(tempOrder.getState() == Order::Ready && tempOrder.getHomeDelivery())
    {
        cout << " READY TO DELIVER,";
    }
    else if(tempOrder.getState() == Order::Ready)
    {
        cout << " READY,";
    }
    else if(tempOrder.getState() == Order::OnItsWay)
    {
        cout << " ON ITS WAY,";
    }
    else if(tempOrder.getState() == Order::Delivered)
    {
        cout << " DELIVERED,";
    }
    if(tempOrder.getPaidFor())
    {
        cout << " PAID" << endl;
    }
    else
    {
        cout << " NOT PAID" << endl;
    }
    cout << "Comment: " << tempOrder.getComment() << endl;

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
        for(unsigned int j = 0; j < tempOrder.getExtras().size(); j++)
        {
            //Store the current extra in a temporary extra variable.
            tempExtra = tempOrder.getExtras().at(j);

            //If the extra is a side dish, it prints out the name of it.
            if(tempExtra.getType() == Extra::SideDish)
            {
                cout << "  *" << tempExtra.getName() << endl;
            }
        }
    }
    if(amountOfDrinks > 0)
    {
        cout << " DRINKS:" << endl;
        for(unsigned int j = 0; j < tempOrder.getExtras().size(); j++)
        {
            //Store the current extra in a temporary extra variable.
            tempExtra = tempOrder.getExtras().at(j);

            //If the extra is a side dish, it prints out the name of it.
            if(tempExtra.getType() == Extra::Drink)
            {
                cout << "  *" << tempExtra.getName() << endl;
            }
        }
    }
    if(amountOfSauces > 0)
    {
        cout << " SAUCES:" << endl;
        for(unsigned int j = 0; j < tempOrder.getExtras().size(); j++)
        {
            //Store the current extra in a temporary extra variable.
            tempExtra = tempOrder.getExtras().at(j);

            //If the extra is a side dish, it prints out the name of it.
            if(tempExtra.getType() == Extra::Sauce)
            {
                cout << "  *" << tempExtra.getName() << endl;
            }
        }
    }
    cout << "--------------------------------------------------------------------------------" << endl;
}

void UI_Delivery::seeAllOrders()
{
    vector<Order> allOrders = orderService.getOrders();
    vector<Order> validOrders;
    Order tempOrd;
    Order tempOrder;
    Pizza tempPizza;
    Extra tempExtra;
    Topping tempTopping;
    unsigned int amountOfPizzas = 0;
    unsigned int amountOfSideDishes = 0;
    unsigned int amountOfDrinks = 0;
    unsigned int amountOfSauces = 0;
    string choice;

    //Count the amount of orders for the chosen location and in a valid state,
    //and store those orders in the validOrders vector.
    unsigned int numberOfOrders = 0;
    do
    {
        //Clear the screen
        cout << string(50, '\n');

        for(unsigned int i = 0; i < allOrders.size(); i++)
        {
            //Stores the current order in a temporary order variable.
            tempOrd = allOrders.at(i);

            //Check if the current order is at the chosen location and in a valid state for the baker.
            if(tempOrd.getLocation().getId() == this->deliveryLocation.getId())
            {
                validOrders.push_back(tempOrd);
                numberOfOrders++;
            }
        }


        //Loops through all orders, if there are any.
        if(validOrders.size() > 0)
        {
            for(unsigned int i = 0; i < validOrders.size(); i++)
            {
                //Stores the current order in a temporary order variable.
                tempOrder = validOrders.at(i);

                //Gets the amount of pizzas.
                amountOfPizzas = tempOrder.getPizzas().size();

                //Gets the amount of extras.
                for(unsigned int j = 0; j < tempOrder.getExtras().size(); j++)
                {
                    tempExtra = tempOrder.getExtras().at(j);
                    if(tempExtra.getType() == Extra::SideDish)
                    {
                        amountOfSideDishes++;
                    }
                    if(tempExtra.getType() == Extra::Drink)
                    {
                        amountOfDrinks++;
                    }
                    if(tempExtra.getType() == Extra::Sauce)
                    {
                        amountOfSauces++;
                    }
                }

                //Print out the order info: Id, amount of pizzas, and amount of side dishes.
                cout << "ID: " << tempOrder.getId() << " - " << "Pizzas: " << amountOfPizzas << ", Side dishes: " << amountOfSideDishes << ", Drinks: "  << amountOfDrinks << ", Sauces: " << amountOfSauces << ", " ;
                //Print out the state of the order.
                if(tempOrder.getState() == Order::Received)
                {
                    cout << " RECEIVED,";
                }
                else if(tempOrder.getState() == Order::Prep)
                {
                    cout << " PREP,";
                }
                else if(tempOrder.getState() == Order::InOven)
                {
                    cout << " IN OVEN,";
                }
                else if(tempOrder.getState() == Order::Ready && tempOrder.getHomeDelivery())
                {
                    cout << " READY TO DELIVER,";
                }
                else if(tempOrder.getState() == Order::Ready)
                {
                    cout << " READY,";
                }
                else if(tempOrder.getState() == Order::OnItsWay)
                {
                    cout << " ON ITS WAY,";
                }
                else if(tempOrder.getState() == Order::Delivered)
                {
                    cout << "DELIVERED,";
                }
                if(tempOrder.getPaidFor())
                {
                    cout << " PAID" << endl;
                }
                else
                {
                    cout << " NOT PAID" << endl;
                }
            }
        }
        cout << endl << "Choose B to go Back" << endl;
        cout << ": ";
        cin >> choice;
    } while(toupper(choice[0]) != 'B');
}

