#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "pizza.h"
#include "Extra.h"

using namespace std;

class Order
{
    public:
        Order();
        Order(int id);
        void addPizza(Pizza pizza);
        void addExtra(Extra extra);
        void removePizza(int i);
        void removeExtra(int i);
        void listPizzas();
        void listExtras();

        ///Getters and setters.
        char getState();


        friend ostream& operator << (ostream& out, const Order& order);
        friend istream& operator >> (istream& in , Order& order);

    protected:

    private:
        int id;
        char state;
        vector<Pizza> pizzas;
        vector<Extra> extras;
        double totalPrice;
};

#endif // ORDER_H
