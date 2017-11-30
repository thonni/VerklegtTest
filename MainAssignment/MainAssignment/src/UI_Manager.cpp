#include "UI_Manager.h"
#include "DataManager.h"

DataManager data;

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
        if(choice == 't'){
            /*Topping topping;
            int arrsize = 0;
            cout <<
            cin >> topping;
            //data.addToppings(topping, );*/
            this->addTopping();
        }
        else if (choice == 'p')
        {
            //test = data.addPizzasToMenu();
        }
        else if (choice == 'e')
        {
            //data.addExtra();
            toppingsToAdd = data.readToppings();
            for(unsigned int i = 0; i < toppingsToAdd.size(); i++)
            {
                cout << toppingsToAdd.at(i);
            }
        }
        else
        {
            cout << "Invalid input!" << endl;
        }

    } while(choice != 'q');
}


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
