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
    protected:
    private:
        OrderService orderService;
        Order order;
        LocationService locationService;
        vector<Location> locations;
};

#endif // UI_DELIVERY_H
