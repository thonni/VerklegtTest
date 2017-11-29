#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <iostream>
#include <string>
#include "Topping.h"
#include "Pizza.h"
#include "Order.h"

using namespace std;

class DataManager
{
    public:
        DataManager();
        virtual ~DataManager();
        void addToppings(const Topping *toppings, const int arrsize);
        void addPizzasToMenu(const Pizza *pizzas, const int arrsize);
        void addOrders(const Order *orders, const int arrsize);
        void readToppings();
        void readPizzaMenu();
        void readCurrentOrders();
        void moveOrders();

    protected:

    private:
        int getToppingRecord();
        int getPizzaRecord();
        int getOrderRecord();
};

#endif // DATAMANAGER_H
