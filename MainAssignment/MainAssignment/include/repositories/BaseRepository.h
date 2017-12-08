#ifndef BASEREPOSITORY_H
#define BASEREPOSITORY_H

#include <iostream>
#include <fstream>
#include <vector>
#include "base.h"

class BaseRepository
{
    public:
        void addBase(Base base);
        vector<Base> getBases();
    protected:
    private:
};

#endif // BASEREPOSITORY_H
