#include "topping.h"


Topping::Topping()
{
    //Populate name and price with default values.
    this->name[0] = '\0';
    this->price = 0.0;
}


Topping::Topping(string name, double price)
{
    //Iterate trough the input string and put each character into the char array.
    for(unsigned int i = 0; i < name.length(); i++)
    {
        //Set the current character into the char array.
        this->name[i] = name[i];
        //Set the end character to the next character (Will be overwritten if it loops again).
        this->name[i+1] = '\0';
    }

    //Put the input price into price.
    this->price = price;
}


istream& operator >> (istream& in, Topping& topping)
{
    in >> topping.name >> topping.price;

    return in;
}


ostream& operator << (ostream& out, const Topping& topping)
{
    out << topping.name << " " << topping.price << endl;

    return out;
}



bool operator < (const Topping& toppingA, const Topping& toppingB)
{
    for(int i = 0; i < 32; i++)
    {
        if(toppingA.getName()[i] < toppingB.getName()[i])
        {
            return true;
        }
        else if(toppingA.getName()[i] < toppingB.getName()[i])
        {
            return false;
        }
    }
    return false;
}


bool operator == (const Topping& ToppingA, const Topping& toppingB)
{
    if(ToppingA.getName() == toppingB.getName())
    {
        return true;
    }
    return false;
}


double Topping::getPrice() const
{
    return this->price;
}

string Topping::getName() const
{
    //Convert char array name to string and store in return string
    string returnString = string(this->name);
    //Return the string.
    return returnString;
}

void Topping::setPrice(double price)
{
    this->price = price;
}

void Topping::setName(string name)
{
    //Iterate trough the input string and put each character into the char array.
    for(unsigned int i = 0; i < name.length(); i++)
    {
        //Set the current character into the char array.
        this->name[i] = name[i];
        //Set the end character to the next character (Will be overwritten if it loops again).
        this->name[i+1] = '\0';
    }
}
