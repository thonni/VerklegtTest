#include "MainUI.h"
#include <iostream>
#include "UI_Manager.h"
#include "UI_Salesman.h"
#include "UI_Baker.h"
#include "UI_Delivery.h"

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

    // Select who you are
    cin >> selection;

    // Responds to who you are, and shows you the appropriate front page
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
