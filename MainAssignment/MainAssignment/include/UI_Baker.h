#ifndef UI_BAKER_H
#define UI_BAKER_H
#include "DataManager.h"
#include "topping.h"
#include "pizza.h"
#include "Extra.h"
#include "Order.h"
#include "OrderService.h"
#include "Location.h"
#include "LocationService.h"


class UI_Baker
{
    public:
        UI_Baker();
        virtual ~UI_Baker();
        void startUI();
        void seeActiveOrders();
        void changeActiveOrder(Order order);
        void seeAllOrders();
        void printOutOrders(vector<Order> validOrders);
        void printOutOrder(Order order);
    protected:
    private:
        OrderService orderService;
        Order order;
        LocationService locationService;
        vector<Location> locations;
        Location bakerLocation;
};

#endif // UI_BAKER_H
