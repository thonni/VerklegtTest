#include "../include/superhero.h"


Superhero::Superhero()
{
    this->name = "";
    this->age = 0;
    this->superpower = 'n';
}


Superhero::Superhero(std::string name, int age, char superpower)
{
    this->name = name;
    this->age = age;
    this->superpower = superpower;
}


string Superhero::getSuperpower() const
{
    if(this->superpower == 'f')
    {
        return "Flying";
    }
    else if(this->superpower == 'g')
    {
        return "Giant";
    }
    else if(this->superpower == 'h')
    {
        return "Hacker";
    }
    else if(this->superpower == 'n')
    {
        return "None";
    }
    else
    {
        return "Weakling";
    }
}


ostream& operator <<(ostream &out, const Superhero &superhero)
{
    out << superhero.name << " (" << superhero.age << "): " << superhero.getSuperpower() << endl;

    return out;
}


istream& operator >>(istream &in, Superhero &superhero)
{
    in >> superhero.name;
    in >> superhero.age;
    in >> superhero.superpower;

    return in;
}
