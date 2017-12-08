#ifndef BASESERVICE_H
#define BASESERVICE_H

#include <vector>
#include <string>
#include "BaseRepository.h"
#include "Base.h"

class BaseService
{
    public:
        void addBase(const Base& base);
        bool isValidBase(const Base& base);
        vector<Base> getBases();

    protected:

    private:
        BaseRepository baseRepository;
};

#endif // BASESERVICE_H
