#include <iostream>
#include <fstream>
#include "include/superhero.h"

using namespace std;

int main()
{
    Superhero hero;
    cin >> hero;

    ofstream fout;
    fout.open ("superherofile.dat", ios::binary|ios::app);

    fout << hero;




    return 0;
}
