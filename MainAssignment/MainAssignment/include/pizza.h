#ifndef PIZZA_H
#define PIZZA_H

#include <stddef.h>
#include <string.h>
#include "topping.h"

using namespace std;

class Pizza
{
    public:

        enum Size
        {
            Small,
            Medium,
            Large
        };

        Pizza();
        Pizza(string name, int toppingsCount, Pizza::Size pizzaSize);
        virtual ~Pizza();

        void addToppings();

        friend ostream& operator << (ostream& out, const Pizza& pizza);
        friend istream& operator >> (istream& in, Pizza& pizza);

    protected:

    private:
        Topping* toppings;
        int toppingsCount;
        double price;
        char name[32];
        Pizza::Size pizzaSize;
};

#endif // PIZZA_H
