#include "../include/superhero.h"


Superhero::Superhero()
{
    this->name = "";
    this->age = 0;
    this->superpower = 'n';
    this->verbose = true;
}


Superhero::Superhero(string name, int age, char superpower)
{
    this->name = name;
    this->age = age;
    this->superpower = superpower;
    this->verbose = true;
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


void Superhero::setVerbose(bool v)
{
    this->verbose = v;
}


ostream& operator <<(ostream &out, const Superhero &superhero)
{
    if(superhero.verbose)
    {
        out << superhero.name << " (" << superhero.age << "): " << superhero.getSuperpower() << endl;
    }
    else
    {
        out << superhero.name << " " << superhero.age << " " << superhero.getSuperpower() << endl;
    }

    return out;
}


istream& operator >>(istream &in, Superhero &superhero)
{
    in >> superhero.name;
    in >> superhero.age;
    in >> superhero.superpower;

    return in;
}
