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
}
