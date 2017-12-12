#ifndef UI_SALESMAN_H
#define UI_SALESMAN_H

#include "toppingservice.h"
#include "PizzaService.h"
#include "ExtraService.h"
#include "OrderService.h"
#include "LocationService.h"
#include "BaseService.h"
#include "Location.h"
#include "topping.h"
#include "pizza.h"
#include "Extra.h"
#include "Order.h"
#include <iomanip>
#include <algorithm>
#include <stdlib.h>


class UI_Salesman
{
    public:
        void startUI();
        void orderSorting();

        void takeOrder();
        Pizza choosePizzaFromMenu();
        Pizza makePizza();
        Extra chooseExtraFromMenu();
        void removeFromOrder(Order* order);
        bool finishUpOrder(Order* order);

        void printOutOrder(Order order);
        void viewOrders();
        bool checkMenu(Pizza pizza);

    protected:

    private:
        ToppingService toppingService;
        PizzaService pizzaService;
        ExtraService extraService;
        OrderService orderService;
        LocationService locationService;
        BaseService baseService;
        Location salesmanLocation;
};

#endif // UI_SALESMAN_H
