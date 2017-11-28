#ifndef SUPERHERO_H
#define SUPERHERO_H

#include <iostream>
#include <string>

using namespace std;

class Superhero
{
    public:
        Superhero();
        Superhero(string name, int age, char superpower);

        string getSuperpower() const;

        friend ostream& operator <<(ostream &out, const Superhero &superhero);
        friend istream& operator >>(istream &in, Superhero &superhero);

    protected:

    private:
        string name;
        int age;
        char superpower;
};

#endif // SUPERHERO_H
