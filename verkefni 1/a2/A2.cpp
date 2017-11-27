#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string str;
	ofstream fout;
	bool running = true;

	fout.open("textFile.txt", ios::app);
	if(fout.is_open()) {
        while(running) {
            getline(cin, str);
            if(str[0] == '\\') {
                running = false;
            } else {
                fout << str << endl;
            }
        }
        fout.close();
	} else {
        cout << "File could not be opened." << endl;
	}

    return 0;
}
