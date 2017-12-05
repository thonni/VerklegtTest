#ifndef TOPPINGREPOSITORY_H
#define TOPPINGREPOSITORY_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Topping.h"

class ToppingRepository
{
    public:
        void addTopping(Topping topping);
        vector<Topping> getToppings();

    protected:

    private:
};

#endif // TOPPINGREPOSITORY_H
