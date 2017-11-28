#include <iostream>
#include <fstream>
#include "include/superhero.h"

using namespace std;

int main()
{
    int arrsize;
    cout << "How many heroes do you want to enter? ";
    cin >> arrsize;
    Superhero hero[arrsize];
    for(int i = 0; i < arrsize; i++) {
        cin >> hero[i];
        cout << endl;
    }

    ofstream fout;

    fout.open ("superherofile.dat", ios::binary|ios::app);
    fout.write((char*)hero, sizeof(Superhero) * arrsize);

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
        cout << hero1[i];
        cout << endl;
    }

    return 0;
}
