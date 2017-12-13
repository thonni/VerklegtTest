#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "pizza.h"
#include "BaseService.h"

class PizzaRepository
{
    public:
        void addPizza(Pizza pizza);
        vector<Pizza> getPizzas();


    protected:

    private:
        BaseService baseService;

};

#endif // PIZZAREPOSITORY_H
