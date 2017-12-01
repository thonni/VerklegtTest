#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "Order.h"

using namespace std;

class DataManager
{
    public:
        DataManager();
        virtual ~DataManager();
        void addToppings(const vector<Topping> topping);
        void addPizzasToMenu(const vector<Pizza> pizzas);
        void addOrders(const Order *orders, const int arrsize);
        void addExtra(const Extra *extras, const int arrsize);
        vector<Topping> readToppings();
        vector<Pizza> readPizzaMenu();
        void readCurrentOrders();
        void readExtras();
        void moveOrders();

    protected:

    private:
        int getToppingRecord();
        int getPizzaRecord();
        int getOrderRecord();
        int getExtraRecord();
};

#endif // DATAMANAGER_H
