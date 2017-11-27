#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string str;
	ifstream fin;
	bool read = true;
	int counter = 1;
	char cont;

	fin.open("textFile.txt");
	if(fin.is_open()) {
        while(!fin.eof() && read) {
            getline(fin, str);
            cout << str << endl;
            if (counter == 10) {
                cont = ' ';
                while (!(toupper(cont) == 'N' || toupper(cont) == 'Y')) {
                    cout << "Do you wish to continue (y/n)?";
                    cin >> cont;
                }
                counter = 0;
                if (toupper(cont) == 'N') {
                    read = false;
                }
            }
            counter++;
        }
        fin.close();
	} else {
        cout << "Unable to read from file." << endl;
	}

    return 0;
}
