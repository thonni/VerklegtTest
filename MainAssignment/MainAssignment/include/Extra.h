#ifndef EXTRA_H
#define EXTRA_H

#include <iostream>
#include <fstream>

using namespace std;

class Extra
{
    public:

        enum Type
        {
            Drink,
            Sauce,
            SideDish
        };

        Extra();
        Extra(string name, Extra::Type type, double price);
        virtual ~Extra();

        friend ostream& operator << (ostream& out, const Extra& extra);
        friend istream& operator >> (istream& in, Extra& extra);

    protected:

    private:
        char name[32];
        double price;
        Extra::Type type;
};

#endif // EXTRA_H
