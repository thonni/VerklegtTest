#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "IdService.h"
#include "pizza.h"
#include "Extra.h"

using namespace std;

class Order
{
    public:

        enum State
        {
            Received,
            Prep,
            InOven,
            Ready,
            OnItsWay,
            Delivered
        };

        Order();
        void addPizza(Pizza pizza);
        void addExtra(Extra extra);
        void removePizza(int i);
        void removeExtra(int i);
        void generatePrice();
        void generateId();

        ///Getters and setters.
        Order::State getState();
        void setState(Order::State state);
        double getPrice();
        vector<Pizza> getPizzas();
        vector<Extra> getExtras();
        bool getPaidFor();
        void setPaidFor(bool paidFor);
        bool getHomeDelivery();
        void setHomeDelivery(bool homeDelivery);
        int getId();
        void setId(int id);


        friend ostream& operator << (ostream& out, const Order& order);
        friend istream& operator >> (istream& in , Order& order);

    protected:

    private:
        int id;
        Order::State state;
        vector<Pizza> pizzas;
        vector<Extra> extras;
        double totalPrice;
        bool paidFor;
        bool homeDelivery;
        IdService idService;
};

#endif // ORDER_H
