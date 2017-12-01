#include "pizza.h"


Pizza::Pizza()
{
    this->name[0] = '\0';
    this->pizzaSize = Small;
    this->price = 0.0;
}


Pizza::Pizza(string name, Pizza::Size pizzaSize = Small)
{

    //Iterate trough the input string and put each character into the char array.
    for(unsigned int i = 0; i < name.length(); i++)
    {
        //Set the current character into the char array.
        this->name[i] = name[i];
        //Set the end character to the next character (Will be overwritten if it loops again).
        this->name[i+1] = '\0';
    }

    //Put the pizzaSize input in pizzaSize.
    this->pizzaSize = pizzaSize;
}


void Pizza::addTopping(Topping topping)
{
    this->toppings.push_back(topping);
}


<<<<<<< HEAD
double Pizza::generatePrice(double extraCost = 0.0)
=======
void Pizza::generatePrice()
{
    this->generatePrice(0.0);
}


void Pizza::generatePrice(double extraCost = 0.0)
>>>>>>> 70912da1a64aefdffb1950821fac2d73a8d2ac71
{
    //Create temporary variables for price and a Topping class.
    double tempPrice = 0;
    Topping tempTopping;

    //Loop trough all toppings that Pizza is storing and add
    //the price of those toppings to tempPrice.
    for(unsigned int i = 0; i < this->toppings.size(); i++)
    {
        tempTopping = this->toppings.at(i);
        tempPrice += tempTopping.getPrice();
    }
    //Add extraCost to tempPrice
    tempPrice += extraCost;

    //Set price to be the calculated tempPrice.
    this->price = tempPrice;
    return tempPrice;
}


ostream& operator << (ostream& out, const Pizza& pizza)
{
    return out;
}


istream& operator >> (istream& in, Pizza& pizza)
{
    return in;
}


///Getters and setters.
int Pizza::getToppingCount()
{
    return this->toppings.size();
}

double Pizza::getPrice()
{
    return this->price;
}

string Pizza::getName()
{
    //Convert char array name to string and store in return string
    string returnString = string(this->name);
    //Return the string.
    return returnString;
}


vector<Topping> Pizza::getToppings()
{
    return this->toppings;
}
