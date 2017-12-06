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

        friend ostream& operator << (ostream& out, const Extra& extra);
        friend istream& operator >> (istream& in, Extra& extra);

        ///Getters and setters.
        string getName() const;
        double getPrice() const;
        Extra::Type getType() const;
        void setName(string name);
        void setPrice(double price);
        void setType(Extra::Type type);

    protected:

    private:
        char name[32];
        double price;
        Extra::Type type;
};

#endif // EXTRA_H
