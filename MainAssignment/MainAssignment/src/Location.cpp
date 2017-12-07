#include "Location.h"

Location::Location()
{
    //Populate address and city with default values.
    this->address[0] = '\0';
    this->city[0] = '\0';
}

Location::Location(string address, string city)
{
    //Iterate trough the input string and put each character into the char array.
    for(unsigned int i = 0; i < address.length(); i++)
    {
        //Set the current character into the char array.
        this->address[i] = address[i];
        //Set the end character to the next character (Will be overwritten if it loops again).
        this->address[i+1] = '\0';
    }
    for(unsigned int i = 0; i < city.length(); i++)
    {
        //Set the current character into the char array.
        this->city[i] = city[i];
        //Set the end character to the next character (Will be overwritten if it loops again).
        this->city[i+1] = '\0';
    }
}

istream& operator >> (istream& in, Location &location)
{
    in >> location.address >> location.city;
    return in;
}

ostream& operator << (ostream& out, const Location &location)
{
    out << location.address << location.city;
    return out;
}

string Location::getAddress() const
{
    //Convert char array name to string and store in return string
    string returnString = string(this->address);
    //Return the string.
    return returnString;
}

string Location::getCity() const
{
    //Convert char array name to string and store in return string
    string returnString = string(this->city);
    //Return the string.
    return returnString;
}

void Location::setAddress(string address)
{
    for(unsigned int i = 0; i < address.length(); i++)
    {
        //Set the current character into the char array.
        this->address[i] = address[i];
        //Set the end character to the next character (Will be overwritten if it loops again).
        this->address[i+1] = '\0';
    }
}

void Location::setCity(string city)
{
    for(unsigned int i = 0; i < city.length(); i++)
    {
        //Set the current character into the char array.
        this->city[i] = city[i];
        //Set the end character to the next character (Will be overwritten if it loops again).
        this->city[i+1] = '\0';
    }
}



