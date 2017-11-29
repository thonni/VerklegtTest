#include "DataManager.h"
#include <fstream>

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

void DataManager::addToppings(const Topping *toppings, const int arrsize) {
    fout.open ("toppingList.dat", ios::binary|ios::app);
    fout.write((char*)toppings, sizeof(Topping) * arrsize);

    fout.close();
}

void DataManager::addPizzasToMenu(const Pizza *pizzas, const int arrsize) {
    fout.open ("pizzaMenu.dat", ios::binary|ios::app);
    fout.write((char*)pizzas, sizeof(Pizza) * arrsize);

    fout.close();
}

void DataManager::addOrders(const Order *orders, const int arrsize) {
    fout.open ("currentOrders.dat", ios::binary|ios::app);
    fout.write((char*)orders, sizeof(Order) * arrsize);

    fout.close();
}

void DataManager::readToppings() {
    fin.open("toppingList.dat", ios::binary);

    int records = getToppingRecord();

    Topping *toppings = new Topping[records];
    fin.read((char*)toppings, sizeof(Topping) * records);

    fin.close();

    for(int i = 0; i < records; i++) {
        cout << toppings[i];
        cout << endl;
    }
    delete[] toppings;
}

void DataManager::readPizzaMenu() {
    fin.open("pizzaMenu.dat", ios::binary);

    int records = getPizzaRecord();

    Pizza *pizzas = new Pizza[records];
    fin.read((char*)pizzas, sizeof(Pizza) * records);

    fin.close();

    for(int i = 0; i < records; i++) {
        cout << pizzas[i];
        cout << endl;
    }
    delete[] pizzas;
}

void DataManager::readCurrentOrders() {
    fin.open("currentOrders.dat", ios::binary);

    int records = getOrderRecord();

    Order *orders = new Order[records];
    fin.read((char*)orders, sizeof(Order) * records);

    fin.close();

    for(int i = 0; i < records; i++) {
        cout << orders[i];
        cout << endl;
    }
    delete[] orders;
}

void DataManager::moveOrders() {
    fin.open("currentOrders.dat", ios::binary);

    int records = getOrderRecord();
    int counter1 = 0, counter2 = 0;

    Order *orders = new Order[records];
    fin.read((char*)orders, sizeof(Order) * records);

    fin.close();

    Order *oldOrders = new Order[records];
    Order *newOrders = new Order[records];

    for(int i = 0; i < records; i++) {
        if(orders[i].getState() == 'a') {
            oldOrders[counter1] = orders[i];
            counter1++;
        }
        else {
            newOrders[counter2] = orders[i];
            counter2++;
        }
    }

    fout.open ("currentOrders.dat", ios::binary);
    fout.write((char*)newOrders, sizeof(Order) * counter1);

    fout.close();

    fout.open ("oldOrders.dat", ios::binary|ios::app);
    fout.write((char*)oldOrders, sizeof(Order) * counter2);

    fout.close();
    delete[] orders;
    delete[] newOrders;
    delete[] oldOrders;
}


int DataManager::getToppingRecord() {
    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Topping);
    fin.seekg(0, fin.beg);
    return records;
}

int DataManager::getPizzaRecord() {
    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Pizza);
    fin.seekg(0, fin.beg);
    return records;
}

int DataManager::getOrderRecord() {
    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Order);
    fin.seekg(0, fin.beg);
    return records;
}
























