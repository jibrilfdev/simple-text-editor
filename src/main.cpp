#include <string> // strings
#include <iostream> // read from files
#include <fstream> // read from files

using namespace std;

int main(int argc, char *argv[]) {
	// Open file from arguments or go to title screen

	return 0;
}

void read_file(string FILENAME) {
	// string to store each line
	string text;
	// file to read
	ifstream TextFile(FILENAME);

	// read the file line by line
	while (getline(TextFile, text)) {
		cout << text;
	}

	TextFile.close();
}
