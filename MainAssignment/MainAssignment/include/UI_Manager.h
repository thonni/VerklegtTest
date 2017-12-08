#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <iostream>
#include <vector>
#include <string>

#include "LocationService.h"
#include "toppingservice.h"
#include "PizzaService.h"
#include "ExtraService.h"
#include "BaseService.h"
#include "DataManager.h"
#include "topping.h"
#include "pizza.h"
#include "Extra.h"
#include "Order.h"
#include "Location.h"
#include "Base.h"

using namespace std;

class UI_Manager
{
    public:
        void startUI ();
        void addToppingToMenu();
        void addPizzaToMenu();
        void addExtraToMenu();
        void addLocation();
        void addBaseToMenu();

    protected:

    private:
        DataManager data;
        ToppingService toppingService;
        PizzaService pizzaService;
        ExtraService extraService;
        LocationService locationService;
        BaseService baseService;
        vector<Topping> toppingsToAdd;

};

#endif // UI_MANAGER_H
