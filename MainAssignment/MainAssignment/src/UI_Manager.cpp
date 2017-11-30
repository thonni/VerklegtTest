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

void addToMenu (){
<<<<<<< HEAD
    char choice;
    do {
        cout << "What would you like to add?" ;
        cout << "Choose t for toppings" << endl;
        cout << "Choose p for pizzas on menu" << endl;
        cout << "Choose e for extras" << endl;
        cout << "Choose q to quit" << endl;
        cin >> choice;
        if(choice == 't'){
            //data.addToppings()
        }
        else if (choice == 'p')
        {
            //data.addPizzasToMenu();
        }
        else if (choice == 'e')
        {
            //data.addExtra();
        }
    } while(choice != 'q');
=======
    cout << "What would you like to add?" ;
    cout << "Choose t for toppings" << endl;
    cout << "Choose t for toppings" << endl;
    cout << "Choose t for toppings" << endl;
    cout << "Choose t for toppings" << endl;
    cout << "Choose t for toppings" << endl;
    char choice;
    cin >> choice;
    if(choice == 't'){
        //data.addToppings()
    }
>>>>>>> be1abc7d5ecd68f3e0788b923b80feb5cfd8300b
}
