#ifndef ORDER_H
#define ORDER_H

#include "Pizza.h"
#include "Extra.h"

class Order
{
    public:
        Order();
        virtual ~Order();

    protected:

    private:
        char state;
        Pizza pizzas[];
        Extra extras[];
};

#endif // ORDER_H
