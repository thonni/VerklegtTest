#include "OrderService.h"


bool OrderService::isValidOrder(const Order& order)
{
    return true;
}


void OrderService::addOrder(const Order& order)
{
    //Check if the input is a valid Pizza
    if(isValidOrder(order))
    {
        //Ask the PizzaRepository to save the pizza to file.
        orderRepository.addOrder(order);
    }
}


vector<Order> OrderService::getOrders()
{
    //Ask the orderRepository for the orders in a vector and return it.
    return orderRepository.getOrders();
}
