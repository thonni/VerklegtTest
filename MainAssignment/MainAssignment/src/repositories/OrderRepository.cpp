#include "OrderRepository.h"


void OrderRepository::addOrder(const Order& order)
{
    //Create an instance of ofstream.
    ofstream fout;

    //Open the activeOrders file
    fout.open("activeOrders.txt", ios::app);

    //Write the pizza data using the Pizza ostream overloader.
    fout << order;

    //Close the file
    fout.close();
}


void OrderRepository::clearOrders()
{
    ofstream fout;

    fout.open("activeOrders.txt");

    fout.close();
}


vector<Order> OrderRepository::getOrders()
{
    //Create an instance of ifstream.
    ifstream fin;
    //Create a vector for the orders.
    vector<Order> returnVector;
    //Create an empty instance of Pizza.
    Order tempOrder;

    //Open the activeOrders file.
    fin.open("data/activeOrders.txt");

    //Check if the file was opened (check if it exists).
    if(fin.is_open())
    {
        //Loop until the end of file and fetch data using the Order istream overloader.
        while(fin >> tempOrder)
        {
            //Put the order into the vector
            returnVector.push_back(tempOrder);
        }
    }
    else
    {
        //Print an error on the screen if the file could not be opened.
        cout << "Could not open file!" << endl;
    }

    //Close the file.
    fin.close();

    //Return the vector of orders.
    return returnVector;
}
