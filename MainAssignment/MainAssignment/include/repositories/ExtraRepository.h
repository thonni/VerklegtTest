#ifndef EXTRAREPOSITORY_H
#define EXTRAREPOSITORY_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Extra.h"

class ExtraRepository
{
    public:
        void addExtra(const Extra& extra);
        vector<Extra> getExtras();

    protected:

    private:
};

#endif // EXTRAREPOSITORY_H
