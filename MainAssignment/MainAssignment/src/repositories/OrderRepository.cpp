#include "OrderRepository.h"


void OrderRepository::addOrder(const Order& order)
{
    //Create an instance of ofstream.
    ofstream fout;

    //Open the activeOrders file
    fout.open("data/activeOrders.txt", ios::app);

    //Write the pizza data using the Pizza ostream overloader.
    fout << order;

    //Close the file
    fout.close();
}


vector<Order> OrderRepository::getOrders()
{

}
