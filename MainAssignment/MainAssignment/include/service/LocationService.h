#ifndef LOCATIONSERVICE_H
#define LOCATIONSERVICE_H
#include <vector>
#include <string>
#include "LocationRepository.h"
#include "Location.h"

class LocationService
{
    public:
        void addLocation(const Location& location);
        bool isValidLocation(const Location& location);
        vector<Location> getLocations();

    protected:

    private:
        LocationRepository locationRepository;
};

#endif // LOCATIONSERVICE_H
