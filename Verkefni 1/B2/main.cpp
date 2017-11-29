#include <iostream>
#include <fstream>
#include "include/superhero.h"

using namespace std;

int main()
{
    int arrsize;
    cout << "How many heroes do you want to enter? ";
    cin >> arrsize;
    Superhero *hero = new Superhero[arrsize];
    for(int i = 0; i < arrsize; i++) {
        hero[i].setVerbose(false);
        cin >> hero[i];
        cout << endl;
    }

    ofstream fout;

    fout.open ("superherofile.dat", ios::binary|ios::app);
    fout.write((char*)hero, sizeof(Superhero) * arrsize);

    fout.close();
    delete[]  hero;
    ifstream fin;

    fin.open("superherofile.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Superhero);
    fin.seekg(0, fin.beg);

    Superhero *hero1 = new Superhero[records];
    fin.read((char*)hero1, sizeof(Superhero) * records);

    fin.close();

    for(int i = 0; i < records; i++) {
        hero1[i].setVerbose(true);
        cout << hero1[i];
        cout << endl;
    }
    delete[] hero1;

    return 0;
}
