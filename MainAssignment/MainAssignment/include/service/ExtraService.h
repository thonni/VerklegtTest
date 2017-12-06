#ifndef EXTRASERVICE_H
#define EXTRASERVICE_H

#include <vector>
#include "Extra.h"
#include "ExtraRepository.h"

class ExtraService
{
    public:
        bool isValidExtra(const Extra& extra);
        void addExtra(const Extra& extra);
        vector<Extra> getExtras();

    protected:

    private:
        ExtraRepository extraRepository;
};

#endif // EXTRASERVICE_H
