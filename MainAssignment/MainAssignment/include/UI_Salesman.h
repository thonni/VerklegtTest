#ifndef UI_SALESMAN_H
#define UI_SALESMAN_H

#include "toppingservice.h"
#include "PizzaService.h"
#include "topping.h"
#include "pizza.h"
#include "Extra.h"
#include "Order.h"


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

    protected:

    private:
        ToppingService toppingService;
        PizzaService pizzaService;
};

#endif // UI_SALESMAN_H
