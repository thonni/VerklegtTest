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
            Topping topping;
            int arrsize = 0;
            cout <<
            cin >> topping;
            //data.addToppings(topping, );
        }
        else if (choice == 'p')
        {
            //data.addPizzasToMenu();
        }
        else if (choice == 'e')
        {
            //data.addExtra();
        }
        else if (choice != 't' || choice != 'p' || choice != 'e')
        {
            cout << "Invalid input!" << endl;
        }
    } while(choice != 'q');
}


void UI_Manager::addTopping()
{
    string name;
    double price;

    cout << "Please enter the name of the topping: ";
    cin >> name;

    cout << "Please enter the price of the topping: ";
    cin >> price;

    //Create an instance of Topping.
    Topping newTopping(name, price);

    //data.addToppings(newTopping, 1);
}
