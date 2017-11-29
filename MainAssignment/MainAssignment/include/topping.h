#ifndef TOPPING_H
#define TOPPING_H

#include <string.h>
#include <iostream>

using namespace std;

class Topping
{
    public:
        Topping();
        Topping(string name, double price);
        virtual ~Topping();

        friend istream& operator >> (istream& in, Topping& topping);
        friend ostream& operator << (ostream& out const Topping& topping);

    protected:

    private:
        char name[32];
        double price;
};

#endif // TOPPING_H
