#ifndef LOCATION_H
#define LOCATION_H

#include <string.h>
#include <iostream>
using namespace std;

class Location
{
    public:
        Location();
        Location(string address, string city);

        /// Overwrites the istream operator
        /// Takes in address and city, in that order
        friend istream& operator >> (istream& in, Location &location);

        /// Overwrites the ostream operator
        /// Writes out address and city, in that order
        friend ostream& operator << (ostream& out, const Location &location);

        ///Getters and setters.
        string getAddress() const;
        string getCity() const;
        void setAddress(string address);
        void setCity(string city);

    protected:
    private:
        char address[32];
        char city[32];
};

#endif // LOCATION_H
