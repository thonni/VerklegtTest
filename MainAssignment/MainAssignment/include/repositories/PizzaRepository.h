#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H

#include <iostream>
#include <fstream>
#include <vector>
#include "pizza.h"

class PizzaRepository
{
    public:
        void addPizza(Pizza pizza);
        vector<Pizza> getPizzas();


    protected:

    private:
};

#endif // PIZZAREPOSITORY_H
