#ifndef BASE_H
#define BASE_H


#include <string.h>
#include <iostream>
#include <IdService.h>

using namespace std;

class Base
{
    public:
        ///////////////////////////////////////////////////////////////////////
        /// \brief Default constructor that sets variables to default values.
        ///////////////////////////////////////////////////////////////////////
        Base();

        ///////////////////////////////////////////////////////////////////////
        /// \brief Constructor that takes name and price and puts those
        ///        values in respected variables.
        ///
        /// \param name - The name of the topping, Will be changed to char.
        /// \param price - The price of the topping.
        ///////////////////////////////////////////////////////////////////////
        Base(string name, double price);

        void generateId();

        ///////////////////////////////////////////////////////////////////////
        /// \brief Overwrites the istream operator,
        ///        takes in name and price, in that order.
        ///////////////////////////////////////////////////////////////////////
        friend istream& operator >> (istream& in, Base& base);

        ///////////////////////////////////////////////////////////////////////
        /// \brief Overwrites the ostream operator,
        ///        returns name and price, in that order.
        ///////////////////////////////////////////////////////////////////////
        friend ostream& operator << (ostream& out, const Base& base);


        ///Getters and setters.
        double getPrice() const;
        string getName() const;
        void setPrice(double price);
        void setName(string name);
        void setId();
        int getId() const;

    protected:

    private:
        char name[32];
        double price;
        int id;
        IdService idService;
};


#endif // BASE_H
