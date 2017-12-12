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

void OrderService::setOrderPaid(int id)
{
    vector<Order> orders = this->getOrders();

    for(unsigned int i = 0; i < orders.size(); i++)
    {
        if(orders.at(i).getId() == id)
        {
            orders.at(i).setPaidFor(true);
        }
    }

    orderRepository.reAddOrders(orders);
}


void OrderService::printOutAllOrders()
{
    Order tempOrder;
    Pizza tempPizza;
    Topping tempTopping;
    Extra tempExtra;
    int amountOfPizzas;
    int amountOfExtras;

    //Get all orders from file and store in a vector.
    vector<Order> orders = this->getOrders();

    for(unsigned int i = 0; i < orders.size(); i++)
    {
        //Stores the current order in a temporary order variable.
        tempOrder = orders.at(i);

        //Gets the amount of pizzas.
        amountOfPizzas = tempOrder.getPizzas().size();
        //Gets the amount of extras.
        amountOfExtras = tempOrder.getExtras().size();

        //Print out the order info: Id, amount of pizzas, and amount of extras.
        cout << "ID: " << tempOrder.getId() << " - Pizzas: " << amountOfPizzas << ", Extras: " << amountOfExtras << " - Status: ";

        //Print out the state of the order.
        if(tempOrder.getState() == Order::Received)
        {
            cout << " RECEIVED" << endl;
        }
        else if(tempOrder.getState() == Order::Prep)
        {
            cout << " PREP" << endl;
        }
        else if(tempOrder.getState() == Order::InOven)
        {
            cout << "IN OVEN" << endl;
        }
        else if(tempOrder.getState() == Order::Ready)
        {
            cout << "READY" << endl;
        }
        else if(tempOrder.getState() == Order::OnItsWay)
        {
            cout << "ON ITS WAY" << endl;
        }
        else if(tempOrder.getState() == Order::Delivered)
        {
            cout << "DELIVERED" << endl;
        }

        //Print out the location of the current order.
        cout << "Location: " << tempOrder.getLocation().getAddress() << " - " << tempOrder.getLocation().getCity() << endl;

        //Loop through all the pizzas if there are any.
        if(amountOfPizzas > 0)
        {
            cout << " PIZZAS: " << endl;
            for(unsigned int y = 0; y < tempOrder.getPizzas().size(); y++)
            {
                //Store the current pizza in a temporary pizza variable.
                tempPizza = tempOrder.getPizzas().at(y);

                //Prints out the current pizza name.
                cout << "  *" << tempPizza.getName() << " - ";
                //Prints out the current pizza size.
                if(tempPizza.getSize() == Pizza::Small)
                {
                    cout << "Small, ";
                }
                else if(tempPizza.getSize() == Pizza::Medium)
                {
                    cout << "Medium, ";
                }
                else if(tempPizza.getSize() == Pizza::Large)
                {
                    cout << "Large, ";
                }
                //Prints out the current pizza base.
                cout << tempPizza.getBase().getName() << endl;

                //Check if the current pizza is a custom pizza, and if so it prints out its toppings.
                if(tempPizza.getName() == "Custom Pizza")
                {
                    cout << "   -Toppings - ";
                    //Loop through all the toppings on the current pizza.
                    for(unsigned int j = 0; j < tempPizza.getToppings().size(); j++)
                    {
                        //Store the current topping in a temporary topping variable.
                        tempTopping = tempPizza.getToppings().at(j);

                        cout << tempTopping.getName();

                        if(j != tempPizza.getToppings().size() - 1)
                        {
                            cout << ", ";
                        }
                    }
                    cout << endl;
                }
            }
        }

        //Loop through all the extras if there are any.
        if(amountOfExtras > 0)
        {
            cout << " SIDE DISHES:" << endl;
            for(unsigned int j = 0; j < tempOrder.getExtras().size(); j++)
            {
                //Store the current extra in a temporary extra variable.
                tempExtra = tempOrder.getExtras().at(j);


                cout << "  *" << tempExtra.getName() << endl;
            }
        }

        cout << "----------------------------------------" << endl;
    }
}

///Getters and setters.

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
