#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

// Constants go here

#define MAX_VERTICES 10
#define MAX_NEIGHBOURS 5
#define MAX_PATHLENGTH 50
#include "graph.h"

//####################### Shortest Path Class #############################

class ShortestPath
{
	/*
	An implementation of Djikstra's Algorithm to find the shortest path
	between any two vertices.
	*/
	private:
		int distances[MAX_VERTICES];
		int visited[MAX_VERTICES];
		int parentVertex[MAX_VERTICES];
		
		Graph map;
		
		int numOfVertices;
		int destnVertex;
	
	public:
		ShortestPath(int srcVertex, int destVertex, Graph pmap);		
		int visitVertex(int vertex);
		int updateDistances(int curVertex);
		int getNextVertex();
		int getPath(int PathList[], int maxlen);
};

#endif