#ifndef LOCATION_H
#define LOCATION_H

#include <string.h>
#include <iostream>

#include "IdService.h"

using namespace std;

class Location
{
    public:
        Location();
        Location(string address, string city);
        void generateId();

        /// Overwrites the istream operator
        /// Takes in address and city, in that order
        friend istream& operator >> (istream& in, Location &location);

        /// Overwrites the ostream operator
        /// Writes out address and city, in that order
        friend ostream& operator << (ostream& out, const Location &location);

        ///Getters and setters.
        string getAddress() const;
        string getCity() const;
        int getId() const;
        void setAddress(string address);
        void setCity(string city);
        void setId(int id);

    protected:
    private:
        IdService idService;
        char address[32];
        char city[32];
        int id;
};

#endif // LOCATION_H
