#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string str;
	ofstream fout;

	fout.open("textFile.txt", ios::app);
	if(fout.is_open()) {


        fout.close();
	} else {
        cout << "File could not be opened." << endl;
	}

    return 0;
}
