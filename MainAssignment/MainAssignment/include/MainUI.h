#ifndef MAINUI_H
#define MAINUI_H

#include <iostream>

#include "UI_Manager.h"
#include "UI_Salesman.h"
#include "UI_Baker.h"
#include "UI_Delivery.h"

using namespace std;

class MainUI
{
    public:
        void startUI();

    protected:

    private:
        UI_Manager manager;
        UI_Salesman salesman;

};

#endif // MAINUI_H
