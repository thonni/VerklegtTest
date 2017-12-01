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


double Topping::getPrice()
{
    return this->price;
}

string Topping::getName()
{
    //Create temporary variables to store the return string
    //and the iterator.
    string returnString = "";
    char currentChar;
    int i = 0;

    //Loop until it comes to the end of the character array.
    while(this->name[i] != '\0');
    {
        //Check if it is at the end of the character array.
        if(this->name[i] != '\0')
        {
            //Add the current character to the return string.
            returnString += this->name[i];;
        }

        i++;
    }

    return returnString;
}
