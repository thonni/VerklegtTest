#ifndef PIZZA_H
#define PIZZA_H

#include <stddef.h>
#include <string.h>
#include <vector>
#include "Topping.h"

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
        Pizza(string name, Pizza::Size pizzaSize);

        void addTopping(Topping topping);
        void generatePrice(double extraCost);

        friend ostream& operator << (ostream& out, const Pizza& pizza);
        friend istream& operator >> (istream& in, Pizza& pizza);

        //Getters and setters
        int getToppingCount();
        double getPrice();
        string getName();
        vector<Topping> getToppings();

    protected:

    private:
        vector<Topping> toppings;
        double price;
        char name[32];
        Pizza::Size pizzaSize;
};

#endif // PIZZA_H
