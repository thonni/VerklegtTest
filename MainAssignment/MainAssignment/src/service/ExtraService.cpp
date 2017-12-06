#include "ExtraService.h"


bool ExtraService::isValidExtra(const Extra& extra)
{
    //Checks if the extra name is an empty string, if it is
    //it returns false else it returns true.
    if(!extra.getName().empty())
    {
        return true;
    }
    else
    {
        return false;
    };
}


void ExtraService::addExtra(const Extra& extra)
{
    //Check if the input is a valid Extra.
    if(this->isValidExtra(extra))
    {
        //Ask the ExtraRepository to save the extra to file.
        extraRepository.addExtra(extra);
    }
}


vector<Extra> ExtraService::getExtras()
{
    //Ask the ExtraRepository for the extras in a vector and return it.
    return extraRepository.getExtras();
}
