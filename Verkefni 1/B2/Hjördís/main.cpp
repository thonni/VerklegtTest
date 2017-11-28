#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Superhero
{
public:
    Superhero();
    Superhero(char name[], int age, char superpower);
    
    void getSuperpower() const;
    
    friend ostream& operator <<(ostream &out, const Superhero &superhero);
    friend istream& operator >>(istream &in, Superhero &superhero);
  
private:
    char name[50];
    int age;
    char superpower;
};

Superhero::Superhero()
{
    this->name[0] = '\0';
    this->age = 0;
    this->superpower = 'n';
}

Superhero::Superhero(char name[], int age, char superpower)
{
    this->name[49] = name[49];
    this->age = age;
    this->superpower = superpower;
}

/*void Superhero::getSuperpower() const
{
    if(this->superpower == 'f')
    {
        cout << "Flying";
    }
    else if(this->superpower == 'g')
    {
        cout << "Giant";
    }
    else if(this->superpower == 'h')
    {
        cout << "Hacker";
    }
    else if(this->superpower == 'n')
    {
        cout << "None";
    }
    else
    {
        cout << "Weakling";
    }
}*/


ostream& operator <<(ostream &out, const Superhero &superhero)
{
    out << superhero.name << " (" << superhero.age << "): ";
    if (superhero.superpower == 'f')
    {
        out << "Flying" << endl;
    }
    if (superhero.superpower == 'g')
    {
        out << "Giant" << endl;
    }
    if (superhero.superpower == 'h')
    {
        out << "Hacker" << endl;
    }
    if (superhero.superpower == 'n')
    {
        out << "None" << endl;
    }
    else
    {
        out << "Weakling" << endl;
    }

    return out;
}


istream& operator >>(istream &in, Superhero &superhero)
{
    in >> superhero.name;
    in >> superhero.age;
    in >> superhero.superpower;
    
    return in;
}
int main()
{
    Superhero hero;
    cin >> hero;
    
    ofstream fout;
    fout.open ("/Users/hjordissveinsdottir/Desktop/HR/3onn/VerklegtnamskeidI/Assignments/Verk1B2/Verk1B2/superherofile.dat");
    
    fout << hero;
    
    /*char addHero = 'n';
    
    //Ask the user if he/she wants to add a hero.
    cout << "Add hero? (Y/N): ";
    cin >> addHero;
    
    if(addHero == 'y' || addHero == 'Y')
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
        
        //Create the ofstream file
        ofstream fout;
        fout.open("superheroes.txt", ios::app);
        
        fout << newHero;
        
        fout.close();*/

    return 0;
}
