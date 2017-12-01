#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <iostream>
#include <vector>
#include <string>

#include "DataManager.h"
#include "topping.h"
#include "pizza.h"
#include "Extra.h"
#include "Order.h"

using namespace std;

class UI_Manager
{
    public:
        UI_Manager();
        virtual ~UI_Manager();
        void startUI ();
        void addTopping();
        void addPizza();

    protected:

    private:
        DataManager data;
        vector<Topping> toppingsToAdd;

};

#endif // UI_MANAGER_H
