#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "pizza.h"
#include "Extra.h"

class Order
{
    public:
        Order();
        virtual ~Order();
        char getState();
        void addPizza(Pizza pizza);
        void addExtra(Extra extra);

        friend ostream& operator << (ostream& out, const Order& order);

    protected:

    private:
        char state;
        vector<Pizza> pizzas;
        vector<Extra> extras;
};

#endif // ORDER_H
