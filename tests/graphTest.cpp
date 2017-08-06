/*
Tests for Graph Class
*/

#include "graph.h"
#include <assert.h>

int testGraph()
{
	Graph g(8);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 3, 7);
	g.addEdge(1, 2, 8);
	g.addEdge(2, 3, 6);
	
	assert(g.getEdgeWeight(0, 1) == 5);
	assert(g.getEdgeWeight(3, 0) == 7);
	assert(g.getEdgeWeight(1, 4) == 0);
	assert(g.getEdgeWeight(9, 1) != 0); // This should raise an error
	
	return(0);
}

int main()
{
	testGraph();
	return(0);
}