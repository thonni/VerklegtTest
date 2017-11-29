#include "Topping.h"


Topping::Topping()
{
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


ostream& operator << (ostream& out const Topping& topping)
{
    out << topping.name << " " << topping.price << endl;
}


Topping::~Topping()
{
    //dtor
}
