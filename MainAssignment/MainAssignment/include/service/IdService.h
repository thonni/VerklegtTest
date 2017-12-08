#ifndef IDSERVICE_H
#define IDSERVICE_H

#include "IdRepository.h"

class IdService
{
    public:
        int getNextId();

    protected:

    private:
        IdRepository idRepository;
};

#endif // IDSERVICE_H
