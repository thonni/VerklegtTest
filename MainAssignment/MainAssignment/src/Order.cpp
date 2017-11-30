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

void Order::addPizza(Pizza pizza) {
    pizzas.push_back(pizza);
}

void Order::addExtra(Extra extra) {
    extras.push_back(extra);
}

ostream& operator << (ostream& out, const Order& order)
{
    out << order.state << endl;
    for(int i = 0; i < order.pizzas.size(); i++) {
        out << order.pizzas.at(i);
    }
    for(int i = 0; i < order.extras.size(); i++) {
        out << order.extras.at(i);
    }
    out << endl;

    return out;
}
