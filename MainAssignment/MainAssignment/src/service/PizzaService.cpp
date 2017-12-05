#include "PizzaService.h"


bool PizzaService::isValidPizza(const Pizza& pizza)
{
    return true;
}


void PizzaService::addPizza(const Pizza& pizza)
{
    //Check if the input is a valid Pizza
    if(isValidPizza(pizza))
    {
        //Ask the PizzaRepository to save the pizza to file.
        pizzaRepository.addPizza(pizza);
    }
}


vector<Pizza> PizzaService::getPizzas()
{
    //Ask the PizzaRepository for the pizzas in a vector and return it.
    return pizzaRepository.getPizzas();
}
