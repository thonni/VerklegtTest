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
    vector<string> dataVector;
    vector<Base> availableBases = baseService.getBases();
    string data;
    string tempData;
    int counter;
    int numberOfToppings;

    //Open the pizzaMenu file.
    fin.open("pizzaMenu.txt");

    //Check if the file was opened (check if it exists).
    if(fin.is_open())
    {
        while(!fin.eof())
        {
            data = "";
            getline(fin, data);

            //Check if the data has any characters, and if so loop through each character
            //and separate the data into a string vector.
            if(data.length() > 0)
            {
                for(unsigned int i = 0; i < data.length(); i++)
                {
                    if(data[i] == '^' && data[i+1] == '~')
                    {
                        dataVector.push_back(tempData);
                        tempData = "";
                        i++;
                    }
                    else
                    {
                        tempData += data[i];
                    }
                }
                dataVector.push_back(tempData);
                tempData = "";


                Pizza tempPizza;
                Topping tempTopping;
                counter = 0;
                numberOfToppings = 0;

                //Get the pizza name
                tempPizza.setName(dataVector.at(counter));
                counter++;

                //Get the number of toppings on the pizza.
                numberOfToppings = atoi(dataVector.at(counter).c_str());
                counter++;
                for(int i = 0; i < numberOfToppings; i++)
                {
                    tempTopping.setName(dataVector.at(counter));
                    counter++;
                    tempTopping.setPrice((float)atoi(dataVector.at(counter).c_str()));
                    counter++;

                    tempPizza.addTopping(tempTopping);
                }

                //Set the base to the first base on file (Default base).
                tempPizza.setBase(availableBases.at(0));

                //Clear the dataVector for the next order;
                dataVector.clear();

                tempPizza.generatePrice();

                //Put the pizza into the returnVector.
                returnVector.push_back(tempPizza);

                //Clear the toppings in tempPizza.
                tempPizza.clearToppings();
            }
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
