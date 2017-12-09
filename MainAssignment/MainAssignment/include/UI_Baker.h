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
        void printOutOrders();
    protected:
    private:
        OrderService orderService;
        Order order;
        LocationService locationService;
        vector<Order> orders;
        vector<Location> locations;
};

#endif // UI_BAKER_H
