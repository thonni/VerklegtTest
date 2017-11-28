#include <iostream>
#include <fstream>
#include "include/superhero.h"

using namespace std;

int main()
{
    char addHero = 'n';

    //Ask the user if he/she wants to add a hero.

    do {
        cout << "Add hero? (Y/N): ";
        cin >> addHero;
    } while (!(toupper(addHero) == 'N' || toupper(addHero) == 'Y'));

    if(toupper(addHero) == 'Y')
    {
        string name = "";
        int age = 0;
        char superpower = 'n';

        //Ask for the hero's name.
        cout << "Name: ";
        cin >> name;

        //Ask for the hero's age.
        cout << "Age: ";
        cin >> age;

        //Ask for the hero's superpower.
        cout << "Please enter a superpower:" << endl;
        cout << "Input f for Flying" << endl;
        cout << "Input g for Giant" << endl;
        cout << "Input h for Hacker" << endl;
        cout << "Input n for None" << endl;
        cout << "If other input, your superhero is a Weakling" << endl;
        cout << "Superpower: ";
        cin >> superpower;

        //Create a new Superhero using the user input.
        Superhero newHero(name, age, superpower);

        //Create the ofstream file.
        ofstream fout;
        fout.open("superheroes.txt", ios::app);

        //Save the hero information to text file.
        newHero.setVerbose(false);
        fout << newHero;
        newHero.setVerbose(true);

        //Close the file
        fout.close();

    }

    //Create the ifstream file.
    ifstream fin;
    fin.open("superheroes.txt");

    //Check if the file is open (Check if it exists).
    if(fin.is_open())
    {
        string name;
        int age;
        char superpower;

        //Loop until the file ends.
        while(!fin.eof())
        {
            //Fetch the data.
            fin >> name;
            fin >> age;
            fin >> superpower;

            //Create a Superhero with the data
            Superhero tempHero(name, age, superpower);

            //Print the Superhero to the screen.
            cout << tempHero << endl;
        }

        //Close the file.
        fin.close();
    }
    else
    {
        //If the file didn't open, print an error to the screen.
        cout << "ERROR: Could not open file" << endl;
    }

    //Stuff Thorri needs to do because the program closes the moment it ends.
    cin >> addHero;



    return 0;
}
