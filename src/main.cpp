#include <string> // strings
#include <iostream> // read from files
#include <fstream> // read from files
#include "../include/main.h"

using namespace std;

string CURRENT_FILE;
int characters[5000][5000];

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
	int line_number=0;
	while (getline(TextFile, text)) {
		for (int i=0; i<text.size(); i++) {
			characters[line_number][i] = text[i];
		}
		line_number++;
	}

	// Close the file
	TextFile.close();
}
