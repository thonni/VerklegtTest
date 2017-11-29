#include "Extra.h"

Extra::Extra()
{
    //ctor
}


Extra::~Extra()
{
    //dtor
}


ostream& operator << (ostream& out, const Extra& extra)
{
    return out;
}


istream& operator >> (istream& in, Extra& extra)
{
    return in;
}
