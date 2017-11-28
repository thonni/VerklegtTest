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
    fout.close();

    ifstream fin;

    fin.open("superherofile.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Superhero);
    fin.seekg(0, fin.beg);

    Superhero *hero1 = new Superhero[records];

    fin.read((char*)hero1, sizeof(Superhero) * records);

    fin.close();

    for(int i = 0; i < records; i++) {
        cout << hero1[i] << endl;
    }

    return 0;
}
