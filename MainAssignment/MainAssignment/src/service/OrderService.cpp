#include "OrderService.h"

using namespace std;

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


void OrderService::setOrderState(int id, Order::State state)
{
    vector<Order> orders = this->getOrders();

    for(unsigned int i = 0; i < orders.size(); i++)
    {
        if(orders.at(i).getId() == id)
        {
            orders.at(i).setState(state);
        }
    }

    orderRepository.reAddOrders(orders);
}


Order OrderService::getOrder(int ID)
{
    vector<Order> orders = getOrders();
    for(unsigned int i = 0; i < orders.size(); i++)
    {
        if(orders[i].getId() == ID)
        {
            return orders[i];
        }
    }
    throw 0;
}
