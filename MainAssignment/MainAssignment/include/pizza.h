#ifndef PIZZA_H
#define PIZZA_H

#include <stddef.h>
#include <string.h>
#include "Topping.h"

using namespace std;

class Pizza
{
    public:
        Pizza(string name, int toppingsCount, Sizes pizzaSize);
        virtual ~Pizza();

        void addToppings();

        enum Sizes
        {
            Small,
            Medium,
            Large
        };

    protected:

    private:
        Topping* toppings;
        int toppingsCount;
        double price;
        char name[32];
        Sizes pizzaSize;
};

#endif // PIZZA_H
