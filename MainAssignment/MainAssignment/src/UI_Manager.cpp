#include "UI_Manager.h"
#include "DataManager.h"

using namespace std;

UI_Manager::UI_Manager()
{
    //ctor
}


void UI_Manager::startUI (){
    char choice;
    do {

        //Clear the screen.
        cout << string(50, '\n');

        cout << "What would you like to do?" << endl;
        cout << "Choose T to add toppings" << endl;
        cout << "Choose P to add pizzas on menu" << endl;
        cout << "Choose E to add extras" << endl;
        cout << "Choose Q to quit" << endl;
        cout << ": ";
        cin >> choice;

        if(choice == 't')
        {
            this->addTopping();
        }
        else if (choice == 'p')
        {
            this->addPizza();
        }
        else if (choice == 'e')
        {
            ///TEMPORARY, LISTS ALL SAVED PIZZAS.
            vector<Pizza> pizzas;
            pizzas = this->pizzaService.getPizzas();
            for(unsigned int i = 0; i < pizzas.size(); i++)
            {
                cout << pizzas.at(i);
            }
            cin >> choice;

        }
        else if(toupper(choice) != 'Q')
        {
            cout << "Invalid input!" << endl;
        }

    } while(toupper(choice) != 'Q');
}


//This function creates new toppings using user input
//and uses DataManager to save them to toppingList.dat.
void UI_Manager::addTopping()
{
    string name;
    double price;
    char continueToAdd = '\0';

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Ask the user for a name and price for the new topping.
        cout << "Please enter the name of the topping: ";
        cin >> name;
        cout << "Please enter the price of the topping: ";
        cin >> price;

        //Create a temporary instance of Topping.
        Topping toppingToAdd = Topping(name, price);

        //Ask the Topping service to save the Topping.
        toppingService.addTopping(toppingToAdd);

        //Ask the user if he/she wants to add another topping.
        cout << "Add another topping? (Y/N): ";
        cin >> continueToAdd;

    } while(toupper(continueToAdd) == 'Y');
}


void UI_Manager::addPizza()
{
    string name;
    Topping tempTopping;
    vector<Topping> availableToppings;
    char selection = '0';
    unsigned int selectionAsInt = 0;

    //Clear the screen.
    cout << string(50, '\n');

    //Get a vector for all saved toppings using DataManager.
    availableToppings = toppingService.getToppings();

    //Ask the user for a name for the new pizza.
    cout << "Pizza name: ";
    cin >> name;

    //Create an instance of pizza using the name
    Pizza newPizza(name, Pizza::Small);

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

    //Clear the screen.
    cout << string(50, '\n');

    //Make the pizza calculate the price of it self.
    newPizza.generatePrice();

    //Tell the user all the information about the pizza he/she created
    cout << "Name: " << newPizza.getName() << endl << endl;
    cout << "Toppings:" << endl;
    for(unsigned int i = 0; i < newPizza.getToppings().size(); i++)
    {
        cout << " *" << newPizza.getToppings().at(i).getName() << endl;
    }
    cout << endl << "Total price: " << newPizza.getPrice() << " ISK" << endl << endl;

    //Ask the user if everything is OK.
    cout << "Is this OK? (Y/N): ";
    cin >> selection;


    //Add the pizza to a vector and use DataManager to save the pizza to file.
    //newPizzas.push_back(newPizza);
    //data.addPizzasToMenu(newPizzas);
    pizzaService.addPizza(newPizza);
}
