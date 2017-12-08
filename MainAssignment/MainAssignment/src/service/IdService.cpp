#include "IdService.h"

int IdService::getNextId()
{
    return idRepository.getNextId();
}
