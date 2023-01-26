#include <string> // strings
#include <iostream> // read from files
#include <fstream> // read from files
#include "../include/main.h"

using namespace std;

string CURRENT_FILE;

int main(int argc, char *argv[]) {
	// Open file from arguments or go to title screen
	if (argc == 2) {
		CURRENT_FILE = argv[1];
		read_file(CURRENT_FILE);
	} else if (argc > 2) {
		cout << "Error: too many arguments." << endl;
		return 1;
	} else {
		cout << "MAIN SCREEN HERE" << endl;
		cout << "File name:";
		cin >> CURRENT_FILE;
		read_file(CURRENT_FILE);
	}

	return 0;
}

void read_file(string FILENAME) {
	// string to store each line
	string text;
	// file to read
	ifstream TextFile(FILENAME);

	// read the file line by line
	while (getline(TextFile, text)) {
		cout << text << endl;
	}

	TextFile.close();
}
