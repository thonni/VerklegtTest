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
    unsigned int choiceToInt;
    bool validInput;
    vector<Location> availableLocations = locationService.getLocations();


    do
    {
        validInput = false;

        //Clear the screen
        cout << string(50, '\n');

        //Loop through and print out all available locations.
        for(unsigned int i = 0; i < availableLocations.size(); i++)
        {
            this->bakerLocation = availableLocations.at(i);

            cout << i << " - " << this->bakerLocation.getAddress() << "  " << this->bakerLocation.getCity() << endl;
        }
        cout << "Choose B to go Back" << endl;
        cout << "Please choose the location you work at: ";
        cin >> choice;

        //Change the choice to int and store in another variable
        choiceToInt = (unsigned int)(choice - '0');
        if(toupper(choice) == 'B')
        {
            validInput = true;
        }
        else if(choiceToInt < availableLocations.size())
        {
            this->bakerLocation = availableLocations.at(choiceToInt);
            validInput = true;
        }

    } while(!validInput);

    if(toupper(choice) != 'B')
    {
        do
        {
            //Clear the screen
            cout << string(50, '\n');

            cout << "Welcome Baker" << endl << endl;

            cout << "Choose A to see/change Active orders" << endl;
            cout << "Choose O to see all Orders" << endl;
            cout << "Choose Q to Quit" << endl;
            cout << ": ";
            cin >> choice;


            if(toupper(choice) == 'A')
            {
                this->seeActiveOrders();
            }
            else if(toupper(choice) == 'O')
            {
                this->seeAllOrders();
            }

        } while(toupper(choice) != 'Q');
    }

}


void UI_Baker::seeActiveOrders()
{
    char choice;
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
        if(tempOrder.getLocation().getId() == this->bakerLocation.getId() && (int)tempOrder.getState() < 3)
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
        //in a nice fashion.
        this->printOutOrders(validOrders);

        if(numberOfOrders > 0)
        {
            cout << "Select an order to view" << endl;
            cout << "Or choose B to go Back" << endl;
            cout << ": ";
            cin >> choice;

            //Change the choice character to int and store in choiceToInt.
            choiceToInt = (unsigned int)(choice - '0');

            //Check if the choice was in range of validOrders
            if(choiceToInt < numberOfOrders)
            {

                //Store the chosen order in a temporary Order variable and use it
                //as an argument in this->changeActiveOrder.
                tempOrder = validOrders.at(choiceToInt);
                this->changeActiveOrder(tempOrder);

                validInput = true;
            }
            else if(toupper(choice) == 'B')
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
            } while(toupper(choice) != 'B');
            validInput = true;
        }

    } while(!validInput);

}


void UI_Baker::changeActiveOrder(Order order)
{
    char choice;
    bool validInput;


    do
    {
        //Clear the screen
        cout << string(50, '\n');

        this->printOutOrder(order);

        cout << endl;
        cout << "Choose M to Move the order to the next state" << endl;
        cout << "RECEIVED->PREP->IN OVEN->READY" << endl;
        cout << "Or choose B to go Back" << endl;
        cout << ": ";
        cin >> choice;

        if(toupper(choice) == 'M')
        {
            //Change the order state depending on what it is.
            if(order.getState() == Order::Received)
            {
                orderService.setOrderState(order.getId(), Order::Prep);
            }
            else if(order.getState() == Order::Prep)
            {
                orderService.setOrderState(order.getId(), Order::InOven);
            }
            else if(order.getState() == Order::InOven)
            {
                orderService.setOrderState(order.getId(), Order::Ready);
            }

            validInput = true;
        }
        else if(toupper(choice) == 'B')
        {
            validInput = true;
        }

    } while(!validInput);
}


void UI_Baker::seeAllOrders()
{
    char choice;


    do
    {
        //Clear the screen
        cout << string(50, '\n');

        //Print out all orders from file using a function in OrderService.
        orderService.printOutAllOrders();

        cout << endl << "Choose B to go Back" << endl;
        cout << ": ";
        cin >> choice;

    } while(toupper(choice) != 'B');
}


void UI_Baker::printOutOrders(vector<Order> validOrders)
{
    Order tempOrder;
    Pizza tempPizza;
    Extra tempExtra;
    Topping tempTopping;
    unsigned int amountOfPizzas = 0;
    unsigned int amountOfSideDishes = 0;


    //Loops through all orders, if there are any.
    if(validOrders.size() > 0)
    {
        for(unsigned int i = 0; i < validOrders.size(); i++)
        {
            //Stores the current order in a temporary order variable.
            tempOrder = validOrders.at(i);

            //Gets the amount of pizzas.
            amountOfPizzas = tempOrder.getPizzas().size();

            //Gets the amount of sideDishes.
            amountOfSideDishes = tempOrder.getAmountOfSideDishes();

            //Print out the order info: Id, amount of pizzas, and amount of side dishes.
            cout << i << " - ID: " << tempOrder.getId() << " - " << amountOfPizzas << " Pizzas and " << amountOfSideDishes << " Side dishes ";
            //Print out the state of the order.
            if(tempOrder.getState() == Order::Received)
            {
                cout << " RECEIVED" << endl;
            }
            else if(tempOrder.getState() == Order::Prep)
            {
                cout << " PREP" << endl;
            }
            else if(tempOrder.getState() == Order::InOven)
            {
                cout << "IN OVEN" << endl;
            }

            cout << "----------------------------------------" << endl;
        }
    }
}


void UI_Baker::printOutOrder(Order order)
{
    int amountOfPizzas = 0;
    int amountOfSideDishes = 0;
    Pizza tempPizza;
    Topping tempTopping;
    Extra tempExtra;

    //Gets the amount of pizzas.
    amountOfPizzas = order.getPizzas().size();

    //Gets the amount of sideDishes.
    amountOfSideDishes = order.getAmountOfSideDishes();

    //Print out the order ID, amount of pizzas and amount of side dishes.
    cout << "ID: " << order.getId() << ", Pizzas: " << amountOfPizzas << ", Side dishes: " << amountOfSideDishes;
    //Print out the state of the order.
    if(order.getState() == Order::Received)
    {
        cout << " RECEIVED" << endl;
    }
    else if(order.getState() == Order::Prep)
    {
        cout << " PREP" << endl;
    }
    else if(order.getState() == Order::InOven)
    {
        cout << " IN OVEN" << endl;
    }

    //Loop through all the pizzas if there are any.
    if(amountOfPizzas > 0)
    {
        cout << " PIZZAS: " << endl;
        for(unsigned int i = 0; i < order.getPizzas().size(); i++)
        {
            //Store the current pizza in a temporary pizza variable.
            tempPizza = order.getPizzas().at(i);

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

    //Loop through all the side dishes if there are any.
    if(amountOfSideDishes > 0)
    {
        cout << " SIDE DISHES:" << endl;
        for(unsigned int j = 0; j < order.getExtras().size(); j++)
        {
            //Store the current extra in a temporary extra variable.
            tempExtra = order.getExtras().at(j);

            //If the extra is a side dish, it prints out the name of it.
            if(tempExtra.getType() == Extra::SideDish)
            {
                cout << "  *" << tempExtra.getName() << endl;
            }
        }
    }

    cout << "----------------------------------------" << endl;
}
