//============================================================================
// Name        : pointer_proj_small.cpp
// Author      : Rithwik Patel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
#include "../includes/constants.h"
#include "../includes/stringmanip.h"
#include "../includes/fileio.h"

using namespace KP;

int main(int argc, char *argv[]) {
//TODO add your content here
	if (argc == HELP_NUMBER_ARGUMENTS) {
		if (*argv[0] == HELP_CHAR) {
			cout << HELP_STRING1 << endl;
			cout << HELP_STRING1 << endl;
			return SUCCESS;
		}
	} else if (!(argc == EXPECTED_NUMBER_ARGUMENTS)) {
		cout << HELP_STRING1 << endl;
		return FAIL_WRONG_NUMBER_ARGS;
	}
	string in = argv[1];
	string out = argv[2];
	string tag = argv[3];
	string replace1 = argv[4];
	string str = "";
	readFile(in, str);
	int occ = findNumbOccurrences(str.c_str(), tag.c_str());
	char *tmpchar = new char[amountOfMemoryToAllocateForNewString(
			strlen(str.c_str()), occ, strlen(tag.c_str()),
			strlen(replace1.c_str()))];

	replace(str.c_str(), tmpchar, tag.c_str(), replace1.c_str());
	int writer_file = writeFile(out, tmpchar);
	if (!(writer_file == SUCCESS)) {
		return writer_file;
	}
	if (tmpchar) {
		delete[] tmpchar;
		tmpchar = 0;
	}
	return SUCCESS;

}
