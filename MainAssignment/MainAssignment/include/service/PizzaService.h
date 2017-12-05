#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include <vector>
#include "pizza.h"
#include "PizzaRepository.h"

class PizzaService
{
    public:
        bool isValidPizza(const Pizza& pizza);
        void addPizza(const Pizza& pizza);
        vector<Pizza> getPizzas();


    protected:

    private:
        PizzaRepository pizzaRepository;
};

#endif // PIZZASERVICE_H
