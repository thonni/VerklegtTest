#include "ExtraRepository.h"


void ExtraRepository::addExtra(const Extra& extra)
{
    ofstream fout;

    fout.open("extraMenu.dat", ios::binary|ios::app);

    fout.write((char*)(&extra), sizeof(Extra));

    fout.close();
}


vector<Extra> ExtraRepository::getExtras()
{
    ifstream fin;

    fin.open("extraMenu.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Extra);
    fin.seekg(0, fin.beg);

    Extra *data = new Extra[records];
    fin.read((char*)data, sizeof(Extra) * records);

    vector<Extra> returnVector;
    for(int i = 0; i < records; i++)
    {
        returnVector.push_back(data[i]);
    }

    return returnVector;
}
