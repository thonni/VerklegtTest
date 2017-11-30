#ifndef UI_MANAGER_H
#define UI_MANAGER_H
#include <iostream>
#include "DataManager.h"
#include "topping.h"
#include "pizza.h"
#include "Extra.h"
#include "Order.h"

class UI_Manager
{
    public:
        UI_Manager();
        virtual ~UI_Manager();
        void addToMenu ();

    protected:

    private:
        DataManager data;

};

#endif // UI_MANAGER_H
