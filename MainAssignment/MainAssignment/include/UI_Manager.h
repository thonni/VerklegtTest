#ifndef UI_MANAGER_H
#define UI_MANAGER_H
#include <iostream>
#include "DataManager.h"
#include "topping.h"
#include "pizza.h"
#include "Extra.h"
#include "Order.h"
#include <vector>

class UI_Manager
{
    public:
        UI_Manager();
        virtual ~UI_Manager();
        void addToMenu ();
        void addTopping();

    protected:

    private:
        DataManager data;
        vector<Topping> toppingsToAdd;

};

#endif // UI_MANAGER_H
