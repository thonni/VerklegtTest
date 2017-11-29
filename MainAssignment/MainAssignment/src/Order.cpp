#include "Order.h"

Order::Order()
{
    //ctor
}

Order::~Order()
{
    //dtor
}

char Order::getState() {
    return this->state;
}

int Order::getPizzaAmt() {
    return this->pizzaAmt;
}

int Order::getExtraAmt() {
    return this->extraAmt;
}

ostream& operator << (ostream& out, const Order& order)
{
    out << order.state;
    for(int i = 0; i < order.pizzaAmt; i++) {
        out << " " << order.pizzas[i];
    }
    for(int i = 0; i < order.extraAmt; i++) {
        out << " " << order.extras[i];
    }
    out << endl;

    return out;
}
