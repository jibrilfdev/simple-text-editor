#include <string> // strings
#include <iostream> // read from files
#include <fstream> // read from files
#include <ncurses.h>
#include "../include/main.h"

std::string CURRENT_FILE = "";
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

		// Display current file on screen
		display_current_file();

		//edit current file
		editing_current_file();
		getch();
		endwin();
	} else if (argc > 2) {
		std::cout << "Error: too many arguments." << '\n';
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

		display_current_file();

		//edits the current file
		editing_current_file();
		endwin();
	}
	endwin();

	return 0;
}

void read_file(std::string FILENAME) {
	// string to store each line
	std::string text;
	// file to read
	std::ifstream TextFile(FILENAME);

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

void editing_current_file() {
	// Track cursor location with x and y values
	int y=0,x=0,ch;
	move(0,0);
	// Update value on key press
	while ((ch = getch()) != ':') {
		switch (ch) {
			case KEY_UP:
				if (y == 0) break;
				y--;
				move(y,x);
				refresh();
				break;
			case KEY_DOWN:
				y++;
				move(y,x);
				refresh();
				break;
			case KEY_LEFT:
				if (x == 0) break;
				x--;
				move(y,x);
				refresh();
				break;
			case KEY_RIGHT:
				x++;
				move(y,x);
				refresh();
				break;
			case 10:
				characters[y][x] = '\n';
				x=0;
				y++;
				move(y,x);
				refresh();
				break;
			case KEY_BACKSPACE:
				printw(" ");
				refresh();
				characters[y][x] = ' ';
				if (x != 0) x--;
				move(y,x);
				refresh();
				break;
			case 'A':
				characters[y][x] = ch;
				x++;
				break;
			case 'B':
				characters[y][x] = ch;
				x++;
				break;
			case 'C':
				characters[y][x] = ch;
				x++;
				break;
			case 'D':
				characters[y][x] = ch;
				x++;
				break;
			case 'E':
				characters[y][x] = ch;
				x++;
				break;
			case 'F':
				characters[y][x] = ch;
				x++;
				break;
			case 'G':
				characters[y][x] = ch;
				x++;
				break;
			case 'H':
				characters[y][x] = ch;
				x++;
				break;
			case 'I':
				characters[y][x] = ch;
				x++;
				break;
			case 'J':
				characters[y][x] = ch;
				x++;
				break;
			case 'K':
				characters[y][x] = ch;
				x++;
				break;
			case 'L':
				characters[y][x] = ch;
				x++;
				break;
			case 'M':
				characters[y][x] = ch;
				x++;
				break;
			case 'N':
				characters[y][x] = ch;
				x++;
				break;
			case 'O':
				characters[y][x] = ch;
				x++;
				break;
			case 'P':
				characters[y][x] = ch;
				x++;
				break;
			case 'Q':
				characters[y][x] = ch;
				x++;
				break;
			case 'R':
				characters[y][x] = ch;
				x++;
				break;
			case 'S':
				characters[y][x] = ch;
				x++;
				break;
			case 'T':
				characters[y][x] = ch;
				x++;
				break;
			case 'U':
				characters[y][x] = ch;
				x++;
				break;
			case 'V':
				characters[y][x] = ch;
				x++;
				break;
			case 'W':
				characters[y][x] = ch;
				x++;
				break;
			case 'X':
				characters[y][x] = ch;
				x++;
				break;
			case 'Y':
				characters[y][x] = ch;
				x++;
				break;
			case 'Z':
				characters[y][x] = ch;
				x++;
				break;
			case 'a':
				characters[y][x] = ch;
				x++;
				break;
			case 'b':
				characters[y][x] = ch;
				x++;
				break;
			case 'c':
				characters[y][x] = ch;
				x++;
				break;
			case 'd':
				characters[y][x] = ch;
				x++;
				break;
			case 'e':
				characters[y][x] = ch;
				x++;
				break;
			case 'f':
				characters[y][x] = ch;
				x++;
				break;
			case 'g':
				characters[y][x] = ch;
				x++;
				break;
			case 'h':
				characters[y][x] = ch;
				x++;
				break;
			case 'i':
				characters[y][x] = ch;
				x++;
				break;
			case 'j':
				characters[y][x] = ch;
				x++;
				break;
			case 'k':
				characters[y][x] = ch;
				x++;
				break;
			case 'l':
				characters[y][x] = ch;
				x++;
				break;
			case 'm':
				characters[y][x] = ch;
				x++;
				break;
			case 'n':
				characters[y][x] = ch;
				x++;
				break;
			case 'o':
				characters[y][x] = ch;
				x++;
				break;
			case 'p':
				characters[y][x] = ch;
				x++;
				break;
			case 'q':
				characters[y][x] = ch;
				x++;
				break;
			case 'r':
				characters[y][x] = ch;
				x++;
				break;
			case 's':
				characters[y][x] = ch;
				x++;
				break;
			case 't':
				characters[y][x] = ch;
				x++;
				break;
			case 'u':
				characters[y][x] = ch;
				x++;
				break;
			case 'v':
				characters[y][x] = ch;
				x++;
				break;
			case 'w':
				characters[y][x] = ch;
				x++;
				break;
			case 'x':
				characters[y][x] = ch;
				x++;
				break;
			case 'y':
				characters[y][x] = ch;
				x++;
				break;
			case 'z':
				characters[y][x] = ch;
				x++;
				break;
			case '0':
				characters[y][x] = ch;
				x++;
				break;
			case '1':
				characters[y][x] = ch;
				x++;
				break;
			case '2':
				characters[y][x] = ch;
				x++;
				break;
			case '3':
				characters[y][x] = ch;
				x++;
				break;
			case '4':
				characters[y][x] = ch;
				x++;
				break;
			case '5':
				characters[y][x] = ch;
				x++;
				break;
			case '6':
				characters[y][x] = ch;
				x++;
				break;
			case '7':
				characters[y][x] = ch;
				x++;
				break;
			case '8':
				characters[y][x] = ch;
				x++;
				break;
			case '9':
				characters[y][x] = ch;
				x++;
				break;
			case '~':
				characters[y][x] = ch;
				x++;
				break;
			case '`':
				characters[y][x] = ch;
				x++;
				break;
			case '!':
				characters[y][x] = ch;
				x++;
				break;
			case '@':
				characters[y][x] = ch;
				x++;
				break;
			case '#':
				characters[y][x] = ch;
				x++;
				break;
			case '$':
				characters[y][x] = ch;
				x++;
				break;
			case '%':
				characters[y][x] = ch;
				x++;
				break;
			case '^':
				characters[y][x] = ch;
				x++;
				break;
			case '&':
				characters[y][x] = ch;
				x++;
				break;
			case '*':
				characters[y][x] = ch;
				x++;
				break;
			case '(':
				characters[y][x] = ch;
				x++;
				break;
			case ')':
				characters[y][x] = ch;
				x++;
				break;
			case '-':
				characters[y][x] = ch;
				x++;
				break;
			case '_':
				characters[y][x] = ch;
				x++;
				break;
			case '+':
				characters[y][x] = ch;
				x++;
				break;
			case '=':
				characters[y][x] = ch;
				x++;
				break;
			case '\\':
				characters[y][x] = ch;
				x++;
				break;
			case '[':
				characters[y][x] = ch;
				x++;
				break;
			case ']':
				characters[y][x] = ch;
				x++;
				break;
			case '{':
				characters[y][x] = ch;
				x++;
				break;
			case '}':
				characters[y][x] = ch;
				x++;
				break;
			case '|':
				characters[y][x] = ch;
				x++;
				break;
			case ';':
				characters[y][x] = ch;
				x++;
				break;
			case '\'':
				characters[y][x] = ch;
				x++;
				break;
			case '\"':
				characters[y][x] = ch;
				x++;
				break;
			case ',':
				characters[y][x] = ch;
				x++;
				break;
			case '.':
				characters[y][x] = ch;
				x++;
				break;
			case '/':
				characters[y][x] = ch;
				x++;
				break;
			case '<':
				characters[y][x] = ch;
				x++;
				break;
			case '>':
				characters[y][x] = ch;
				x++;
				break;
			case '?':
				characters[y][x] = ch;
				x++;
				break;
			case ' ':
				characters[y][x] = ' ';
				x++;
				break;
		}
	}
	// on exit, write and quit or quit
	exit_file_editing("WRITE", CURRENT_FILE);
}

void exit_file_editing(std::string TYPE, std::string FILENAME) {
	if (TYPE == "WRITE") {
		// String to store each line.
		std::string text;
		// File to read.
		std::ofstream TextFile(FILENAME);

		// Write the file line by line.
		for (int i=0; i<5000; i++) {
			for (int j=0; j<5000; j++) {
				if (characters[i][j] == '\n') {
					text+='\n';
					break;
				}
				text += characters[i][j];
			}
			TextFile << text;
			text = "";
		}

		// Close the file
		TextFile.close();
	}
}
