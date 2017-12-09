#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "IdService.h"
#include "pizza.h"
#include "Extra.h"
#include "Location.h"
#include "LocationService.h"
#include "BaseService.h"

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
        void clearPizzas();
        void addExtra(Extra extra);
        void clearExtras();
        void removePizza(int i);
        void removeExtra(int i);
        void generatePrice();
        void generateId();


        ///Getters and setters.
        Order::State getState() const;
        void setState(Order::State state);
        double getPrice() const;
        vector<Pizza> getPizzas() const;
        vector<Extra> getExtras() const;
        bool getPaidFor() const;
        void setPaidFor(bool paidFor);
        bool getHomeDelivery() const;
        void setHomeDelivery(bool homeDelivery);
        int getId() const;
        void setId(int id);
        Location getLocation() const;
        void setLocation(Location location);


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
        BaseService baseService;
        LocationService locationService;
        Location location;
};

#endif // ORDER_H
