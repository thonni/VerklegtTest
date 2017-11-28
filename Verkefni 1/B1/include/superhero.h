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
        void setVerbose(bool v);

        friend ostream& operator <<(ostream &out, const Superhero &superhero);
        friend istream& operator >>(istream &in, Superhero &superhero);

    protected:

    private:
        string name;
        int age;
        char superpower;
        bool verbose;
};

#endif // SUPERHERO_H
