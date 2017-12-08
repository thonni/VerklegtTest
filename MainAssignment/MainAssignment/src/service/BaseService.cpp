#include "BaseService.h"

bool BaseService::isValidBase(const Base& base)
{
    //Checks if the base name is an empty string, if it is
    //it returns false else it returns true.
    if(!base.getName().empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


void BaseService::addBase(const Base& base)
{
    //Check if the input is a valid Base.
    if(this->isValidBase(base))
    {
        //Ask the BaseRepository to save the base to file.
        baseRepository.addBase(base);
    }
}


vector<Base> BaseService::getBases()
{
    //Ask the BaseRepository for the bases in a vector and return it.
    return baseRepository.getBases();
}
