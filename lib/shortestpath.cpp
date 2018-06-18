//------------------------------------------- Header Section ------------------------------------------
#include <limits>
#include "shortestpath.h"

//######################### Shortest Path Class #####################################

ShortestPath :: ShortestPath(int srcVertex, int destVertex, Graph pmap) 
{	
	// Set map to pmap
	map = pmap;
	numOfVertices = map.getNumOfVertices();
	
	destnVertex = destVertex; 
	
	// set all vertices' distance to infinity and state to unvisited			
	for(int i = 0; i < numOfVertices; i++)
	{
		distances[i] = std::numeric_limits<int>::max(); // Sets it to max possible
		visited[i] = 0; // see http://bit.ly/inttoinf
	}
	
	// set src vertex to 0 and visited
	distances[srcVertex] = 0;
	parentVertex[srcVertex] = -1;
	visitVertex(srcVertex);
	
	int ctr = 0;
	
	// cut -----set up loop to update distances till all vertices are covered
	int nextVertex = getNextVertex();
	while(ctr++ < numOfVertices - 1)
	{
		visitVertex(nextVertex);
		nextVertex = getNextVertex();
	}
}

int ShortestPath :: visitVertex(int vertex)
{
	/*
	Visits the given vertex and updates its neighbours.
	*/
	
	//std::cout << "Visiting Vertex " << vertex << std::endl;
	visited[vertex] = 1;
	updateDistances(vertex);
	
	/*std::cout << "Neighbour List: ";
	int nList[MAX_NEIGHBOURS];\
	map.getNeighbourList(vertex, nList);
	for(int j = 0; j < MAX_NEIGHBOURS; j++)
		std::cout << nList[j] << " ";
	std::cout << std::endl;
	
	std::cout << "Distance List: ";
	for(int i = 0; i < numOfVertices;i++)
		std::cout << distances[i] << " ";
	
	std:: cout << std::endl << std::endl;
	*/
	
	return(0);
}

int ShortestPath:: updateDistances(int curVertex)
{
	/*
	Updates the distances to all the neighbour nodes if a shorter
	path exists through the current node.
	*/
	
	int neighbourList[MAX_NEIGHBOURS];
	map.getNeighbourList(curVertex, neighbourList);
	
	int i = 0;
	while(neighbourList[i] != -1)
	{
		int nVertex = neighbourList[i];
		
		int distanceViaCurVertex = distances[curVertex] + map.getEdgeWeight(curVertex, nVertex);
		
		if(distanceViaCurVertex < distances[nVertex] && !visited[nVertex])
		{
			distances[nVertex] = distanceViaCurVertex;		
			parentVertex[nVertex] = curVertex;
		}
		
		i++;
	}
	
	return(0);
}

int ShortestPath :: getNextVertex()
{
	/*
	Returns the unvisited node that is least distant, -1 if none exist
	*/
	
	int minDistantVertex = -1;
	int minDistance = std::numeric_limits<int>::max();
	
	for(int i = 0; i < numOfVertices; i++)
	{
		if(distances[i] < minDistance && !visited[i])
		{	
			minDistantVertex = i;
			minDistance = distances[i];
		}
	}
	
	return(minDistantVertex);
}

int ShortestPath :: getPath(int pathList[], int maxlen)
{
	/*
	Returns the required shortest path in sequence of vertices to
	be traversed in the array given. If length of path is greater than maxlen then -1
	is returned. Otherwise length of path is returned.
	*/
	
	/*std::cout << "Parent List: ";
	for(int k=0;k<numOfVertices;k++)
		std::cout << parentVertex[k] << " ";
	std::cout << std::endl;*/
	
	int ctr = 0;
	
	int curVertex = destnVertex;
	
	//std::cout << "curVertex is" << curVertex << std::endl;
	
	int parent = parentVertex[curVertex];
	
	while(parent != -1 && ctr < maxlen)
	{
		pathList[ctr++] = curVertex;
		curVertex = parent;
		parent = parentVertex[curVertex];
	}
	
	if(ctr >= maxlen)
		return(-1);

	pathList[ctr++] = curVertex;
	
	/*for(int j = 0; j <  ctr; j++)
		std::cout << PathList[j] << " "; 

	std::cout << std::endl;*/
	
	for(int i = 0; i < ctr/2 ; i++)
	{	
		int tmp = pathList[i];
		pathList[i] = pathList[ctr - 1 - i];
		pathList[ctr - i -1] = tmp;
	}
	
	return(ctr);

}