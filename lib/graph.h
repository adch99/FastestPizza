/*
This file contains the classes for the main Graph
and its Vertices and Edges. 
*/

#ifndef FASTESTPIZZA_GRAPH_H
#define FASTESTPIZZA_GRAPH_H
// Constants go here

#define MAX_VERTICES 10
#define MAX_NEIGHBOURS 5

// Classes begin from here



class Vertex
{
	public:
		int index;
};



class Graph
{
	private:
		Vertex * vertices[MAX_VERTICES]; // main list of all vertices in the graph
		int edgeWeight[MAX_VERTICES][MAX_VERTICES];
		// Adjacency array for retrieving the weight of each edge. 
		// This implementation is easily extendable to directed graphs as well but that
		// will not be a part of our main objective.
		
	public:
		// Preferably keep an integer return value for all function that do not need
		// return anything. Indicate success with return value of 0 and anything else
		// for different errors. This should help in debugging.
		
		// Indexes can be in integers in half open range [0, numOfVertices)
		
		Graph(int numOfVertices);
		
		int addEdge(int index1, int index2, int weight); // Undirected Vertex
		int getEdgeWeight(int index1, int index2);
		int getNeighbourList(int index, int neighbourList[MAX_NEIGHBOURS]);
		
		// Miscellanous Functions for use inside other functions
		int assertIndexInRange(int index);
		
		// Functions that may be defined for later extension
		//int addDirectedEdge(int indexFrom, int indexTo, int weight);
};






#endif