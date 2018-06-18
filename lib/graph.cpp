//------------------------------------------- Header Section ------------------------------------------
#include <cassert>
#include "graph.h"

//########################## Graph Class ##########################
Graph :: Graph(int numOfVerticesTemp)
{
	/*
	Constructor for Graph Class
	*/
	
	numOfVertices = numOfVerticesTemp;
	// Set all the edges to 0 initially
	int i, j;
	for(i = 0; i < numOfVertices; i++)
	{
		for(j = 0; j < numOfVertices; j++)
			edgeWeight[i][j] = 0;
	}
}

int Graph :: addEdge(int index1, int index2, int weight)
{
	/*
	Adds an undirected edge of given weight between the 2 nodes whose indexes are given.
	*/
	
	assertIndexInRange(index1);
	assertIndexInRange(index2);
	assert(weight > 0);
	
	edgeWeight[index1][index2] = edgeWeight[index2][index1] = weight;

	return(0);
}

int Graph :: getEdgeWeight(int index1, int index2)
{
	/*
	Returns the weight of edge between vertices index1 and index2
	*/
	
	int weight = edgeWeight[index1][index2];
	return(weight);
}

int Graph :: getNeighbourList(int index, int neighbourList[MAX_NEIGHBOURS])
{
	/*
	Returns by reference the index list of neigbhbours of the vertex of given
	index.
	*/
	
	int neighbourIndex;
	int i = 0;
	
	for(neighbourIndex = 0; neighbourIndex < numOfVertices; neighbourIndex++)
	{
		if(getEdgeWeight(index, neighbourIndex) > 0)
			neighbourList[i++] = neighbourIndex;
	}
	
	// All other spaces are set to -1 to avoid confusion with garbage values
	for(; i < MAX_NEIGHBOURS; i++)
		neighbourList[i] = -1;
	
	return(0);
}

int Graph :: getNumOfVertices()
{
	return(numOfVertices);
}


int Graph :: assertIndexInRange(int index)
{
	/*
	Ensures that given index is in appropriate range i.e it is an
	integer in half open interval [0, numOfVertices). Raises error
	if it is not in range.
	*/
	
	int indexInRange = ( index >= 0 && index < numOfVertices );
	assert(indexInRange);	
	
	return(0);
}
