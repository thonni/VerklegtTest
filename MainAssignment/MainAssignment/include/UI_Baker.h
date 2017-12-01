#ifndef UI_BAKER_H
#define UI_BAKER_H
#include "DataManager.h"
#include "topping.h"
#include "pizza.h"
#include "Extra.h"
#include "Order.h"

class UI_Baker
{
    public:
        UI_Baker();
        virtual ~UI_Baker();
        void bakerMenu();
    protected:
    private:
};

#endif // UI_BAKER_H
