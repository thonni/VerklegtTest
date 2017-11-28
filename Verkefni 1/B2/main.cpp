#include <iostream>
#include <fstream>
#include "include/superhero.h"

using namespace std;

int main()
{
    Superhero hero;
    cin >> hero;

    ofstream fout;

    hero.setVerbose(false);

    fout.open ("superherofile.dat", ios::binary|ios::app);
    fout.write((char*)(&hero), sizeof(Superhero));

    hero.setVerbose(true);



    return 0;
}
