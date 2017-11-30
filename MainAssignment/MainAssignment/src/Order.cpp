#include "Order.h"

using namespace std;

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

void Order::removePizza(int i) {
    this->pizzas.at(i) = this->pizzas.back();
    this->pizzas.pop_back();
}

void Order::removeExtra(int i) {
    this->extras.at(i - 1) = this->extras.back();
    this->extras.pop_back();
}

void Order::listPizzas() {
    int ssize = this->pizzas.size();
    for(int i = 0; i < ssize; i++) {
        cout << (i + 1) << this->pizzas.at(i);
    }
}

void Order::listExtras() {
    int ssize = this->extras.size();
    for(int i = 0; i < ssize; i++) {
        cout << (i + 1) << this->extras.at(i);
    }
}

ostream& operator << (ostream& out, const Order& order)
{
    int ssize = order.pizzas.size();
    out << order.state << endl;
    for(int i = 0; i < ssize; i++) {
        out << order.pizzas.at(i);
    }
    ssize = order.extras.size();
    for(int i = 0; i < ssize; i++) {
        out << order.extras.at(i);
    }
    out << endl;

    return out;
}
