#ifndef UI_H
#define UI_H

//------------------------------------------- Header Section ------------------------------------------
#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include "graph.h"
#include "shortestpath.h"


// Constants go here

#define MAX_VERTICES 10
#define MAX_NEIGHBOURS 5
#define MAX_PATHLENGTH 50
#define MAX_STRLEN 10


// ####################### UI Class ###################################
/*Class for the parser and file I/O that reads and stores 
graphs in files. Also interacts with the user input.
*/

typedef char string[MAX_STRLEN];

class UI{
	private:
		string table[MAX_VERTICES];
		char filePath[MAX_PATHLENGTH];
		
		int getVertexNames();
		int refer(string t);
		int makeGraph();
		int inputScreen(int &srcVertex, int &destVertex);
		int questPath(int &srcVertex, int &destVertex);
		int addDistance();
		int printVisual();
		int displayCity();
		
	public:
		Graph map;
		
		UI(const char path[MAX_PATHLENGTH]);
		int takeInput(int &srcVertex, int &destVertex);
		int outputPath(int PathList[], int pathLen);		
		Graph getMap();
		
		//Ideal Example output: Shortest Path:
		//						Home to School to Shop
		//						Total Path Length: 9 units
};

// PLEASE KEEP THIS IN MIND
// The indexes for the vertices should not be arbitrary. They should be the integers
// from 0 to <number_of_vertices>. This will help tremendously in coding the logic
// in other parts. If you want to be able to assign real names to them then maintain
// a separate list of strings containing these names where name[i] = "Name of the 
// ith vertex". 

#endif