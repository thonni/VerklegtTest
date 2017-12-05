#include "toppingservice.h"



bool ToppingService::isValidTopping(const Topping& topping)
{
    //Checks if the topping name is an empty string, if it is
    //it returns false else it returns true.
    if(!topping.getName().empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


void ToppingService::addTopping(const Topping& topping)
{
    //Check if the input is a valid Topping.
    if(this->isValidTopping(topping))
    {
        //Ask the ToppingRepository to save the topping to file.
        toppingRepository.addTopping(topping);
    }
}


vector<Topping> ToppingService::getToppings()
{
    //Ask the ToppingRepository for the toppings in a vector and return it.
    return toppingRepository.getToppings();
}
