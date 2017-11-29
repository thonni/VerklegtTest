#ifndef ORDER_H
#define ORDER_H

#include "Pizza.h"
#include "Extra.h"

class Order
{
    public:
        Order();
        virtual ~Order();
        char getState();
        int getPizzaAmt();
        int getExtraAmt();

        friend ostream& operator << (ostream& out, const Order& order);

    protected:

    private:
        char state;
        Pizza pizzas[];
        int pizzaAmt;
        Extra extras[];
        int extraAmt;
};

#endif // ORDER_H
