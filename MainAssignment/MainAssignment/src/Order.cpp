#include "Order.h"


Order::Order()
{

}


Order::Order(int id)
{
    this->id = id;
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


void Order::listPizzas()
{
    int ssize = this->pizzas.size();
    for(int i = 0; i < ssize; i++) {
        cout << (i + 1) << this->pizzas.at(i);
    }
}


void Order::listExtras()
{
    int ssize = this->extras.size();
    for(int i = 0; i < ssize; i++) {
        cout << (i + 1) << this->extras.at(i);
    }
}


ostream& operator << (ostream& out, const Order& order)
{
    Pizza tempPizza;
    Topping tempTopping;
    Extra tempExtra;

    out << order.id << " " << (int)order.state << " ";
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

    //Get the order id and state.
    in >> order.id >> tempState;
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


///Getters and setters.
Order::State Order::getState()
{
    return this->state;
}

void Order::setState(Order::State state)
{
    this->state = state;
}

bool Order::getPaidFor()
{
    return this->paidFor;
}

void Order::setPaidFor(bool paidFor)
{
    this->paidFor = paidFor;
}

vector<Pizza> Order::getPizzas()
{
    return this->pizzas;
}

vector<Extra> Order::getExtras()
{
    return this->extras;
}
