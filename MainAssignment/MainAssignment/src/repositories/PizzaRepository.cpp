#include "PizzaRepository.h"


void PizzaRepository::addPizza(Pizza pizza)
{
    //Create an instance of ofstream.
    ofstream fout;

    //Open the pizzaMenu file
    fout.open("pizzaMenu.txt", ios::app);

    //Write the pizza data using the Pizza ostream overloader.
    fout << pizza;

    //Close the file
    fout.close();
}


vector<Pizza> PizzaRepository::getPizzas()
{
    //Create an instance of ifstream.
    ifstream fin;
    //Create a vector for the pizzas.
    vector<Pizza> returnVector;
    //Create an empty instance of Pizza.
    Pizza tempPizza;

    //Open the pizzaMenu file.
    fin.open("pizzaMenu.txt");

    //Check if the file was opened (check if it exists).
    if(fin.is_open())
    {
        //Loop until the end of file and fetch data using the Pizza istream overloader.
        while(fin >> tempPizza)
        {
            //Put the pizza into the vector
            returnVector.push_back(tempPizza);
            //Clear the toppings vector.
            tempPizza.clearToppings();
        }
    }
    else
    {
        //Print an error on the screen if the file could not be opened.
        cout << "Could not open file!" << endl;
    }

    //Close the file.
    fin.close();

    //Return the vector of pizzas.
    return returnVector;
}
