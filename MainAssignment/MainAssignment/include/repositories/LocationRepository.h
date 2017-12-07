#ifndef LOCATIONREPOSITORY_H
#define LOCATIONREPOSITORY_H
#include <iostream>
#include <fstream>
#include <vector>
#include "Location.h"

class LocationRepository
{
    public:
        void addLocation(Location location);
        vector<Location> getLocations();
    protected:
    private:
};

#endif // LOCATIONREPOSITORY_H
