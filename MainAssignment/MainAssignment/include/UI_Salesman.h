#ifndef UI_SALESMAN_H
#define UI_SALESMAN_H
#include "DataManager.h"
#include "topping.h"
#include "pizza.h"
#include "Extra.h"
#include "Order.h"


class UI_Salesman
{
    public:
        UI_Salesman();
        void startUI();
        void orderSorting();

        void takeOrder();
        Pizza choosePizzaFromMenu();
        Pizza makePizza();
        Extra chooseExtraFromMenu();
        void removeFromOrder(Order* order);
        void finishUpOrder(Order* order);

    protected:
    private:
};

#endif // UI_SALESMAN_H
