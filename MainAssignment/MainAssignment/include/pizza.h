#ifndef PIZZA_H
#define PIZZA_H

#include <stddef.h>
#include <string.h>
#include "Topping.h"

using namespace std;

class Pizza
{
    public:
        Pizza(string name, int toppingsCount);
        virtual ~Pizza();

        void addToppings();

        /*enum sizes
        {
            Small = 1.0,
            Medium = 1.2,
            Large = 1.4
        };*/

    protected:

    private:
        Topping* toppings;
        int toppingsCount;
        double price;
        char name[32];
};

#endif // PIZZA_H
