#ifndef GRAPH_H
#define GRAPH_H

// Constants

#define MAX_VERTICES 10
#define MAX_NEIGHBOURS 5
#define MAX_PATHLENGTH 50

//##################### Graph Class #######################

// This class contains the framework needed to work with the nodes/vertices
// and edges of the graph.


class Graph
{
	private:
		int edgeWeight[MAX_VERTICES][MAX_VERTICES];
		// Adjacency array for retrieving the weight of each edge. 
		// This implementation is easily extendable to directed graphs as well but that
		// will not be a part of our main objective.
		int numOfVertices;
		
	public:
		// Preferably keep an integer return value for all function that do not need
		// return anything. Indicate success with return value of 0 and anything else
		// for different errors. This should help in debugging.
		
		// Indexes can be in integers in half open range [0, numOfVertices)
		
		Graph(){}
		Graph(int numOfVerticesTemp);
		
		int addEdge(int index1, int index2, int weight); // Undirected Vertex
		int getEdgeWeight(int index1, int index2);
		int getNeighbourList(int index, int neighbourList[MAX_NEIGHBOURS]);
		int getNumOfVertices();
		
		// Miscellanous Functions for use inside other functions
		int assertIndexInRange(int index);
		
		// Functions that may be defined for later extension
		//int addDirectedEdge(int indexFrom, int indexTo, int weight);
};

// ONE THING I SHOULD PROBABLY MAKE CLEAR OVER HERE
// The indexes for the vertices should not be arbitrary. They should be the integers
// from 0 to <number_of_vertices>. This will help tremendously in coding the logic
// in other parts. If you want to be able to assign real names to them then maintain
// a separate list of strings containing these names where name[i] = "Name of the 
// ith vertex". 

#endif
