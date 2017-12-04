#include "UI_Salesman.h"

DataManager data;

UI_Salesman::UI_Salesman()
{
    //ctor
}

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

    //Create an instance of order.
    Order newOrder;

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
            //Call the choosePizzaFromMenu function
            //and add the pizza it returns to newOrder.
            newOrder.addPizza(this->choosePizzaFromMenu());
        }
        else if(toupper(choice) == 'M')
        {
            //Call the makePizza function
            //and add the pizza it returns to newOrder.
            newOrder.addPizza(this->makePizza());
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
<<<<<<< HEAD
            //Call the finishUpOrder function which
            //takes newOrder as an pointer argument.
            //If the order was finished up it returns true.
            orderFinished = this->finishUpOrder(&newOrder);
        }

    } while(toupper(choice) != 'C' && orderFinished == false);
=======

        }
    } while(toupper(choice) != 'C');
>>>>>>> 91eec6c9734a2f543b82a1b5bfccc6fb3103b633
}


Pizza UI_Salesman::choosePizzaFromMenu()
{
    /// \TODO: Print out all menu pizzas from file and make the user select from them.

    //Temp stuff just so it returns something (And doesn't give an warning when compiling).
    Pizza temp("Temp", Pizza::Small);
    return temp;
}


Pizza UI_Salesman::makePizza()
{
    Topping tempTopping;
    vector<Topping> availableToppings;
    char selection = '0';
    unsigned int selectionAsInt = 0;

    //Clear the screen.
    cout << string(50, '\n');

    //Get a vector for all saved toppings using DataManager.
    availableToppings = data.readToppings();

    //Create an instance of pizza using the name
    Pizza newPizza("noName", Pizza::Small);

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Loop trough all menu toppings and print them on screen.
        for(unsigned int i = 0; i < availableToppings.size(); i++)
        {
            tempTopping = availableToppings[i];
            cout << i << " - Name: " << tempTopping.getName() << " - Price: " << tempTopping.getPrice() << endl;
        }
        cout << "E - End" << endl << endl;

        //Ask the user to select a topping.
        cout << "Please select the id of the topping to add: ";
        cin >> selection;

        //Change the char selection to int.
        selectionAsInt = (int)(selection - '0');

        //Check if the selection is in the correct range.
        if((selectionAsInt >= 0 && selectionAsInt < availableToppings.size()))
        {
            //Add the topping to the pizza.
            newPizza.addTopping(availableToppings[selectionAsInt]);
        }
        //If it is not in range, it checks if you entered the letter e or E.
        else if(toupper(selection) != 'E')
        {
            /// \TODO: Make error message here.
        }

    } while(toupper(selection) != 'E');

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

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


    return newPizza;
}


Extra UI_Salesman::chooseExtraFromMenu()
{
    /// \TODO: Print out all menu extras from file and make the user select from them.

    //Temp stuff just so it returns something (And doesn't give an warning when compiling).
    Extra temp("temp", Extra::Drink, 0.0);
    return temp;
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
