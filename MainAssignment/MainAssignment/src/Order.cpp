#include "Order.h"


Order::Order()
{

}


void Order::addPizza(Pizza pizza)
{
    this->pizzas.push_back(pizza);
}


void Order::addExtra(Extra extra)
{
    this->extras.push_back(extra);
}


void Order::removePizza(int i)
{
    this->pizzas.at(i) = this->pizzas.back();
    this->pizzas.pop_back();
}


void Order::removeExtra(int i)
{
    this->extras.at(i - 1) = this->extras.back();
    this->extras.pop_back();
}


ostream& operator << (ostream& out, const Order& order)
{
    Pizza tempPizza;
    Topping tempTopping;
    Extra tempExtra;

    out << order.id << " " << (int)order.state << " " << order.homeDelivery << " ";
    out << order.pizzas.size() << " ";
    for(unsigned int i = 0; i < order.pizzas.size(); i++)
    {
        tempPizza = order.pizzas.at(i);
        out << tempPizza.getName() << " ";
        out << tempPizza.getToppings().size() << " ";
        for(unsigned int j = 0; j < tempPizza.getToppings().size(); j++)
        {
            tempTopping = tempPizza.getToppings().at(j);
            out << tempTopping.getName() << " " << tempTopping.getPrice() << " ";
        }
    }

    out << order.extras.size() << " ";
    for(unsigned int i = 0; i < order.extras.size(); i++)
    {
        tempExtra = order.extras.at(i);
        out << tempExtra.getName() << " " << (int)(tempExtra.getType()) << " " << tempExtra.getPrice() << " ";
    }

    return out;
}


void Order::generateId()
{
    this->id = idService.getNextId();
}


istream& operator >> (istream& in , Order& order)
{
    Pizza tempPizza;
    Topping tempTopping;
    Extra tempExtra;

    string tempName;
    double tempPrice;
    int tempType;
    int tempState;

    int size1, size2;

    //Get the order id, state and homeDelivery.
    in >> order.id >> tempState >> order.homeDelivery;
    order.state = (Order::State)(tempState);

    //Get the number of pizzas to come and loop through them
    in >> size1;
    for(int i = 0; i < size1; i++)
    {
        //Store the pizza name in a temporary variable and
        //set the name using setName.
        in >> tempName;
        tempPizza.setName(tempName);

        //Get the number of toppings on the pizza and loop through them.
        in >> size2;
        for(int j = 0; j < size2; j++)
        {
            //Store the toppings name and price in the temporary variables.
            in >> tempName >> tempPrice;
            //Set the tempTopping name and price.
            tempTopping.setName(tempName);
            tempTopping.setPrice(tempPrice);
            //Add the topping to the pizza.
            tempPizza.addTopping(tempTopping);
        }
        //Make the pizza generate its price.
        tempPizza.generatePrice();
        //Add the pizza to the order.
        order.addPizza(tempPizza);
    }

    //Get the number of extras to come and loop trough them.
    in >> size1;
    for(int i = 0; i < size1; i++)
    {
        //Get the extra's name, type and price,
        //and store in the temporary variables.
        in >> tempName >> tempType >> tempPrice;
        //Set the temp extra name type and price to the input.
        tempExtra.setName(tempName);
        tempExtra.setType((Extra::Type)(tempType));
        tempExtra.setPrice(tempPrice);
        //Add the extra to the order.
        order.addExtra(tempExtra);
    }

    return in;
}


void Order::generatePrice()
{
    Pizza tempPizza;
    Extra tempExtra;

    this->totalPrice = 0;

    //Loop through all pizzas and add their price to the total price.
    for(unsigned int i = 0; i < this->pizzas.size(); i++)
    {
        tempPizza = this->pizzas.at(i);
        this->totalPrice += tempPizza.getPrice();
    }

    //Loop through all extras and add their price to the total price.
    for(unsigned int i = 0; i < this->extras.size(); i++)
    {
        tempExtra = this->extras.at(i);
        this->totalPrice += tempExtra.getPrice();
    }
}


///Getters and setters.
Order::State Order::getState()
{
    return this->state;
}

void Order::setState(Order::State state)
{
    this->state = state;
}

double Order::getPrice()
{
    return this->totalPrice;
}

bool Order::getPaidFor()
{
    return this->paidFor;
}

void Order::setPaidFor(bool paidFor)
{
    this->paidFor = paidFor;
}

bool Order::getHomeDelivery()
{
    return this->homeDelivery;
}

void Order::setHomeDelivery(bool homeDelivery)
{
    this->homeDelivery = homeDelivery;
}

int Order::getId()
{
    return this->id;
}

void Order::setId(int id)
{
    this->id = id;
}

vector<Pizza> Order::getPizzas()
{
    return this->pizzas;
}

vector<Extra> Order::getExtras()
{
    return this->extras;
}
