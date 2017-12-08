#ifndef IDREPOSITORY_H
#define IDREPOSITORY_H

#include <iostream>
#include <fstream>

using namespace std;

class IdRepository
{
    public:
        int getNextId();
        void resetId();

    protected:

    private:
};

#endif // IDREPOSITORY_H
