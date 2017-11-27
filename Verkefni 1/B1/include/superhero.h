#ifndef SUPERHERO_H
#define SUPERHERO_H

#include <string>

class Superhero
{
    public:
        Superhero(std::string name, int age, char superpower);

    protected:

    private:
        std::string name;
        int age;
        char superpower;
};

#endif // SUPERHERO_H
