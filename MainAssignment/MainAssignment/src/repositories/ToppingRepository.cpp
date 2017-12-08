#include "ToppingRepository.h"



void ToppingRepository::addTopping(Topping topping)
{
    ofstream fout;

    fout.open("toppingList.dat", ios::binary|ios::app);

    fout.write((char*)(&topping), sizeof(Topping));

    fout.close();
}


vector<Topping> ToppingRepository::getToppings()
{
    ifstream fin;

    fin.open("toppingList.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Topping);
    fin.seekg(0, fin.beg);

    Topping *data = new Topping[records];
    fin.read((char*)data, sizeof(Topping) * records);

    vector<Topping> returnVector;
    for(int i = 0; i < records; i++)
    {
        returnVector.push_back(data[i]);
    }

    return returnVector;
}
