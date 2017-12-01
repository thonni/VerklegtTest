#ifndef UI_DELIVERY_H
#define UI_DELIVERY_H
#include "DataManager.h"
#include "topping.h"
#include "pizza.h"
#include "Extra.h"
#include "Order.h"

class UI_Delivery
{
    public:
        UI_Delivery();
        virtual ~UI_Delivery();
        void deliveryMenu();
    protected:
    private:
};

#endif // UI_DELIVERY_H
