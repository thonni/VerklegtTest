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

    //Create an instance of order.
    Order newOrder;
    newOrder.setState(Order::Received);

    do
    {

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
        newPizza = availablePizzas.at(0);
    }

    //Return the pizza.
    return newPizza;
}


Pizza UI_Salesman::makePizza()
{
    Topping tempTopping;
    vector<Topping> availableToppings;
    char selection = '0';
    unsigned int selectionAsInt = 0;

    //Clear the screen.
    cout << string(50, '\n');

    //Ask toppingService for a vector of all toppings that are on the menu.
    availableToppings = toppingService.getToppings();

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
        newPizza.setName("Ok");
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

        //Make the pizza calculate the price of it self.
        newPizza.generatePrice();

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
    /// \TODO: Print out all items that are currently in the order in a nice list and ask the user
    ///        if he/she wants to finish up the order, if so it saves the order to file and returns true
    ///        else it returns false.




    return true;
}
