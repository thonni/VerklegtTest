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

    vector<Location> availableLocations = locationService.getLocations();
    vector<Base> availableBases = baseService.getBases();
    vector<Order> returnVector;
    vector<string> dataVector;
    string data;
    string tempData = "";
    Order tempOrder;
    Location tempLocation;
    Base tempBase;

    int extraCount;
    int counter;

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
                counter = 0;

                //Get the order id.
                tempOrder.setId(atoi(dataVector.at(counter).c_str()));
                counter++;
                //Get the paidFor bool.
                tempOrder.setPaidFor(atoi(dataVector.at(counter).c_str()));
                counter++;

                //Get the order location id.
                int locationId = atoi(dataVector.at(counter).c_str());
                counter++;
                //Loop through all available locations from file and match the id with the order id.
                for(unsigned int i = 0; i < availableLocations.size(); i++)
                {
                    tempLocation = availableLocations.at(i);
                    if(tempLocation.getId() == locationId)
                    {
                        //Set the location with the same id into the order.
                        tempOrder.setLocation(tempLocation);
                    }
                }

                //Get the state of the order.
                tempOrder.setState((Order::State)atoi(dataVector.at(counter).c_str()));
                counter++;
                //Get the HomeDelivery bool.
                tempOrder.setHomeDelivery((bool)atoi(dataVector.at(counter).c_str()));
                counter++;

                //Get the pizza count.
                int pizzaCount = atoi(dataVector.at(counter).c_str());
                counter++;
                //Loop through all the pizzas if there are any.
                if(pizzaCount > 0)
                {
                    for(int i = 0; i < pizzaCount; i++)
                    {
                        Pizza tempPizza;

                        //Get the pizza name.
                        tempPizza.setName(dataVector.at(counter));
                        counter++;
                        //Get the pizza size.
                        tempPizza.setSize((Pizza::Size)atoi(dataVector.at(counter).c_str()));
                        counter++;

                        //Get the base id for the current pizza.
                        int baseId = atoi(dataVector.at(counter).c_str());
                        counter++;
                        //Loop through all available bases from file and match the id with the order id.
                        for(unsigned int j = 0; j < availableBases.size(); j++)
                        {
                            tempBase = availableBases.at(j);
                            if(tempBase.getId() == baseId)
                            {
                                //Set the base with the same id into the order.
                                tempPizza.setBase(tempBase);
                            }
                        }

                        //Get the amount of toppings for the current pizza.
                        int toppingCount = atoi(dataVector.at(counter).c_str());
                        counter++;
                        //Loop through all the toppings if there are any.
                        if(toppingCount > 0)
                        {
                            for(int j = 0; j < toppingCount; j++)
                            {
                                //Get the topping name.
                                string tempToppingName = dataVector.at(counter);
                                counter++;
                                //Get the topping price.
                                float tempToppingPrice = (float)atoi(dataVector.at(counter).c_str());
                                counter++;
                                //Create a temporary instance of topping, add the name and price to it,
                                //and add the topping to the temporary pizza.
                                Topping tempTopping;
                                tempTopping.setName(tempToppingName);
                                tempTopping.setPrice(tempToppingPrice);
                                tempPizza.addTopping(tempTopping);
                            }
                        }

                        //Add the temporary pizza to the order.
                        tempOrder.addPizza(tempPizza);
                    }
                }

                //Get the amount of extras.
                extraCount = atoi(dataVector.at(counter).c_str());
                counter++;
                //Loop through all the extras if there are any.
                if(extraCount > 0)
                {
                    for(int i = 0; i < extraCount; i++)
                    {
                        //Create a temporary instance of extra
                        Extra tempExtra;
                        //Get and add the name to the temp extra.
                        tempExtra.setName(dataVector.at(counter));
                        counter++;
                        //Get and add the type to the temp extra.
                        tempExtra.setType((Extra::Type)atoi(dataVector.at(counter).c_str()));
                        counter++;
                        //Get and add the price to the temp extra.
                        tempExtra.setPrice((float)atoi(dataVector.at(counter).c_str()));
                        counter++;

                        //Add the temporary extra to the order.
                        tempOrder.addExtra(tempExtra);
                    }
                }

                //Clear the dataVector for the next order;
                dataVector.clear();

                //Put the order into the vector
                returnVector.push_back(tempOrder);

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
