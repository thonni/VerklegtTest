#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include <stdlib.h>
#include "Order.h"
#include "LocationService.h"
#include "BaseService.h"

using namespace std;

class OrderRepository
{
    public:
        void addOrder(const Order& order);
        vector<Order> getOrders();
        void clearOrders();

    protected:

    private:
        LocationService locationService;
        BaseService baseService;
};

#endif // ORDERREPOSITORY_H
