#include <fstream>
#include <iostream>

/*
This file contains class and methods for the 
parser and file I/O that reads and stores 
graphs in files.
*/

#define MAX_PATHLENGTH 50

class GraphParser
{
	private:
		char filepath[MAX_PATHLENGTH];
		ifstream inputfile;
		
	public:
		GraphParser();
		GraphParser(char path[MAX_PATHLENGTH]);
		
		Graph open(char path[MAX_PATHLENGTH]);
};

pl