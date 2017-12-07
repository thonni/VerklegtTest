#include "LocationService.h"

bool LocationService::isValidLocation(const Location& location)
{
    //Checks if the location name is an empty string, if it is
    //it returns false else it returns true.
    if(!location.getAddress().empty())
    {
        return true;
    }
    else if(!location.getCity().empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


void LocationService::addLocation(const Location& location)
{
    //Check if the input is a valid Location.
    if(this->isValidLocation(location))
    {
        //Ask the LocationRepository to save the location to file.
        locationRepository.addLocation(location);
    }
}


vector<Location> LocationService::getLocations()
{
    //Ask the LocationRepository for the location in a vector and return it.
    return locationRepository.getLocations();
}
