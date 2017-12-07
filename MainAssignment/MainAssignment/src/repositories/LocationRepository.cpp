#include "LocationRepository.h"

void LocationRepository::addLocation(Location location)
{
    ofstream fout;

    fout.open("data/locationList.dat", ios::binary|ios::app);

    fout.write((char*)(&location), sizeof(Location));

    fout.close();
}


vector<Location> LocationRepository::getLocations()
{
    ifstream fin;

    fin.open("data/locationList.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Location);
    fin.seekg(0, fin.beg);

    Location *data = new Location[records];
    fin.read((char*)data, sizeof(Location) * records);

    vector<Location> returnVector;
    for(int i = 0; i < records; i++)
    {
        returnVector.push_back(data[i]);
    }

    return returnVector;
}
