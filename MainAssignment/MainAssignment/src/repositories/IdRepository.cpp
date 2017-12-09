#include "IdRepository.h"


int IdRepository::getNextId()
{
    ofstream fout;
    ifstream fin;
    int id;

    fin.open("id.txt");

    if(!fin.is_open())
    {
        fin.close();
        int number = 0;
        fout.open("id.txt");
        fout << number;
        fout.close();
        fin.open("id.txt");
    }


    fin >> id;

    fin.close();

    fout.open("id.txt");

    fout << id+1;

    fout.close();

    return id;
}
