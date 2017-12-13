#include "UI_Salesman.h"

using namespace std;

void UI_Salesman::startUI()
{
    char choice;

    do
    {
        //Clear the screen.
        cout << string(50, '\n');
        cout << "Welcome salesperson" << endl << endl;

        cout << "Choose O to take order" << endl;
        cout << "Choose V to view orders" << endl;
        cout << "Choose B to go back" << endl;
        cout << ": ";
        cin >> choice;

        if (toupper(choice) == 'O')
        {
            this->takeOrder();
        }
        else if (toupper(choice) == 'V')
        {
            this->viewOrders();
        }
        else if (toupper(choice) != 'F')
        {
            cout << "Invalid input!" << endl;
        }
    } while (toupper(choice) != 'B');
}



void UI_Salesman::takeOrder()
{
    char choice;
    bool orderFinished = false;
    Pizza tempPizza;

    //Create an instance of order and make it get an id.
    Order newOrder;
    newOrder.generateId();
    //set the state of the order to 'received'.
    newOrder.setState(Order::Received);

    do
    {

        //Make the order generate the total price of itself.
        newOrder.generatePrice();

        //Clear the screen.
        cout << string(50, '\n');

        cout << "Order creation" << endl << endl;

        cout << "Choose S to Select a pizza from the menu" << endl;
        cout << "Choose M to Make a Pizza from scratch" << endl;
        cout << "Choose E to add Extras" << endl;
        cout << "Choose R to Remove something from order" << endl;
        cout << "Choose F to Finish up the order" << endl;
        cout << "Choose C to Cancel order" << endl;
        cout << ": ";
        cin >> choice;

        if(toupper(choice) == 'S')
        {
            //Call the choosePizzaFromMenu function and add the pizza
            //it returns to newOrder only if the name of the pizza is not "N/A"
            //which means the pizza selection was canceled.
            tempPizza = this->choosePizzaFromMenu();
            if(tempPizza.getName() != "N/A")
            {
                newOrder.addPizza(tempPizza);
            }
        }
        else if(toupper(choice) == 'M')
        {
            //Call the makePizza function and add the pizza it returns
            //to newOrder only if the name of the pizza is not "N/A"
            //which means the pizza selection was canceled..
            tempPizza = this->makePizza();
            if(tempPizza.getName() != "N/A")
            {
                tempPizza.generatePrice();
                newOrder.addPizza(tempPizza);
            }
        }
        else if(toupper(choice) == 'E')
        {
            //Call the addExtra function
            //and add the Extra it returns to newOrder.
            newOrder.addExtra(this->chooseExtraFromMenu());
        }
        else if(toupper(choice) == 'R')
        {
            //Call the removeFromOrder function which
            //takes newOrder as an pointer argument.
            this->removeFromOrder(&newOrder);
        }
        else if(toupper(choice) == 'F')
        {
            //Call the finishUpOrder function which
            //takes newOrder as an pointer argument.
            //If the order was finished up it returns true.
            orderFinished = this->finishUpOrder(&newOrder);
        }

    } while(toupper(choice) != 'C' && orderFinished == false);
}


Pizza UI_Salesman::choosePizzaFromMenu()
{
    Pizza tempPizza;
    Topping tempTopping;
    Base tempBase;
    vector<Pizza> availablePizzas;
    vector<Base> availableBases;
    string selection = "0";
    unsigned int selectionAsInt = 0;
    Pizza newPizza("N/A", Pizza::Small);

    //Ask pizzaService for a vector of all pizzas that are on the menu.
    availablePizzas = pizzaService.getPizzas();
    //Ask baseService for a vector of all bases that are on the menu.
    availableBases = baseService.getBases();

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Loop trough all the pizzas on the menu and print their id, name, price
        //and also loop trough their toppings and print them out.
        cout << "****PIZZA MENU****" << endl;
        for(unsigned int i = 0; i < availablePizzas.size(); i++)
        {
            tempPizza = availablePizzas.at(i);
            cout << i << " - Name: " << tempPizza.getName() << " - Price of small: " << tempPizza.getPrice() << " KR" << endl;
            cout << "Toppings:" << endl;

            for(unsigned int j = 0; j < tempPizza.getToppings().size(); j++)
            {
                tempTopping = tempPizza.getToppings().at(j);
                cout << " *" << tempTopping.getName() << endl;
            }
            cout << endl;
        }
        cout << "Choose C to Cancel" << endl << endl;

        //Ask the user to select a pizza from the menu.
        cout << "Please select the id of the pizza to add: ";
        cin >> selection;

        //Store the selection as int in another variable.
        selectionAsInt = 0;
        for(unsigned int i = 0; i < selection.length(); i++)
        {
            selectionAsInt *= 10;
            selectionAsInt += (int)selection[i] - '0';
        }

    //Loop if selection is out of range and is not c or C for cancel.
    } while(!((selectionAsInt >= 0 && selectionAsInt < availablePizzas.size()) || toupper(selection[0]) == 'C'));


    if(toupper(selection[0]) != 'C')
    {
        //Set newPizza to the selected pizza if the selection was not canceled.
        newPizza = availablePizzas.at(selectionAsInt);

        do
        {
            //Clear the screen.
            cout << string(50, '\n');

            //Make the user select the size of the pizza.
            cout << "Please select the size of the pizza" << endl;
            cout << "Choose S for Small" << endl;
            cout << "Choose M for Medium" << endl;
            cout << "Choose L for Large" << endl;
            cout << ": ";
            cin >> selection[0];

            //Set the size of the pizza depending on the user input.
            if(toupper(selection[0]) == 'S')
            {
                newPizza.setSize(Pizza::Small);
            }
            else if(toupper(selection[0]) == 'M')
            {
                newPizza.setSize(Pizza::Medium);
            }
            else if(toupper(selection[0]) == 'L')
            {
                newPizza.setSize(Pizza::Large);
            }
            else
            {
                selection[0] = '0';
            }

          //Loop until a valid input is entered.
        } while(selection[0] == '0');

        do
        {
            //Clear the screen.
            cout << string(50, '\n');

            //Print out all available pizza bases.
            for(unsigned int i = 0; i < availableBases.size(); i++)
            {
                tempBase = availableBases.at(i);
                cout << i << " - Name: " << tempBase.getName() << " - price: " << tempBase.getPrice() << " Kr" << endl;
            }
            cout << "Please select the id of the pizza base to add: ";
            cin >> selection;


            //Store the selection as int in another variable.
            selectionAsInt = 0;
            for(unsigned int i = 0; i < selection.length(); i++)
            {
                selectionAsInt *= 10;
                selectionAsInt += (int)selection[i] - '0';
            }

            //Check if the selection is in the correct range.
            if((selectionAsInt >= 0 && selectionAsInt < availableBases.size()))
            {
                //Set the base to the selected base
                newPizza.setBase(availableBases.at(selectionAsInt));
                selection[0] = '/';
            }

          //Loop until a valid input is entered.
        } while(selection[0] != '/');
    }

    //Return the pizza.
    return newPizza;
}


Pizza UI_Salesman::makePizza()
{
    Topping tempTopping;
    Topping tempTopp;
    Base tempBase;
    vector<Topping> availableToppings;
    vector<Base> availableBases;
    string selection = "0";
    unsigned int selectionAsInt = 0;

    //Clear the screen.
    cout << string(50, '\n');

    //Ask toppingService for a vector of all toppings that are on the menu.
    availableToppings = toppingService.getToppings();
    sort(availableToppings.begin(), availableToppings.end());
    //Ask baseService for a vector of all bases that are on the menu.
    availableBases = baseService.getBases();

    //Create an instance of pizza using the name
    Pizza newPizza("N/A", Pizza::Small);

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Loop trough all menu toppings and print them on screen.
        for(unsigned int i = 0; i < availableToppings.size(); i++)
        {
            tempTopping = availableToppings[i];
            cout << i << " - Name: " << tempTopping.getName() << " - Price: " << tempTopping.getPrice() << " KR" << endl;
        }


        cout << "E - End" << endl;
        cout << "C - Cancel pizza" << endl << endl;

        cout << endl;

        //Loop trough toppings on custom pizza and print them on screen.
        cout << "****TOPPINGS ON CUSTOM PIZZA****" << endl;
        for(int i = 0; i < newPizza.getToppingCount(); i++)
        {
            tempTopp = newPizza.getToppings().at(i);
            cout << tempTopp.getName() << endl;
        }
        cout << endl;



        //Ask the user to select a topping.
        if(newPizza.getToppingCount() < 16)
        {
            cout << "Please select the id of the topping to add: " << endl;
        }
        else
        {
            cout << "Topping limit reached!" << endl;
        }
        cout << ": ";
        cin >> selection;

        //Store the selection as int in another variable.
        selectionAsInt = 0;
        for(unsigned int i = 0; i < selection.length(); i++)
        {
            selectionAsInt *= 10;
            selectionAsInt += (int)selection[i] - '0';
        }

        //Check if the selection is in the correct range, and if the topping limit
        //has not been reached.
        if(selectionAsInt >= 0 && selectionAsInt < availableToppings.size() && newPizza.getToppingCount() < 16)
        {
            //Add the topping to the pizza.
            newPizza.addTopping(availableToppings[selectionAsInt]);
        }

    } while(toupper(selection[0]) != 'E' && toupper(selection[0]) != 'C');

    //Check if the order was canceled.
    if(toupper(selection[0]) != 'C')
    {
        //Change the name of the pizza to indicate
        //that the order was not canceled.
        newPizza.setName("Custom Pizza");
        do
        {
            //Clear the screen.
            cout << string(50, '\n');

            //Make the user select the size of the pizza.
            cout << "Please select the size of the pizza" << endl;
            cout << "Choose S for Small" << endl;
            cout << "Choose M for Medium" << endl;
            cout << "Choose L for Large" << endl;
            cout << ": ";
            cin >> selection[0];

            if(toupper(selection[0]) == 'S')
            {
                newPizza.setSize(Pizza::Small);
            }
            else if(toupper(selection[0]) == 'M')
            {
                newPizza.setSize(Pizza::Medium);
            }
            else if(toupper(selection[0]) == 'L')
            {
                newPizza.setSize(Pizza::Large);
            }
            else
            {
                selection[0] = '0';
            }

        } while(selection[0] == '0');


        do
        {
            //Clear the screen.
            cout << string(50, '\n');

            //Print out all available pizza bases.
            for(unsigned int i = 0; i < availableBases.size(); i++)
            {
                tempBase = availableBases.at(i);
                cout << i << " - Name: " << tempBase.getName() << " - price: " << tempBase.getPrice() << " Kr" << endl;
            }
            cout << "Please select the id of the pizza base to add: ";
            cin >> selection;


            //Store the selection as int in another variable.
            selectionAsInt = 0;
            for(unsigned int i = 0; i < selection.length(); i++)
            {
                selectionAsInt *= 10;
                selectionAsInt += (int)selection[i] - '0';
            }

            //Check if the selection is in the correct range.
            if((selectionAsInt >= 0 && selectionAsInt < availableBases.size()))
            {
                //Set the base to the selected base
                newPizza.setBase(availableBases.at(selectionAsInt));
                selection[0] = '/';
            }


        } while(selection[0] != '/');


        //Make the pizza calculate the price of it self (And add extra for making a custom pizza).
        newPizza.generatePrice(300.0);

        //Clear the screen.
        cout << string(50, '\n');

        //Tell the user all the information about the pizza he/she created
        cout << "Toppings:" << endl;
        for(unsigned int i = 0; i < newPizza.getToppings().size(); i++)
        {
            cout << " *" << newPizza.getToppings().at(i).getName() << endl;
        }
        //If there were no toppings, say that there were none
        if(newPizza.getToppings().size() == 0)
        {
            cout << " *NO TOPPINGS" << endl;
        }
        cout << endl << "Pizza price: " << newPizza.getPrice() << " ISK" << endl << endl;

        //Ask the user if everything is OK.
        cout << "Is this OK? (Y/N): ";
        cin >> selection[0];
    }


    return newPizza;
}


Extra UI_Salesman::chooseExtraFromMenu()
{
    Extra tempExtra;
    Topping tempTopping;
    vector<Extra> availableExtras;
    string selection = "0";
    unsigned int selectionAsInt = 0;
    Extra newExtra("N/A", Extra::Drink, 0);

    //Ask extraService for a vector of all extras that are on the menu.
    availableExtras = extraService.getExtras();

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Loop trough all the extras on the menu and print their id, name and price.
        cout << "****EXTRA MENU****" << endl;
        for(unsigned int i = 0; i < availableExtras.size(); i++)
        {
            tempExtra = availableExtras.at(i);
            cout << i << " - Name: " << tempExtra.getName() << " - Price: " << tempExtra.getPrice() << " KR" << endl;
        }
        cout << "Choose C to Cancel" << endl << endl;

        //Ask the user to select a extra from the menu.
        cout << "Please select the id of the extra to add: ";
        cin >> selection;

        //Store the selection as int in another variable.
        selectionAsInt = 0;
        for(unsigned int i = 0; i < selection.length(); i++)
        {
            selectionAsInt *= 10;
            selectionAsInt += (int)selection[i] - '0';
        }

    //Loop if selection is out of range and is not c or C for cancel.
    } while(!((selectionAsInt >= 0U && selectionAsInt < availableExtras.size()) || toupper(selection[0]) == 'C'));

    //Set newExtra to the selected extra if the selection was not canceled.
    if(toupper(selection[0]) != 'C')
    {
        newExtra = availableExtras.at(selectionAsInt);
    }

    //Return the extra.
    return newExtra;
}


void UI_Salesman::removeFromOrder(Order* order)
{
    bool backInput;
    Pizza tempPizza;
    Extra tempExtra;
    unsigned int numberOfOrderedItems;
    string choice;
    int choiceAsInt;

    do
    {
        backInput = false;

        //Clear the screen.
        cout << string(50, '\n');

        //Get the number of Pizzas and extras combined.
        numberOfOrderedItems = (order->getExtras().size() + order->getPizzas().size());

        if(numberOfOrderedItems > 0)
        {

            //Loop through and print out all the pizzas and then all the extras (In the same loop).
            for(unsigned int i = 0; i < numberOfOrderedItems; i++)
            {
                //Prints the pizzas.
                if(i < order->getPizzas().size())
                {
                    tempPizza = order->getPizzas().at(i);

                    if(i == 0)
                    {
                        cout << "Pizzas:" << endl;
                    }

                    cout << "#" << i << " - Name: " << tempPizza.getName() << " - Price: " << tempPizza.getPrice() << " Kr" << endl;

                }
                //Prints the extras.
                else
                {
                    tempExtra = order->getExtras().at(i - order->getPizzas().size());

                    if(i == order->getPizzas().size())
                    {
                        cout << "Extras:" << endl;
                    }

                    cout << "#" << i << " - Name: " << tempExtra.getName() << " - Price: " << tempExtra.getPrice() << " Kr" << endl;

                }
            }

            cout << "B - Back" << endl << endl;

            cout << "Please select an item to remove from the order" << endl;
            cout << ": ";
            cin >> choice;

            choiceAsInt = atoi(choice.c_str());

            if(toupper(choice[0]) == 'B')
            {
                backInput = true;
            }
            else if(choiceAsInt >= 0 && choiceAsInt < (int)numberOfOrderedItems)
            {
                if(choiceAsInt < (int)order->getPizzas().size())
                {
                    order->removePizza(choiceAsInt);
                }
                else
                {
                    order->removeExtra(choiceAsInt);
                }
            }
        }
        else
        {
            cout << "Nothing here!" << endl;
            cout << "Choose B to back" << endl;
            cout << ": ";
            cin >> choice;

            if(toupper(choice[0]) == 'B')
            {
                backInput = true;
            }
        }

    } while(!backInput);

}


bool UI_Salesman::finishUpOrder(Order* order)
{
    string choice;
    unsigned int selectionAsInt;
    bool validInput = false;
    vector<Location> availableLocations;
    Location tempLocation;

    //Ask LocationService for all saved locations.
    availableLocations = locationService.getLocations();

    //Check if there are any items in the order before continuing.
    if(order->getPizzas().size() > 0 || order->getExtras().size() > 0)
    {
        do
        {
            //Clear the screen.
            cout << string(50, '\n');

            //Print out everything in the order using printOutOrder
            this->printOutOrder(*order);

            //Ask the user if he/she wants the order home delivered.
            cout << endl << "Do you want your order to be delivered to your home? (Y/N) " << endl;
            cout << "Choose B to go back." << endl;
            cin >> choice;

            //Check the answer, if it is y it sets homeDelivery to true,
            //else it sets it to false.
            if(toupper(choice[0]) == 'Y')
            {
                order->setHomeDelivery(true);
                validInput = true;
            }
            else if(toupper(choice[0]) == 'N')
            {
                order->setHomeDelivery(false);
                validInput = true;
            }

        } while(!validInput && toupper(choice[0]) != 'B');

        if (toupper(choice[0]) != 'B')
        {
            do
            {
                validInput = false;

                //Clear the screen.
                cout << string(50, '\n');

                //Print out everything in the order using printOutOrder
                //this->printOutOrder(*order);

                //Print out all available locations.
                for(unsigned int i = 0; i < availableLocations.size(); i++)
                {
                    tempLocation = availableLocations.at(i);

                    cout << i << " - " << tempLocation.getAddress() << " " << tempLocation.getCity() << endl;
                }

                //Ask the user if he/she wants the order home delivered.
                cout << endl << "Please choose the id of the location you want your pizza to be made: ";
                cin >> choice;

                //Change the char selection to int.
                selectionAsInt = 0;
                for(unsigned int i = 0; i < choice.length(); i++)
                {
                    selectionAsInt *= 10;
                    selectionAsInt += (int)choice[i] - '0';
                }

                //Check if the input was valid.
                if(selectionAsInt >= 0 && selectionAsInt < availableLocations.size())
                {
                    order->setLocation(availableLocations.at(selectionAsInt));
                    validInput = true;
                }
            } while(!validInput);

            validInput = false;
            //Clear the screen.
            cout << string(50, '\n');
            cout << "Do you wish to pay for the order now? (Y/N)" << endl;
            cin >> choice;
            if(toupper(choice[0]) == 'Y')
            {
                char paymentMethod;
                cout << "Do you wish to pay with card or cash?" << endl;
                cout << "Choose 1 to pay with card" << endl;
                cout << "Choose 2 to pay with cash" << endl;
                cin >> paymentMethod;
                order->setPaidFor(true);
                validInput = true;
            }
            else if(toupper(choice[0]) == 'N')
            {
                order->setPaidFor(false);
                validInput = true;
            }

            //Check if there are any pizzas or side dishes for the baker to bake,
            //if there are none the order goes straight to the Ready state.
            if(order->getPizzas().size() == 0 && order->getAmountOfSideDishes() == 0)
            {
                order->setState(Order::Ready);
            }

            //Save the order to file.
            orderService.addOrder(*order);

            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        //If there are no items in the order, it goes into this else.
        do
        {
            validInput = false;

            //Clear the screen.
            cout << string(50, '\n');

            cout << "There is nothing in the order!" << endl;
            cout << "Choose B to go Back" << endl;
            cout << ": ";
            cin >> choice;

            if(toupper(choice[0]) == 'B')
            {
                validInput = true;
            }

        } while(!validInput);

        return false;
    }

}


void UI_Salesman::printOutOrder(Order order)
{
    Pizza tempPizza;
    Extra tempExtra;
    Order tempOrder;

    //Loops trough all the pizzas in the order and prints them out in this format:
    //SIZE - NAME ............................ PRICE Kr
    cout << "Pizzas: " << endl;
    for(unsigned int i = 0; i < order.getPizzas().size(); i++)
    {
        tempPizza = order.getPizzas().at(i);

        //Print out the size of the pizza.
        if(tempPizza.getSize() == Pizza::Small)
        {
            cout << "Small  - ";
        }
        else if(tempPizza.getSize() == Pizza::Medium)
        {
            cout << "Medium - ";
        }
        else if(tempPizza.getSize() == Pizza::Large)
        {
            cout << "Large  - ";
        }

        //Print out the type of base of the pizza.
        cout << tempPizza.getBase().getName() << " - " ;

        //Print out the name of the pizza.
        cout << tempPizza.getName();

        //Print out dots in between name and price, and there are different amount
        //of dots depending on the length of the name.
        cout << " " << string((47-tempPizza.getName().length()- tempPizza.getBase().getName().length()), '.') << " ";

        //print out the price of the pizza.
        if(checkMenu(tempPizza))
        {
            tempPizza.generatePrice();
        }
        else
        {
            tempPizza.generatePrice(300);
        }
        tempOrder.addPizza(tempPizza);
        cout << tempPizza.getPrice() << " Kr" << endl;
    }

    //Loops trough all the pizzas in the order and prints them out in this format:
    //NAME ................................... PRICE Kr
    cout << endl << "Extras:" << endl;
    for(unsigned int i = 0; i < order.getExtras().size(); i++)
    {
        tempExtra = order.getExtras().at(i);

        //Print out the name of the extra.
        cout << tempExtra.getName();

        //Print out dots in between name and price, and there are different amount
        //of dots depending on the length of the name.
        cout << " " << string((59-tempExtra.getName().length()), '.') << " ";

        //print out the price of the pizza.
        tempOrder.addExtra(tempExtra);
        cout << tempExtra.getPrice() << " Kr" << endl;
    }

    //Print out a line between the list and total
    cout << string(70, '-') << endl;

    //Print out the total price.
    tempOrder.generatePrice();
    cout << "Total " << string(54, '.') << " " << tempOrder.getPrice() << " Kr" << endl << endl;
}


void UI_Salesman::viewOrders()
{
    string choice;
    unsigned int choiceToInt = 0;
    int counter = 0;
    bool validInput;
    vector<Order> orders;
    vector<int> numbers;
    Order tempOrder;
    orders = orderService.getOrders();
    vector<Location> availableLocations = locationService.getLocations();

    do
    {
        validInput = false;

        //Clear the screen
        cout << string(50, '\n');

        //Loop through and print out all available locations.
        for(unsigned int i = 0; i < availableLocations.size(); i++)
        {
            this->salesmanLocation = availableLocations.at(i);

            cout << i << " - " << this->salesmanLocation.getAddress() << "  " << this->salesmanLocation.getCity() << endl;
        }
        cout << "Please choose the location you work at: ";
        cin >> choice;

        //Change the choice to int and store in another variable
        for(unsigned int i = 0; i < choice.length(); i++)
        {
            choiceToInt *= 10;
            choiceToInt += (int)choice[i] - '0';
        }
        //choiceToInt = (unsigned int)(choice - '0');

        if(choiceToInt < availableLocations.size())
        {
            this->salesmanLocation = availableLocations.at(choiceToInt);
            validInput = true;
        }

    } while(!validInput);
    cout << endl << endl;
    for(unsigned int i = 0; i < orders.size(); i++)
    {
        if(orders[i].getLocation().getId() == salesmanLocation.getId() && !orders[i].getPaidFor())
        {
            tempOrder = orders[i];
            cout << counter << " - ";
            numbers.push_back(i);
            counter++;
            this->printOutOrder(tempOrder);
        }
    }
    choiceToInt = 0;
    if(counter == 0)
    {

    }
    else
    {
        cout << "Please select which order you wish to mark as paid for: ";
        cin >> choice;

        for(unsigned int i = 0; i < choice.length(); i++)
        {
            choiceToInt *= 10;
            choiceToInt += (int)choice[i] - '0';
        }
        orderService.setOrderPaid(orders[numbers[choiceToInt]].getId());
    }
}


bool UI_Salesman::checkMenu(Pizza pizza)
{
    vector<Pizza> pizzas = pizzaService.getPizzas();
    vector<Topping> inToppings = pizza.getToppings();
    vector<Topping> tempToppings;
    sort(inToppings.begin(), inToppings.end());
    for(unsigned int i = 0; i < pizzas.size(); i++)
    {
        tempToppings = pizzas[i].getToppings();
        if(tempToppings == inToppings)
        {
            return true;
        }
    }
    return false;
}


























