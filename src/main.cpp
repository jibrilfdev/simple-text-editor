#include <string> // strings
#include <iostream> // read from files
#include <fstream> // read from files
#include <ncurses.h>
#include "../include/main.h"

using namespace std;

string CURRENT_FILE = "";
char characters[5000][5000];

int main(int argc, char *argv[]) {
	// Open file from arguments or go to title screen
	if (argc == 2) {
		int ch;
		// Initialize ncurses screen
		initscr();
		raw();
		keypad(stdscr, TRUE);

		// Get max screen width and height
		int X_MAX, Y_MAX;
		getmaxyx(stdscr, Y_MAX, X_MAX);

		// Set current file based on argument and read file into memory
		CURRENT_FILE = argv[1];
		read_file(CURRENT_FILE);

		move(0,0);
		refresh();
		getch();

		// Display current file on screen
		display_current_file();
		getch();
		endwin();
	} else if (argc > 2) {
		cout << "Error: too many arguments." << endl;
		return 1;
	} else {
		int ch;

		// Initialize ncurses window.
		initscr();
		raw();
		keypad(stdscr, TRUE);

		// Get max width and height values
		int X_MAX, Y_MAX;
		getmaxyx(stdscr, Y_MAX, X_MAX);

		// Display main screen
		move(Y_MAX/2-1, X_MAX/2-8);
		printw("Simple Text Editor");
		getch();
		refresh();
		move(Y_MAX/2, X_MAX/2-8);
		printw("File Name: ");
		while ((ch = getch()) != 10) {
			if (ch == KEY_BACKSPACE) {
				if (CURRENT_FILE.size()!=0) CURRENT_FILE.pop_back();
				else {
					int curr_y, curr_x;
					getyx(stdscr, curr_y, curr_x);
					move(curr_y, curr_x+1);
					refresh();
				}
			} else {
				CURRENT_FILE+=ch;
			}
		}

		read_file(CURRENT_FILE);
		getch();
		display_current_file();
		getch();
		endwin();
	}
	endwin();

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
		// add new line character to the end of each line
		characters[line_number][text.size()] = '\n';
		line_number++;
	}

	// Close the file
	TextFile.close();
}

void display_current_file() {
	clear();
	refresh();
	move(0,0);
	refresh();
	getch();

	for (int i=0; i<5000; i++) {
		for (int j=0; j<5000; j++) {
			if (characters[i][j] == '\n') {
				printw("%c", characters[i][j]);
				break;
			}
			printw("%c", characters[i][j]);
		}
		refresh();
	}
}
