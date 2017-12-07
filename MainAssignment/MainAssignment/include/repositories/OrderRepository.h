#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include "Order.h"

class OrderRepository
{
    public:
        void addOrder(const Order& order);
        vector<Order> getOrders();
        void clearOrders();

    protected:

    private:
};

#endif // ORDERREPOSITORY_H
