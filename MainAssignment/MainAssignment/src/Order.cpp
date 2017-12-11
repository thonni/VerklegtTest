#include "Order.h"


Order::Order()
{
    this->paidFor = false;
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
    this->pizzas.at(i) = this->pizzas.back();
    this->pizzas.pop_back();
}


void Order::removeExtra(int i)
{
    this->extras.at(i - 1) = this->extras.back();
    this->extras.pop_back();
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
    out << order.id << "," << order.paidFor << "," << order.getLocation().getId() << "," << (int)order.state << "," << order.homeDelivery << ",";

    //Write out the number of pizzas in the order
    out << order.pizzas.size() << ",";
    //Loop trough all the pizzas in the order
    for(unsigned int i = 0; i < order.pizzas.size(); i++)
    {
        //Store the current pizza in a temporary Pizza variable.
        tempPizza = order.pizzas.at(i);


        out << tempPizza.getName() << ",";

        out << (int)tempPizza.getSize() << ",";

        out << tempPizza.getBase().getId() << ",";

        //Write out the number of toppings on the current pizza.
        out << tempPizza.getToppings().size() << ",";
        //Loops through the toppings in the order.
        for(unsigned int j = 0; j < tempPizza.getToppings().size(); j++)
        {
            //Store the current topping in a temporary Topping variable.
            tempTopping = tempPizza.getToppings().at(j);


            //Writes out the current topping name and price.
            out << tempTopping.getName() << "," << tempTopping.getPrice() << ",";
        }
    }

    //Writes out the number of extras in the order.
    out << order.extras.size() << ",";
    //Loops through all the extras in the order.
    for(unsigned int i = 0; i < order.extras.size(); i++)
    {
        //Store the current extra in a temporary Extra variable.
        tempExtra = order.extras.at(i);
        //Writes out the current topping name, price and type.
        out << tempExtra.getName() << "," << (int)(tempExtra.getType()) << "," << tempExtra.getPrice();
        if(i < order.extras.size()-1)
        {
            out << ",";
        }
    }

    out << endl;

    return out;

    /*Pizza tempPizza;
    Topping tempTopping;
    Extra tempExtra;

    //Write out the order id, paidFor boolean, location id, order state, and home delivery boolean.
    out << order.id << " " << order.paidFor << " " << order.getLocation().getId() << " " << (int)order.state << " " << order.homeDelivery << " ";

    //Write out the number of pizzas in the order
    out << order.pizzas.size() << " ";
    //Loop trough all the pizzas in the order
    for(unsigned int i = 0; i < order.pizzas.size(); i++)
    {
        //Store the current pizza in a temporary Pizza variable.
        tempPizza = order.pizzas.at(i);

        //Goes through the pizza name and replaces all ' ' with '~' and writes that.
        string tempName = "";
        for(int i = 0; i < 32; i++)
        {
            if(tempPizza.getName()[i] == ' ')
            {
                tempName += '~';
            }
            else if(tempPizza.getName()[i] == '\0')
            {
                break;
            }
            else
            {
                tempName += tempPizza.getName()[i];
            }
        }
        out << tempName << " ";

        out << tempPizza.getBase().getId() << " ";

        //Write out the number of toppings on the current pizza.
        out << tempPizza.getToppings().size() << " ";
        //Loops through the toppings in the order.
        for(unsigned int j = 0; j < tempPizza.getToppings().size(); j++)
        {
            //Store the current topping in a temporary Topping variable.
            tempTopping = tempPizza.getToppings().at(j);

            //Goes through the topping name and replaces all ' ' with '~' and saves that.
            tempName = "";
            for(int i = 0; i < 32; i++)
            {
                if(tempTopping.getName()[i] == ' ')
                {
                    tempName += '~';
                }
                else if(tempTopping.getName()[i] == '\0')
                {
                    break;
                }
                else
                {
                    tempName += tempTopping.getName()[i];
                }
            }
            //Writes out the current topping price.
            out << tempName << " " << tempTopping.getPrice() << " ";
        }
    }

    //Writes out the number of extras in the order.
    out << order.extras.size() << " ";
    //Loops through all the extras in the order.
    for(unsigned int i = 0; i < order.extras.size(); i++)
    {
        //Store the current extra in a temporary Extra variable.
        tempExtra = order.extras.at(i);
        //Writes out the current topping name, price and type.
        out << tempExtra.getName() << " " << (int)(tempExtra.getType()) << " " << tempExtra.getPrice() << " ";
    }

    out << endl;

    return out;*/
}


istream& operator >> (istream& in , Order& order)
{

    ///NOTHING HERE.


    /*Pizza tempPizza;
    Topping tempTopping;
    Extra tempExtra;
    Base tempBase;

    string tempName;
    double tempPrice;
    int tempLocationId;
    int tempBaseId;
    Location tempLocation;
    vector<Location> availableLocations = order.locationService.getLocations();
    vector<Base> availableBases = order.baseService.getBases();
    int tempType;
    int tempState;

    int size1, size2;

    //Get the order id and paidFor.
    in >> order.id >> order.paidFor;

    in >> tempLocationId;
    for(unsigned int i = 0; i < availableLocations.size(); i++)
    {
        tempLocation = availableLocations.at(i);
        if(tempLocation.getId() == tempLocationId)
        {
            order.setLocation(tempLocation);
        }
    }

    in >> tempState >> order.homeDelivery;
    order.state = (Order::State)(tempState);

    //Get the number of pizzas to come and loop through them
    in >> size1;
    for(int i = 0; i < size1; i++)
    {
        //Goes through the name input and replaces all '~' with ' ' and
        //set the name using setName.
        in >> tempName;
        string tempName2 = "";
        for(unsigned int i = 0; i < tempName.length(); i++)
        {
            if(tempName[i] == '~')
            {
                tempName2 += ' ';
            }
            else
            {
                tempName2 += tempName[i];
            }
        }
        tempPizza.setName(tempName2);

        in >> tempBaseId;

        for(unsigned int j = 0; j < availableBases.size(); j++)
        {
            tempBase = availableBases.at(j);
            if(tempBase.getId() == tempBaseId)
            {
                tempPizza.setBase(tempBase);
            }
        }


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

    //Get the number of extras to come and loop through them if there are any.
    in >> size1;
    if(size1 > 0)
    {
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
    }

    return in;*/
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
