#include "pizza.h"


Pizza::Pizza()
{

}


Pizza::Pizza(string name, int toppingsCount)
{

    //Iterate trough the input string and put each character into the char array.
    for(unsigned int i = 0; i < name.length(); i++)
    {
        //Set the current character into the char array.
        this->name[i] = name[i];
        //Set the end character to the next character (Will be overwritten if it loops again).
        this->name[i+1] = '\0';
    }

    //Put the input toppingsCount into toppingsCount.
    this->toppingsCount = toppingsCount;

    //Check if toppingsCount is more than 0, if so it creates the dynamic toppings array,
    //if it is 0 it sets the toppings array to NULL.
    if(toppingsCount != 0)
    {
        this->toppings = new Topping[toppingsCount];
    }
    else
    {
        this->toppings = NULL;
    }
}


void Pizza::addToppings()
{
    //Check if there are any toppings to be set.
    if(this->toppings != NULL)
    {
        //Iterate trough the toppings array.
        for(int i = 0; i < this->toppingsCount; i++)
        {
            cin >> toppings[i];
        }
    }
}


ostream& operator << (ostream& out, const Pizza& pizza)
{
    return out;
}


istream& operator >> (istream& in, Pizza& pizza);
{
    return in;
}


Pizza::~Pizza()
{
    if(this->toppings != NULL)
    {
        delete[] this->toppings;
    }
}
