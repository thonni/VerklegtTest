#ifndef TOPPING_H
#define TOPPING_H

#include <string.h>
#include <iostream>

using namespace std;

class Topping
{
    public:
        ///////////////////////////////////////////////////////////////////////
        /// \brief Default constructor that sets variables to default values.
        ///////////////////////////////////////////////////////////////////////
        Topping();

        ///////////////////////////////////////////////////////////////////////
        /// \brief Constructor that takes name and price and puts those
        ///        values in respected variables.
        ///
        /// \param name - The name of the topping, Will be changed to char.
        /// \param price - The price of the topping.
        ///////////////////////////////////////////////////////////////////////
        Topping(string name, double price);

        ///////////////////////////////////////////////////////////////////////
        /// \brief Overwrites the istream operator,
        ///        takes in name and price, in that order.
        ///////////////////////////////////////////////////////////////////////
        friend istream& operator >> (istream& in, Topping& topping);

        ///////////////////////////////////////////////////////////////////////
        /// \brief Overwrites the ostream operator,
        ///        returns name and price, in that order.
        ///////////////////////////////////////////////////////////////////////
        friend ostream& operator << (ostream& out, const Topping& topping);


        friend bool operator < (const Topping& toppingA, const Topping& toppingB);


        friend bool operator == (const Topping& ToppingA, const Topping& toppingB);


        ///Getters and setters.
        double getPrice() const;
        string getName() const;
        void setPrice(double price);
        void setName(string name);

    protected:

    private:
        char name[32];
        double price;
};

#endif // TOPPING_H
