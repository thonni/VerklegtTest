#include "UI_Manager.h"


void UI_Manager::startUI (){
    char choice;
    do {

        //Clear the screen.
        cout << string(50, '\n');

        cout << "What would you like to do?" << endl;
        cout << "Choose T to add Toppings" << endl;
        cout << "Choose B to add a Base" << endl;
        cout << "Choose P to add Pizzas on menu" << endl;
        cout << "Choose E to add Extras" << endl;
        cout << "Choose L to add Locations" << endl;
        cout << "Choose Q to Quit" << endl;
        cout << ": ";
        cin >> choice;

        if(toupper(choice) == 'T')
        {
            this->addToppingToMenu();
        }
        if(toupper(choice) == 'B')
        {
            this->addBaseToMenu();
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
    Topping tempTopping;
    vector<Topping> availableToppings;
    Topping toppingToAdd;
    bool validInput;

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Get a vector for all saved toppings using toppingService.
        availableToppings = toppingService.getToppings();

        //Loop trough all menu toppings and print them on screen.
        cout << "****AVAILABLE TOPPINGS**** " << endl;
        for(unsigned int i = 0; i < availableToppings.size(); i++)
        {
            tempTopping = availableToppings[i];
            cout << i << " - Name: " << tempTopping.getName() << " - Price: " << tempTopping.getPrice() << endl;
        }
        cout << endl;

        name = "";
        do
        {
            validInput = false;

            //Ask the user for a name and price for the new topping.
            cout << "Please enter the name of the topping to add: ";
            cin.ignore();
            getline(cin, name);

            if(name.length() > 0)
            {
                validInput = true;
            }

        } while(!validInput);

        do
        {
            validInput = true;

            cout << "Please enter the price of the topping: ";
            cin >> price;

            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                validInput = false;
            }

        } while(!validInput);


        //Create a temporary instance of Topping.
        toppingToAdd = Topping(name, price);

        //Ask the Topping service to save the Topping.
        toppingService.addTopping(toppingToAdd);

        //Ask the user if he/she wants to add another topping.
        cout << "Add another topping? (Y/N): ";
        cin >> continueToAdd;

    } while(toupper(continueToAdd) == 'Y');
}

//This function creates new bases using user input
//and uses DataManager to save them to
void UI_Manager::addBaseToMenu()
{
    string name;
    double price;
    char continueToAdd = '\0';
    Base tempBase;
    vector<Base> availableBases;

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Ask baseService for a vector of all bases that are on the menu.
        availableBases = baseService.getBases();
        //Print out all available pizza bases.
        cout << "****AVAILABLE PIZZA BASES****" << endl;
        for(unsigned int i = 0; i < availableBases.size(); i++)
        {
            tempBase = availableBases.at(i);
            cout << i << " - Name: " << tempBase.getName() << " - price: " << tempBase.getPrice() << " Kr" << endl;
        }
        cout << endl;

        //Ask the user for a name and price for the new topping.
        cout << "Please enter the name of the base to add: ";
        cin.ignore();
        getline(cin, name);
        cout << "Please enter the price of the base: ";
        cin >> price;

        //Create a temporary instance of Base.
        Base baseToAdd = Base(name, price);
        baseToAdd.generateId();

        //Ask the Base service to save the Base.
        baseService.addBase(baseToAdd);

        //Ask the user if he/she wants to add another Base.
        cout << "Add another base? (Y/N): ";
        cin >> continueToAdd;

    } while(toupper(continueToAdd) == 'Y');
}


void UI_Manager::addPizzaToMenu()
{
    string name;
    Topping tempTopping;
    Topping tempTopp;
    vector<Topping> availableToppings;
    vector<Base> availableBases;
    string selection = "0";
    unsigned int selectionAsInt = 0;
    Pizza tempPizza;
    vector<Pizza> availablePizzas;
    vector<Topping> tempToppings;

    //Clear the screen.
    cout << string(50, '\n');

    //Ask pizzaService for a vector of all pizzas that are on the menu.
    availablePizzas = pizzaService.getPizzas();

    //Loop trough all the pizzas on the menu and print their id, name, price
    //and also loop trough their toppings and print them out.
    cout << "****AVAILABLE PIZZAS ON MENU****" << endl;
    for(unsigned int i = 0; i < availablePizzas.size(); i++)
    {
        tempPizza = availablePizzas.at(i);
        cout <<"Name: " << tempPizza.getName() << " - Price of small: " << tempPizza.getPrice() << " KR" << endl;
        cout << "Toppings:" << endl;
        for(unsigned int j = 0; j < tempPizza.getToppings().size(); j++)
        {
            tempTopping = tempPizza.getToppings().at(j);
            cout << " *" << tempTopping.getName() << endl;
        }
        cout << endl;
    }

    //Get a vector for all saved toppings using toppingService.
    availableToppings = toppingService.getToppings();
    //Get a vector for all saved bases using baseService.
    availableBases = baseService.getBases();

    //Ask the user for a name for the new pizza.
    cout << "Name of pizza to add on menu: ";
    cin.ignore();
    getline(cin, name);

    //Create an instance of pizza using the name
    Pizza newPizza(name, Pizza::Small);

    //Set the base of the pizza to be the first base on file.
    newPizza.setBase(availableBases.at(0));

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

        //Loop trough toppings on pizza and print them on screen.
        cout << "****TOPPINGS ON "<< newPizza.getName() << "****" << endl;
        for(unsigned int i = 0; i < tempToppings.size(); i++)
        {
            cout << i << " - Name: " << tempToppings[i].getName() << endl;
        }
        cout << endl;

        //Ask the user to select a topping.
        cout << "Please select the id of the topping to add: ";
        cin >> selection;

        //Change the char selection to int.
        selectionAsInt = 0;
        for(unsigned int i = 0; i < selection.length(); i++)
        {
            selectionAsInt *= 10;
            selectionAsInt += (int)selection[i] - '0';
        }

        //Check if the selection is in the correct range.
        if((selectionAsInt >= 0 && selectionAsInt < availableToppings.size()))
        {
            //Add the topping to the pizza.
            tempToppings.push_back(availableToppings[selectionAsInt]);
        }
        //If it is not in range, it checks if you entered the letter e or E.
        else if(toupper(selection[0]) != 'E')
        {
            /// \TODO: Make error message here.
        }

    } while(toupper(selection[0]) != 'E');

    //Clear the screen.
    cout << string(50, '\n');

    //Make the pizza calculate the price of it self.
    sort(tempToppings.begin(), tempToppings.end());
    for(unsigned int i = 0; i < tempToppings.size(); i++)
    {
        newPizza.addTopping(tempToppings[i]);
    }
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


    //Use pizzaService to save the new pizza to file.
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
    Extra tempExtra;
    vector<Extra> availableExtras;
    //Ask extraService for a vector of all extras that are on the menu.
    availableExtras = extraService.getExtras();

    do
    {
        //Clear the screen.
        cout << string(50, '\n');
        //Ask extraService for a vector of all extras that are on the menu.
        availableExtras = extraService.getExtras();

        //Loop trough all the extras on the menu and print their id, name and price.
        cout << "****CURRENT EXTRA MENU****" << endl;
        for(unsigned int i = 0; i < availableExtras.size(); i++)
        {
            tempExtra = availableExtras.at(i);
            cout << i << " - Name: " << tempExtra.getName() << " - Price: " << tempExtra.getPrice() << " KR" << endl;
        }
        cout << endl;

        //Ask the user for a name and price for the new extra.
        cout << "Please enter the name of the extra to add to menu: ";
        cin.ignore();
        getline(cin, name);
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
    vector<Location> locations;

    do
    {
        //Clear the screen.
        cout << string(50, '\n');

        //Print out available locations.
        locations = locationService.getLocations();
        int locSize = locations.size();
        cout << "***AVAILABLE LOCATIONS***" << endl;
        for(unsigned int i = 0; i < locations.size(); i++)
        {
            cout << (i + 1) << ": " << locations.at(i).getAddress() << ", " << locations.at(i).getCity() << endl;
        }
        cout << endl;

        //Ask the user for a address and city for the new location.
        cout << "Please enter the street name and number: ";
        cin.ignore();
        getline(cin, address);
        cout << "Please enter the city: ";
        getline(cin, city);

        //Create a temporary instance of Location.
        Location locationToAdd = Location(address, city);
        locationToAdd.generateId();

        //Ask the Location service to save the location.
        locationService.addLocation(locationToAdd);

        //Ask the user if he/she wants to add another location.
        cout << "Add another location? (Y/N): ";
        cin >> continueToAdd;

    } while(toupper(continueToAdd) == 'Y');
}

