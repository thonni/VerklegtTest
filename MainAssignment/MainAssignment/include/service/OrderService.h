#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include <vector>
#include "OrderRepository.h"
#include "Order.h"

class OrderService
{
    public:
        bool isValidOrder(const Order& order);
        void addOrder(const Order& order);
        vector<Order> getOrders();
        void setOrderState(int id, Order::State state);
        void setOrderPaid(int id);
        void printOutAllOrders();

        ///Getters and setters.
        Order getOrder(int ID);

    protected:

    private:
        OrderRepository orderRepository;
};

#endif // ORDERSERVICE_H
