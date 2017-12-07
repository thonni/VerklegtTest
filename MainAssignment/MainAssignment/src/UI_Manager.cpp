#include "UI_Manager.h"
#include "DataManager.h"

using namespace std;


void UI_Manager::startUI (){
    char choice;
    do {

        //Clear the screen.
        cout << string(50, '\n');

        cout << "What would you like to do?" << endl;
        cout << "Choose T to add toppings" << endl;
        cout << "Choose P to add pizzas on menu" << endl;
        cout << "Choose E to add extras" << endl;
        cout << "Choose L to add locations" << endl;
        cout << "Choose Q to quit" << endl;
        cout << ": ";
        cin >> choice;

        if(toupper(choice) == 'T')
        {
            this->addToppingToMenu();
        }
        else if (toupper(choice) == 'P')
        {
            this->addPizzaToMenu();
        }
        else if (toupper(choice) == 'E')
        {
            this->addExtraToMenu();
        }
        else if (toupper(choice) == 'L')
        {
            this->addLocation();
        }
        else if(toupper(choice) != 'Q')
        {
            cout << "Invalid input!" << endl;
        }

    } while(toupper(choice) != 'Q');
}


//This function creates new toppings using user input
//and uses DataManager to save them to toppingList.dat.
void UI_Manager::addToppingToMenu()
{
    string name;
    double price;
    char continueToAdd = '\0';

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Ask the user for a name and price for the new topping.
        cout << "Please enter the name of the topping: ";
        cin >> name;
        cout << "Please enter the price of the topping: ";
        cin >> price;

        //Create a temporary instance of Topping.
        Topping toppingToAdd = Topping(name, price);

        //Ask the Topping service to save the Topping.
        toppingService.addTopping(toppingToAdd);

        //Ask the user if he/she wants to add another topping.
        cout << "Add another topping? (Y/N): ";
        cin >> continueToAdd;

    } while(toupper(continueToAdd) == 'Y');
}


void UI_Manager::addPizzaToMenu()
{
    string name;
    Topping tempTopping;
    vector<Topping> availableToppings;
    char selection = '0';
    unsigned int selectionAsInt = 0;

    //Clear the screen.
    cout << string(50, '\n');

    //Get a vector for all saved toppings using DataManager.
    availableToppings = toppingService.getToppings();

    //Ask the user for a name for the new pizza.
    cout << "Pizza name: ";
    cin >> name;

    //Create an instance of pizza using the name
    Pizza newPizza(name, Pizza::Small);

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Loop trough all menu toppings and print them on screen.
        for(unsigned int i = 0; i < availableToppings.size(); i++)
        {
            tempTopping = availableToppings[i];
            cout << i << " - Name: " << tempTopping.getName() << " - Price: " << tempTopping.getPrice() << endl;
        }
        cout << "E - End" << endl << endl;

        //Ask the user to select a topping.
        cout << "Please select the id of the topping to add: ";
        cin >> selection;

        //Change the char selection to int.
        selectionAsInt = (int)(selection - '0');

        //Check if the selection is in the correct range.
        if((selectionAsInt >= 0 && selectionAsInt < availableToppings.size()))
        {
            //Add the topping to the pizza.
            newPizza.addTopping(availableToppings[selectionAsInt]);
        }
        //If it is not in range, it checks if you entered the letter e or E.
        else if(toupper(selection) != 'E')
        {
            /// \TODO: Make error message here.
        }

    } while(toupper(selection) != 'E');

    //Clear the screen.
    cout << string(50, '\n');

    //Make the pizza calculate the price of it self.
    newPizza.generatePrice();

    //Tell the user all the information about the pizza he/she created
    cout << "Name: " << newPizza.getName() << endl << endl;
    cout << "Toppings:" << endl;
    for(unsigned int i = 0; i < newPizza.getToppings().size(); i++)
    {
        cout << " *" << newPizza.getToppings().at(i).getName() << endl;
    }
    cout << endl << "Total price: " << newPizza.getPrice() << " ISK" << endl << endl;

    //Ask the user if everything is OK.
    cout << "Is this OK? (Y/N): ";
    cin >> selection;


    //Add the pizza to a vector and use DataManager to save the pizza to file.
    //newPizzas.push_back(newPizza);
    //data.addPizzasToMenu(newPizzas);
    pizzaService.addPizza(newPizza);
}


void UI_Manager::addExtraToMenu()
{
    string name;
    double price;
    char charType;
    Extra::Type type;
    bool validType;
    char continueToAdd = '\0';

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Ask the user for a name and price for the new extra.
        cout << "Please enter the name of the extra: ";
        cin >> name;
        cout << "Please enter the price of the extra: ";
        cin >> price;

        do
        {
            //Set valid type to false;
            validType = false;

            //Ask the user what type this extra is.
            cout << endl;
            cout << "Of what type is this extra?" << endl;
            cout << "Choose D for Drink" << endl;
            cout << "Choose S for Sauce" << endl;
            cout << "Choose I for SideDish" << endl;
            cout << ": ";
            cin >> charType;

            //Check if the input was valid, if it is it sets
            //the type into the variable type and sets validType
            //to true to get out of the do-while loop.
            if(toupper(charType) == 'D')
            {
                type = Extra::Drink;
                validType = true;
            }
            else if(toupper(charType) == 'S')
            {
                type = Extra::Sauce;
                validType = true;
            }
            else if(toupper(charType) == 'I')
            {
                type = Extra::SideDish;
                validType = true;
            }

        //Loop if the input was invalid.
        } while(!validType);

        //Create a temporary instance of Extra using the user input.
        Extra extraToAdd = Extra(name, type, price);

        //Ask the Extra service to save the Extra.
        extraService.addExtra(extraToAdd);

        //Ask the user if he/she wants to add another extra.
        cout << "Add another extra? (Y/N): ";
        cin >> continueToAdd;

    } while(toupper(continueToAdd) == 'Y');
}

//This function creates new locations using user input
//and uses DataManager to save them to locationList.dat.
void UI_Manager::addLocation()
{
    string address;
    string city;
    char continueToAdd = '\0';

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Ask the user for a address and city for the new location.
        cout << "Please enter the address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Please enter the city: ";
        cin.ignore();
        getline(cin, city);

        //Create a temporary instance of Location.
        Location locationToAdd = Location(address, city);

        //Ask the Location service to save the location.
        locationService.addLocation(locationToAdd);

        //Ask the user if he/she wants to add another location.
        cout << "Add another location? (Y/N): ";
        cin >> continueToAdd;

    } while(toupper(continueToAdd) == 'Y');
}

