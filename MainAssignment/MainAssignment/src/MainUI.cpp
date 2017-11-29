#include "MainUI.h"
#include <iostream>
using namespace std;


MainUI::MainUI()
{
    //ctor
}

MainUI::~MainUI()
{
    //dtor
}

void MainUI::startUI()
{
    cout << "Welcome to Pizza hut" << endl;
    cout << "Please tell us who you are:" << endl;
    cout << "Choose m for manager" << endl;
    cout << "Choose s for salesman" << endl;
    cout << "Choose b for baker" << endl;
    cout << "Choose d for delivery" << endl;

    char selection = '\0';

    cin >> selection;

    if (selection == 'm')
    {

    }
    if (selection == 's')
    {

    }
    if (selection == 'b')
    {

    }
    if (selection == 'd')
    {

    }
}
