#include "Base.h"

Base::Base()
{
    //Populate name and price with default values.
    this->name[0] = '\0';
    this->price = 0.0;
}


Base::Base(string name, double price)
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

void Base::generateId()
{
    this->id = idService.getNextId();
}


istream& operator >> (istream& in, Base& base)
{
    in >> base.id >> base.name >> base.price;

    return in;
}


ostream& operator << (ostream& out, const Base& base)
{
    out << base.id << " " << base.name << " " << base.price << endl;

    return out;
}


double Base::getPrice() const
{
    return this->price;
}

string Base::getName() const
{
    //Convert char array name to string and store in return string
    string returnString = string(this->name);
    //Return the string.
    return returnString;
}

void Base::setPrice(double price)
{
    this->price = price;
}

void Base::setName(string name)
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

void Base::setId()
{
    this->id = id;
}

int Base::getId() const
{
    return this->id;
}
