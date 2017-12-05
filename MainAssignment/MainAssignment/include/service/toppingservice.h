#ifndef TOPPINGSERVICE_H
#define TOPPINGSERVICE_H

#include <vector>
#include <string>
#include "ToppingRepository.h"
#include "topping.h"
#include "Toppingrepository.h"

class ToppingService
{
    public:
        void addTopping(const Topping& topping);
        bool isValidTopping(const Topping& topping);
        vector<Topping> getToppings();

    protected:

    private:
        ToppingRepository toppingRepository;

};

#endif // TOPPINGSERVICE_H
