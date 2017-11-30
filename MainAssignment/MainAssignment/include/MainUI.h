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
        MainUI();
        virtual ~MainUI();

        void startUI();

    protected:

    private:

};

#endif // MAINUI_H
