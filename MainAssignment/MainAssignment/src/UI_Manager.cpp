#include "UI_Manager.h"
#include "DataManager.h"

using namespace std;

UI_Manager::UI_Manager()
{
    //ctor
}


UI_Manager::~UI_Manager()
{
    //dtor
}


void UI_Manager::addToMenu (){
    char choice;
    do {
        cout << "What would you like to add?" << endl;
        cout << "Choose t for toppings" << endl;
        cout << "Choose p for pizzas on menu" << endl;
        cout << "Choose e for extras" << endl;
        cout << "Choose q to quit" << endl;
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
            ///THIS IS TEMPORARY, IT READS AND DISPLAYS EVERYTHING IN THE TOPPING FILE.
            toppingsToAdd = data.readToppings();
            for(unsigned int i = 0; i < toppingsToAdd.size(); i++)
            {
                cout << toppingsToAdd.at(i);
            }
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
    Topping tempTopping;
    char continueToAdd = '\0';

    do
    {
        //Ask the user for a name and price for the new topping.
        cout << "Please enter the name of the topping: ";
        cin >> name;
        cout << "Please enter the price of the topping: ";
        cin >> price;

        //Create a temporary instance of Topping.
        tempTopping = Topping(name, price);

        //Add the temporary topping to the vector.
        toppingsToAdd.push_back(tempTopping);

        //Ask the user if he/she wants to add another topping.
        cout << "Add another topping? (Y/N): ";
        cin >> continueToAdd;

    } while(toupper(continueToAdd) == 'Y');

    //Run the addToppings from DataManager to save the topping to file.
    data.addToppings(toppingsToAdd);
    //Clear the vector.
    toppingsToAdd.clear();
}


void UI_Manager::addPizza()
{
    string name;
    Topping tempTopping;
    vector<Topping> availableToppings;
    vector<Pizza> newPizzas;
    char selection = '0';
    unsigned int selectionAsInt = 0;

    //Get a vector for all saved toppings using DataManager.
    availableToppings = data.readToppings();

    //Ask the user for a name for the new pizza.
    cout << "Pizza name: ";
    cin >> name;

    //Create an instance of pizza using the name
    Pizza newPizza(name, Pizza::Small);

    do
    {
        //Loop trough all menu toppings and print them on screen.
        for(unsigned int i = 0; i < availableToppings.size(); i++)
        {
            tempTopping = availableToppings[i];
            cout << i << " - Name: " << tempTopping.getName() << " - Price: " << tempTopping.getPrice() << endl;
        }
        cout << "E - End" << endl << endl;

        //Ask the user to select a topping.
        cout << "Please select a topping to add: ";
        cin >> selection;

        //Change the char selection to int.
        selectionAsInt = (int)(selection - '0');

        //Check if the selection is in the correct range.
        if((selectionAsInt >= 0 && selectionAsInt < availableToppings.size()))
        {
            //Add the topping to the pizza.
            newPizza.addTopping(availableToppings[selectionAsInt]);
        }
        else if(toupper(selection) != 'E')
        {
            /// \TODO: Make error message here.
        }

    } while(toupper(selection) != 'E');

    newPizzas.push_back(newPizza);
    data.addPizzasToMenu(newPizzas);
}
