// ------------------------- Testing Functions -------------------------------------

int testGraph()
{
	Graph map(4);
	map.addEdge(0,1,10);
	map.addEdge(1,2,3);
	map.addEdge(0,2,4);
	map.addEdge(2,3,9);
	map.addEdge(1,3,2);
	
	ShortestPath path(0,3,map);
	
	int p[10];
	int l = path.getPath(p, 10);
	
	for(int i = 0; i < l; i++)
		std :: cout << p[i] << " ";
	
	return(0);
}