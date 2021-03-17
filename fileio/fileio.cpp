#include <iostream>
#include <fstream>
#include <string>

#include "../includes/constants.h"
#include "../includes/fileio.h"

using namespace std;

/**
 * write data in contents to filename
 *
 * \param filename: where data will go, overwrite if already there
 * \param contents: data to write to filename
 *        hint:  you can get a const char * by calling the method .c_str() on a std::string
 * \return
 *        INVALID_NULL_PTR_DETECTED if contents ==NULL
 *        SUCCESS otherwise
 */
int writeFile(std::string &filename, char *contents) {
	ofstream myfile;

	myfile.open(filename.c_str());
	if (!myfile.is_open()) {
		return FAIL_CANNOT_OPEN_FILE;
	} else if (contents == NULL) {
		return INVALID_NULL_PTR_DETECTED;
	} else {
		myfile << contents;
		myfile.close();
		return SUCCESS;
	}
}

/**
 * Reads info from filename into contents
 *
 * \param filename where data is
 * \param contents data to write to file
 * \return
 *        CANNOT_OPEN_FILE  if filename cannot be opened
 *        SUCCESS
 */
int readFile(std::string &filename, std::string &contents) {
	ifstream myfile;
	myfile.open(filename.c_str(), ios::in);
	if (!myfile.is_open()) {
		return FAIL_CANNOT_OPEN_FILE;
	}
	getline(myfile, contents);
	myfile.close();

	return SUCCESS;
}
