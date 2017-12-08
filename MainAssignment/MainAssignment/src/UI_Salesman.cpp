#include "UI_Salesman.h"


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
    vector<Pizza> availablePizzas;
    char selection = '0';
    unsigned int selectionAsInt = 0;
    Pizza newPizza("N/A", Pizza::Small);

    //Ask pizzaService for a vector of all pizzas that are on the menu.
    availablePizzas = pizzaService.getPizzas();

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
            cout << i << " - Name: " << tempPizza.getName() << " - Price: " << tempPizza.getPrice() << " KR" << endl;
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
        selectionAsInt = (int)(selection - '0');

    //Loop if selection is out of range and is not c or C for cancel.
    } while(!((selectionAsInt >= 0U && selectionAsInt < availablePizzas.size()) || toupper(selection) == 'C'));

    //Set newPizza to the selected pizza if the selection was not canceled.
    if(toupper(selection) != 'C')
    {
        newPizza = availablePizzas.at(selectionAsInt);
    }

    //Return the pizza.
    return newPizza;
}


Pizza UI_Salesman::makePizza()
{
    Topping tempTopping;
    Base tempBase;
    vector<Topping> availableToppings;
    vector<Base> availableBases;
    char selection = '0';
    unsigned int selectionAsInt = 0;

    //Clear the screen.
    cout << string(50, '\n');

    //Ask toppingService for a vector of all toppings that are on the menu.
    availableToppings = toppingService.getToppings();
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

        //Ask the user to select a topping.
        cout << "Please select the id of the topping to add: ";
        cin >> selection;

        //Store the selection as int in another variable.
        selectionAsInt = (int)(selection - '0');

        //Check if the selection is in the correct range.
        if((selectionAsInt >= 0 && selectionAsInt < availableToppings.size()))
        {
            //Add the topping to the pizza.
            newPizza.addTopping(availableToppings[selectionAsInt]);
        }

    } while(toupper(selection) != 'E' && toupper(selection) != 'C');

    //Check if the order was canceled.
    if(toupper(selection) != 'C')
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
            cin >> selection;

            if(toupper(selection) == 'S')
            {
                newPizza.setSize(Pizza::Small);
            }
            else if(toupper(selection) == 'M')
            {
                newPizza.setSize(Pizza::Medium);
            }
            else if(toupper(selection) == 'L')
            {
                newPizza.setSize(Pizza::Large);
            }
            else
            {
                selection = '0';
            }

        } while(selection == '0');


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
            cout << "Please select the id of the topping to add: ";
            cin >> selection;


            //Store the selection as int in another variable.
            selectionAsInt = (int)(selection - '0');

            //Check if the selection is in the correct range.
            if((selectionAsInt >= 0 && selectionAsInt < availableBases.size()))
            {
                //Set the base to the selected base
                newPizza.setBase(availableBases.at(selectionAsInt));
                selection = '/';
            }


        } while(selection != '/');


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
        cin >> selection;
    }


    return newPizza;
}


Extra UI_Salesman::chooseExtraFromMenu()
{
    Extra tempExtra;
    Topping tempTopping;
    vector<Extra> availableExtras;
    char selection = '0';
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
        selectionAsInt = (int)(selection - '0');

    //Loop if selection is out of range and is not c or C for cancel.
    } while(!((selectionAsInt >= 0U && selectionAsInt < availableExtras.size()) || toupper(selection) == 'C'));

    //Set newExtra to the selected extra if the selection was not canceled.
    if(toupper(selection) != 'C')
    {
        newExtra = availableExtras.at(selectionAsInt);
    }

    //Return the extra.
    return newExtra;
}


void UI_Salesman::removeFromOrder(Order* order)
{
    /// \TODO: print out all items that are currently in the order and make the user select
    ///        something to remove (Or select something to cancel).

}


bool UI_Salesman::finishUpOrder(Order* order)
{
    char choice;
    unsigned int selectionAsInt;
    bool validInput = false;
    vector<Location> availableLocations;
    Location tempLocation;

    //Ask LocationService for all saved locations.
    availableLocations = locationService.getLocations();


    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Print out everything in the order using printOutOrder
        this->printOutOrder(*order);

        //Ask the user if he/she wants the order home delivered.
        cout << endl << "Do you want your order to be delivered to your home? (Y/N): ";
        cin >> choice;

        //Check the answer, if it is y it sets homeDelivery to true,
        //else it sets it to false.
        if(toupper(choice) == 'Y')
        {
            order->setHomeDelivery(true);
            validInput = true;
        }
        else if(toupper(choice) == 'N')
        {
            order->setHomeDelivery(false);
            validInput = true;
        }

    } while(!validInput);


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
        selectionAsInt = (int)(choice - '0');

        //Check if the input was valid.
        if(selectionAsInt >= 0 && selectionAsInt < availableLocations.size())
        {
            order->setLocation(availableLocations.at(selectionAsInt));
            validInput = true;
        }


    } while(!validInput);

    //Save the order to file.


    return true;
}


void UI_Salesman::printOutOrder(Order order)
{
    Pizza tempPizza;
    Extra tempExtra;

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

        //Print out the name of the pizza.
        cout << tempPizza.getName();

        //Print out dots in between name and price, and there are different amount
        //of dots depending on the length of the name.
        cout << " " << string((50-tempPizza.getName().length()), '.') << " ";

        //print out the price of the pizza.
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
        cout << tempExtra.getPrice() << " Kr" << endl;
    }

    //Print out a line between the list and total
    cout << string(70, '-') << endl;

    //Print out the total price.
    cout << "Total " << string(54, '.') << " " << order.getPrice() << " Kr" << endl;
}
