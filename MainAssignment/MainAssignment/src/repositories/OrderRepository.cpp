#include "OrderRepository.h"


void OrderRepository::addOrder(const Order& order)
{
    //Create an instance of ofstream.
    ofstream fout;

    //Open the activeOrders file
    fout.open("activeOrders.txt", ios::app);

    //Write the pizza data using the Pizza ostream overloader.
    fout << order;

    //Close the file
    fout.close();
}


void OrderRepository::reAddOrders(vector<Order> orders)
{
    Order tempOrder;
    //Create an instance of ofstream.
    ofstream fout;

    //Open the activeOrders file
    fout.open("activeOrders.txt");

    //Loop through all the orders in the vector.
    for(unsigned int i = 0; i < orders.size(); i++)
    {
        //Store the current order in a temporary Order variable.
        tempOrder = orders.at(i);
        //Write the pizza data using the Pizza ostream overloader.
        fout << tempOrder;
    }

    //Close the file
    fout.close();
}


void OrderRepository::clearOrders()
{
    ofstream fout;

    fout.open("activeOrders.txt");

    fout.close();
}


vector<Order> OrderRepository::getOrders()
{
    //Create an instance of ifstream.
    ifstream fin;
    //Create a vector for the orders.
    vector<Location> availableLocations = locationService.getLocations();
    vector<Base> availableBases = baseService.getBases();
    vector<Order> returnVector;
    //Create an empty instance of order.
    Order tempOrder;
    string data;
    string tempData = "";
    vector<string> dataVector;
    Location tempLocation;
    Base tempBase;

    //Open the activeOrders file.
    fin.open("activeOrders.txt");

    //Check if the file was opened (check if it exists).
    if(fin.is_open())
    {
        //Loop until the end of file and fetch data using the Order istream overloader.
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
                    if(data[i] == ',')
                    {
                        dataVector.push_back(tempData);
                        tempData = "";
                    }
                    else
                    {
                        tempData += data[i];
                    }
                }
                dataVector.push_back(tempData);
                tempData = "";

                Order tempOrder;
                Location tempLocation;

                tempOrder.setId(atoi(dataVector.at(0).c_str()));
                tempOrder.setPaidFor(atoi(dataVector.at(1).c_str()));

                int locationId = atoi(dataVector.at(2).c_str());
                for(unsigned int i = 0; i < availableLocations.size(); i++)
                {
                    tempLocation = availableLocations.at(i);
                    if(tempLocation.getId() == locationId)
                    {
                        tempOrder.setLocation(tempLocation);
                    }
                }

                tempOrder.setState((Order::State)atoi(dataVector.at(3).c_str()));
                tempOrder.setHomeDelivery((bool)atoi(dataVector.at(4).c_str()));

                int counter = 6;
                int pizzaCount = atoi(dataVector.at(5).c_str());
                for(int i = 0; i < pizzaCount; i++)
                {
                    Pizza tempPizza;
                    tempPizza.setName(dataVector.at(counter));
                    counter++;

                    int baseId = atoi(dataVector.at(counter).c_str());
                    counter++;
                    for(unsigned int j = 0; j < availableBases.size(); j++)
                    {
                        tempBase = availableBases.at(j);
                        if(tempBase.getId() == baseId)
                        {
                            tempPizza.setBase(tempBase);
                        }
                    }

                    int toppingCount = atoi(dataVector.at(counter).c_str());
                    counter++;
                    for(int j = 0; j < toppingCount; j++)
                    {
                        string tempToppingName = dataVector.at(counter);
                        counter++;
                        float tempToppingPrice = (float)atoi(dataVector.at(counter).c_str());
                        counter++;
                        Topping tempTopping;
                        tempTopping.setName(tempToppingName);
                        tempTopping.setPrice(tempToppingPrice);
                        tempPizza.addTopping(tempTopping);
                    }

                    tempOrder.addPizza(tempPizza);
                }

                int extraCount = atoi(dataVector.at(counter).c_str());
                counter++;
                for(int i = 0; i < extraCount; i++)
                {
                    Extra tempExtra;
                    tempExtra.setName(dataVector.at(counter));
                    counter++;
                    tempExtra.setType((Extra::Type)atoi(dataVector.at(counter).c_str()));
                    counter++;
                    tempExtra.setPrice((float)atoi(dataVector.at(counter).c_str()));
                    counter++;
                    tempOrder.addExtra(tempExtra);
                }

                //Clear the dataVector for the next order;
                dataVector.clear();

                //Put the order into the vector
                returnVector.push_back(tempOrder);
                cout << tempOrder.getPizzas().at(0).getName() << endl;
                //Clear the pizza and extras vector in Order
                tempOrder.clearPizzas();
                tempOrder.clearExtras();
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

    //Return the vector of orders.
    return returnVector;
}
