#include "DataManager.h"
#include <fstream>

// Declare fout and fin in the global scope since they are used very often
ofstream fout;
ifstream fin;

DataManager::DataManager()
{
    //ctor
}

DataManager::~DataManager()
{
    //dtor
}

// Adds a dynamic array of toppings to the binary file toppingList.dat
void DataManager::addToppings(const Topping *toppings, const int arrsize) {
    // Opens the file that I want to write inn in binary mode with the append setting
    fout.open ("toppingList.dat", ios::binary|ios::app);
    // Writes the dynamic array into the file in one motion
    fout.write((char*)toppings, sizeof(Topping) * arrsize);
    // Closes the file
    fout.close();
}

// Adds a dynamic array of pizzas to the binary file pizzaMenu.dat
void DataManager::addPizzasToMenu(const Pizza *pizzas, const int arrsize) {
    // Opens the file that I want to write inn in binary mode with the append setting
    fout.open ("pizzaMenu.dat", ios::binary|ios::app);
    // Writes the dynamic array into the file in one motion
    fout.write((char*)pizzas, sizeof(Pizza) * arrsize);
    // Closes the file
    fout.close();
}

// Adds a dynamic array of orders to the binary file currentOrders.dat
void DataManager::addOrders(const Order *orders, const int arrsize) {
    // Opens the file that I want to write inn in binary mode with the append setting
    fout.open ("currentOrders.dat", ios::binary|ios::app);
    // Writes the dynamic array into the file in one motion
    fout.write((char*)orders, sizeof(Order) * arrsize);
    // Closes the file
    fout.close();
}


// Adds a dynamic array of extras to the binary file extraMenu.dat
void DataManager::addExtra(const Extra *extras, const int arrsize) {
    // Opens the file that I want to write inn in binary mode with the append setting
    fout.open ("extraMenu.dat", ios::binary|ios::app);
    // Writes the dynamic array into the file in one motion
    fout.write((char*)extras, sizeof(Order) * arrsize);
    // Closes the file
    fout.close();
}

// Reads out of the binary file toppingList.dat and writes out the contents to the console
void DataManager::readToppings() {
    // Opens the file that I want to read from in binary mode
    fin.open("toppingList.dat", ios::binary);
    // Sets records as the record for Topping
    int records = getToppingRecord();
    // Creates a dynamic array of toppings
    Topping *toppings = new Topping[records];
    // Reads all of the toppings from the file in one motion
    fin.read((char*)toppings, sizeof(Topping) * records);
    // Closes the file
    fin.close();
    // For loop to write out all of the toppings
    for(int i = 0; i < records; i++) {
        // Writes out one topping per loop
        cout << toppings[i];
        cout << endl;
    }
    // Deletes the dynamic array
    delete[] toppings;
}

// Reads out of the binary file pizzaMenu.dat and writes out the contents to the console
void DataManager::readPizzaMenu() {
    // Opens the file that I want to read from in binary mode
    fin.open("pizzaMenu.dat", ios::binary);
    // Sets records as the record for Pizza
    int records = getPizzaRecord();
    // Creates a dynamic array of pizzas
    Pizza *pizzas = new Pizza[records];
    // Reads all of the pizzas from the file in one motion
    fin.read((char*)pizzas, sizeof(Pizza) * records);
    // Closes the file
    fin.close();
    // For loop to write out all of the pizzas
    for(int i = 0; i < records; i++) {
        // Writes out one topping per loop
        cout << pizzas[i];
        cout << endl;
    }
    // Deletes the dynamic array
    delete[] pizzas;
}

// Reads out of the binary file currentOrders.dat and writes out the contents to the console
void DataManager::readCurrentOrders() {
    // Opens the file that I want to read from in binary mode
    fin.open("currentOrders.dat", ios::binary);
    // Sets records as the record for Order
    int records = getOrderRecord();
    // Creates a dynamic array of orders
    Order *orders = new Order[records];
    // Reads all of the orders from the file in one motion
    fin.read((char*)orders, sizeof(Order) * records);
    // Closes the file
    fin.close();
    // For loop to write out all of the orders
    for(int i = 0; i < records; i++) {
        // Writes out one topping per loop
        cout << orders[i];
        cout << endl;
    }
    // Deletes the dynamic array
    delete[] orders;
}

// Reads out of the binary file extraMenu.dat and writes out the contents to the console
void DataManager::readExtras() {
    // Opens the file that I want to read from in binary mode
    fin.open("extraMenu.dat", ios::binary);
    // Sets records as the record for Extra
    int records = getExtraRecord();
    // Creates a dynamic array of extras
    Extra *extras = new Extra[records];
    // Reads all of the extras from the file in one motion
    fin.read((char*)extras, sizeof(Extra) * records);
    // Closes the file
    fin.close();
    // For loop to write out all of the extras
    for(int i = 0; i < records; i++) {
        // Writes out one topping per loop
        cout << extras[i];
        cout << endl;
    }
    // Deletes the dynamic array
    delete[] extras;
}

// Removes delivered orders from currentOrders.dat and adds them to oldOrders.dat
void DataManager::moveOrders() {
    // Opens the file that I want to read from in binary mode
    fin.open("currentOrders.dat", ios::binary);
    // Sets record as the record for Order
    int records = getOrderRecord();
    // Initializes counter1 and counter2 and sets both to 0
    int counter1 = 0, counter2 = 0;
    // Creates a dynamic array of orders
    Order *orders = new Order[records];
    // Reads all of the orders from the file in one motion
    fin.read((char*)orders, sizeof(Order) * records);
    // Closes the file
    fin.close();
    // Creates a dynamic array of orders to move to oldOrders.dat
    Order *oldOrders = new Order[records];
    // Creates a dynamic array of orders to move to currentOrders.dat
    Order *newOrders = new Order[records];
    // A for loop to go over every current order
    for(int i = 0; i < records; i++) {
        // Checks if the order has been delivered
        if(orders[i].getState() == 'a') {
            // Adds the delivered order to a dynamic array which will be added to oldOrders.dat
            oldOrders[counter1] = orders[i];
            // Increments counter1 by one
            counter1++;
        }
        // If the order has not been delivered this will run
        else {
            // Adds the non-delivered order to a dynamic array which will overwrite currentOrders.dat
            newOrders[counter2] = orders[i];
            // Increments counter2 by one
            counter2++;
        }
    }
    // Opens currentOrders.dat in binary mode to be overwritten
    fout.open ("currentOrders.dat", ios::binary);
    // Overwrites currentOrders.dat with a dynamic array in one motion
    fout.write((char*)newOrders, sizeof(Order) * counter1);
    // Closes currentOrders.dat
    fout.close();
    // Opens currentOrders.dat in binary mode with the append setting
    fout.open ("oldOrders.dat", ios::binary|ios::app);
    // Adds the dynamic array to oldOrders.dat
    fout.write((char*)oldOrders, sizeof(Order) * counter2);
    // Closes oldOrders.dat
    fout.close();
    // Deletes all dynamic arrays
    delete[] orders;
    delete[] newOrders;
    delete[] oldOrders;
}


// Finds and returns the record for Topping
int DataManager::getToppingRecord() {
    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Topping);
    fin.seekg(0, fin.beg);
    return records;
}

// Finds and returns the record for Pizza
int DataManager::getPizzaRecord() {
    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Pizza);
    fin.seekg(0, fin.beg);
    return records;
}

// Finds and returns the record for Orders
int DataManager::getOrderRecord() {
    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Order);
    fin.seekg(0, fin.beg);
    return records;
}

int DataManager::getExtraRecord() {
    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Extra);
    fin.seekg(0, fin.beg);
    return records;
}






















