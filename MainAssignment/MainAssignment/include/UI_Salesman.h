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
        virtual ~UI_Salesman();
        void customerOrder();
        void orderSorting();
    protected:
    private:
};

#endif // UI_SALESMAN_H
