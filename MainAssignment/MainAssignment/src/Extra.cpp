#include "Extra.h"


Extra::Extra()
{
    this->name[0] = '\0';
    this->price = 0.0;
    this->type = SideDish;
}


Extra::Extra(string name, Extra::Type type, double price)
{
    //Iterate trough the input string and put each character into the char array.
    for(unsigned int i = 0; i < name.length(); i++)
    {
        //Set the current character into the char array.
        this->name[i] = name[i];
        //Set the end character to the next character (Will be overwritten if it loops again).
        this->name[i+1] = '\0';
    }

    //Put input price in to price and input type in to type;
    this->price = price;
    this->type = type;
}


ostream& operator << (ostream& out, const Extra& extra)
{
    out << extra.name << " " << extra.type << " " << extra.price << endl;

    return out;
}


istream& operator >> (istream& in, Extra& extra)
{
    //Temporary integer value to store type in.
    int tempType;

    //Fetch the data.
    in >> extra.name >> tempType >> extra.price;

    //Cast tempType over to enum Extra::Type and store in extra.type;
    extra.type = static_cast<Extra::Type>(tempType);

    return in;
}


///Getters and Setters.

string Extra::getName() const
{
    //Convert char array name to string and store in return string
    string returnString = string(this->name);
    //Return the string.
    return returnString;
}


double Extra::getPrice() const
{
    return this->price;
}


Extra::Type Extra::getType() const
{
    return this->type;
}

void Extra::setName(string name)
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

void Extra::setPrice(double price)
{
    this->price = price;
}

void Extra::setType(Extra::Type type)
{
    this->type = type;
}
