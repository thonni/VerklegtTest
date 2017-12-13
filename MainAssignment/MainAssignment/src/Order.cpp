#include "Order.h"


Order::Order()
{
    this->paidFor = false;
    this->homeDelivery = false;
    this->deliveryAddress = "";
    this->comment = "";
}


void Order::addPizza(Pizza pizza)
{
    this->pizzas.push_back(pizza);
}


void Order::clearPizzas()
{
    this->pizzas.clear();
}


void Order::addExtra(Extra extra)
{
    this->extras.push_back(extra);
}

void Order::clearExtras()
{
    this->extras.clear();
}


void Order::removePizza(int i)
{
    this->pizzas.erase(this->pizzas.begin() + i);
}


void Order::removeExtra(int i)
{
    this->extras.erase(this->extras.begin() + i);
}


void Order::generateId()
{
    this->id = idService.getNextId();
}


ostream& operator << (ostream& out, const Order& order)
{

    Pizza tempPizza;
    Topping tempTopping;
    Extra tempExtra;

    //Write out the order id, paidFor boolean, location id, order state, and home delivery boolean.
    out << order.id << "^~" << order.paidFor << "^~" << order.getLocation().getId() << "^~";
    out << (int)order.state << "^~" << order.homeDelivery << "," << order.deliveryAddress << "^~";

    //Write out the number of pizzas in the order
    out << order.pizzas.size() << "^~";
    //Loop trough all the pizzas in the order
    for(unsigned int i = 0; i < order.pizzas.size(); i++)
    {
        //Store the current pizza in a temporary Pizza variable.
        tempPizza = order.pizzas.at(i);


        out << tempPizza.getName() << "^~";

        out << (int)tempPizza.getSize() << "^~";

        out << tempPizza.getBase().getId() << "^~";

        //Write out the number of toppings on the current pizza.
        out << tempPizza.getToppings().size() << "^~";
        //Loops through the toppings in the order.
        for(unsigned int j = 0; j < tempPizza.getToppings().size(); j++)
        {
            //Store the current topping in a temporary Topping variable.
            tempTopping = tempPizza.getToppings().at(j);


            //Writes out the current topping name and price.
            out << tempTopping.getName() << "^~" << tempTopping.getPrice() << "^~";
        }
    }

    //Writes out the number of extras in the order.
    out << order.extras.size() << "^~";
    //Loops through all the extras in the order.
    for(unsigned int i = 0; i < order.extras.size(); i++)
    {
        //Store the current extra in a temporary Extra variable.
        tempExtra = order.extras.at(i);
        //Writes out the current topping name, price and type.
        out << tempExtra.getName() << "^~" << (int)(tempExtra.getType()) << "^~" << tempExtra.getPrice() << "^~";
    }

    out << order.comment;

    out << endl;

    return out;
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
Order::State Order::getState() const
{
    return this->state;
}

void Order::setState(Order::State state)
{
    this->state = state;
}

double Order::getPrice() const
{
    return this->totalPrice;
}

bool Order::getPaidFor() const
{
    return this->paidFor;
}

void Order::setPaidFor(bool paidFor)
{
    this->paidFor = paidFor;
}

bool Order::getHomeDelivery() const
{
    return this->homeDelivery;
}

void Order::setHomeDelivery(bool homeDelivery)
{
    this->homeDelivery = homeDelivery;
}

int Order::getId() const
{
    return this->id;
}

void Order::setId(int id)
{
    this->id = id;
}

vector<Pizza> Order::getPizzas() const
{
    return this->pizzas;
}

vector<Extra> Order::getExtras() const
{
    return this->extras;
}

Location Order::getLocation() const
{
    return this->location;
}

void Order::setLocation(Location location)
{
    this->location = location;
}

int Order::getAmountOfSideDishes()
{
    int amountOfSideDishes = 0;
    Extra tempExtra;

    for(unsigned int i = 0; i < this->extras.size(); i++)
    {
        tempExtra = this->extras.at(i);
        if(tempExtra.getType() == Extra::SideDish)
        {
            amountOfSideDishes++;
        }
    }

    return amountOfSideDishes;
}

string Order::getDeliveryAddress()
{
    return this->deliveryAddress;
}

void Order::setDeliveryAddress(string deliveryAddress)
{
    this->deliveryAddress = deliveryAddress;
}

string Order::getComment()
{
    return this->comment;
}

void Order::setComment(string comment)
{
    this->comment = comment;
}
