#ifndef UI_BAKER_H
#define UI_BAKER_H
#include "DataManager.h"
#include "topping.h"
#include "pizza.h"
#include "Extra.h"
#include "Order.h"
#include "OrderService.h"


class UI_Baker
{
    public:
        UI_Baker();
        virtual ~UI_Baker();
        void startUI();
    protected:
    private:
        OrderService orderService;
        Order order;
};

#endif // UI_BAKER_H
