#ifndef UI_DELIVERY_H
#define UI_DELIVERY_H
#include "DataManager.h"
#include "topping.h"
#include "pizza.h"
#include "Extra.h"
#include "Order.h"
#include "OrderService.h"
#include "Location.h"
#include "LocationService.h"

class UI_Delivery
{
    public:
        UI_Delivery();
        virtual ~UI_Delivery();
        void deliveryMenu();
        void printOutOrders(vector<Order> validOrders);
        void seeOrdersToBeDelivered();
        void changeDeliveryOrder(Order tempOrder);
        void printOutOrder(Order order);

    protected:
    private:
        OrderService orderService;
        Order order;
        LocationService locationService;
        vector<Location> locations;
        Location deliveryLocation;
};

#endif // UI_DELIVERY_H
