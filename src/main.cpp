// ------------------------ Header Files ------------------------------------------
#include "graph.h"
#include "UI.h"
#include "shortestpath.h"

// Constants go here

#define MAX_VERTICES 10
#define MAX_NEIGHBOURS 5
#define MAX_PATHLENGTH 50
#define MAX_STRLEN 10
#define FILENAME "mapofthecity.txt"

// ------------------------- Final main Function -----------------------------------

int main()
{
	// This should preferably consist only of function calls and no actual working
	int srcVertex, destVertex;
	Graph map;
	int pathList[MAX_PATHLENGTH];
	int pathLen;
	int pathNeeded = 0;
	
	UI interface(FILENAME);
	pathNeeded = interface.takeInput(srcVertex, destVertex);
	
	if(pathNeeded)
	{
		map = interface.getMap();
		ShortestPath path(srcVertex, destVertex, map);
		pathLen = path.getPath(pathList, MAX_PATHLENGTH);
		interface.outputPath(pathList, pathLen);
	}
		
	return(0);
}