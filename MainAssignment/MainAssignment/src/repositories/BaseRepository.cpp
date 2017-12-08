#include "BaseRepository.h"

void BaseRepository::addBase(Base base)
{
    ofstream fout;

    fout.open("data/baseList.dat", ios::binary|ios::app);

    fout.write((char*)(&base), sizeof(Base));

    fout.close();
}


vector<Base> BaseRepository::getBases()
{
    ifstream fin;

    fin.open("data/baseList.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Base);
    fin.seekg(0, fin.beg);

    Base *data = new Base[records];
    fin.read((char*)data, sizeof(Base) * records);

    vector<Base> returnVector;
    for(int i = 0; i < records; i++)
    {
        returnVector.push_back(data[i]);
    }

    return returnVector;
}
