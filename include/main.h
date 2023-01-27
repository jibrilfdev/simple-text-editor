#include <string>

/*
* read_file
* Reads text currently stored in file and saves it in memory.
*
*/
void read_file(std::string FILENAME);

/*
* display_current_file
* outputs the file in memory onto the screen
*
*/

void display_current_file();

/*
* editing_current_file
* logic for editing the current file loaded in memory
*
*/

void editing_current_file();

/*
* exit_file_editing
* Exit editing. Expects a TYPE string ("WRITE" for saving the file on exit) and a file name.
*
* */

void exit_file_editing(std::string TYPE, std::string FILENAME);
