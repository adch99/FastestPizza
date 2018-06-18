#include "UI.h"


//###################### UI Class ##################################################
UI :: UI(const char path[MAX_PATHLENGTH])
{	
	std::strcpy(filePath, path);
	
	for(int i = 0; i < MAX_VERTICES; i++)
		std::strcpy(table[i],"\0");
	
	getVertexNames();
	makeGraph();
}

int UI :: refer(string t){									
	//returns index value of given node
	
	for (int i = 0 ; std::strcmp(table[i],"\0") != 0; i++){
		if (std::strcmp(t,table[i])==0){
			return(i);
		}
	}
	//std::cout << "refer: No such vertex found!:" << t << std::endl;
	return(-1);
}

int UI :: getVertexNames(){
	/*
	Creates a table of all the vertex names in the file and assigns
	distinct integer indices to each of them.
	*/
	
	string temp;
	int i=0, flag=0;
	std::ifstream file;
	file.open(filePath);

	while(!file.eof()){               												//while the file is open,
		file>>temp;																//input single word into temp
		if (!std::isdigit(temp[0])){    //ctype header									//if the word is not a number
			for (i=0; std::strcmp(table[i],"\0") != 0; i++){										
				if (std::strcmp(temp,table[i]) == 0){    //string header 				//check if name already in table
					flag = 1;													//if it is in table, set flag to 1
				}
			}
			if (flag == 0){														//if not in table,
				std::strcpy(table[i],temp);					//then add to table
				//std::cout << "Entering " << temp << " into the table with index" << i << std::endl;
			}
		}
		flag = 0;																	//set flag to 0 for next word
	}
	return(0);
}

int UI :: outputPath(int pathList[], int len){
	/*
	Outputs the path computed by the algorithm
	*/
	int x;
	int weight = 0;
	
	for(x = 0; x < len - 1; x++){
		weight += map.getEdgeWeight(pathList[x],pathList[x+1]);
	}
	std :: cout<<"Shortest Path:"<<std::endl;
	
	for(x = 0; x < len - 1; x++){
		std::cout<<table[pathList[x]]<<" to ";
	}
	std::cout<<table[pathList[x]] << std::endl;  
	std::cout<<"Total Path Length: " << weight << " units" << std::endl;
	
	std::cout << std::endl << "Thank You for using Fastest Pizza Delivery Services!" << std::endl;
	char end;
	std::cin >> end; // To hold the console window open
	
	return(0);																		
}

int UI :: makeGraph()
{
	/*
	Creates the actual graph object from the data file
	*/
	
	int i;
	for(i = 0; std::strcmp(table[i], "\0") != 0; i++);												//counting total number of vertices
	Graph g(i);														   			//graph object has i vertices

	std::ifstream file;
	file.open(filePath);
	
	char temp[MAX_STRLEN];
	
	while (file>>temp){
		int index1=refer(temp);
		file>>temp;
		int index2=refer(temp);
		file>>temp;
		int weight=atoi(temp);
		
		//std::cout << "Adding edge with " << index1 << " " << index2 << " " << weight << std::endl;
		
		g.addEdge(index1, index2, weight);
	}
	
	file.close();
	
	map = g;
	
	return(0);
}

int UI :: takeInput(int &srcVertex, int &destVertex)
{
	/*
	Handles the entire end user interface.
	Returns 1 if shortest path is to be calculated
	and 0 if not.
	*/

	printVisual();
	int pathNeeded = inputScreen(srcVertex, destVertex);
	
	return(pathNeeded);
}

int UI :: inputScreen(int &srcVertex, int &destVertex)
{
	/*
	Runs the menu screen offering options.
	Returns 1 if shortest path is to be calculated and 0 if not.
	*/
	
	enum options {path=1, display, add, exit};
	int opt = 4;
	int chosen = 1;
	int pathChosen = 0; // do you want the shortest path
	int rerun = 0;
	
	std::cout << std::endl;
	std::cout << " Main Menu\n-----------\n";
	std::cout<<"1. If you wish to find the shortest path, press 1 \n";
	std::cout<<"2. If you wish to see locations in the city, press 2 \n";
	std::cout<<"3. If you wish to add places to the directory, press 3 \n";
	std::cout<<"4. If you wish to exit, press 4\n";
	std::cout<<"Choice: ";

	std::cin>>opt;
	
	switch(opt)
	{
		case path:
			questPath(srcVertex, destVertex);
			pathChosen = 1;
			break;
			
		case display:
			displayCity();
			rerun = 1;
			break;
			
		case add:
			addDistance();
			rerun = 1;
			break;
			
		case exit:
			std::cout << "Thank You for using our service!" << std::endl;
			std::exit(0);
			break;
			
		default:
			chosen = 0;
	}
	
	if(!chosen || rerun)
	{
		if(!chosen && !rerun)
			std::cout << "Only numbers 1-4 are allowed." << std::endl;

		pathChosen = inputScreen(srcVertex, destVertex);
	}
	
	return(pathChosen);
}

int UI :: questPath(int &srcVertex, int &destVertex){
	/*
		Takes user input for source vertex and destination vertex for shortest path.
	*/
	
	string src, dest;
	srcVertex = destVertex = -1;
	
	std::cout << "In order to avail this service please enter your starting point" << std::endl;
	std::cout << "(like your shop or a house you may be at) and your customer's address" << std::endl;
	std::cout << "as the end point" << std::endl << std::endl; 
	
	std::cout << "Please enter Starting Point: ";
	std::cin >> src;
	std::cout << "Please enter End Point: ";
	std::cin >> dest; 
	
	for(int i = 0; i < map.getNumOfVertices(); i++)
	{
		if(std::strcmp(src, table[i]) == 0)
		{
			srcVertex = i;
		}
	}
	
	if(srcVertex == -1)
	{
		std::cout << "No such point exists on the map: " << src << std::endl;
		return(-1);
	}
	
	for(int j = 0; j < map.getNumOfVertices(); j++)
	{
		if(std::strcmp(dest, table[j]) == 0)
		{
			destVertex = j;
		}
	}
	
	if(destVertex == -1)
	{
		std::cout << "No such point exists on the map: " << dest << std::endl;
		return(-1);
	}
	
	
	return 0;
}

int UI :: addDistance()
{
	/*
	Adds a new edge to the data file 
	*/
	
	string name1,name2;
	int dist;
	
	if (map.getNumOfVertices() == MAX_VERTICES){
		std::cout<<"Cannot add any more locations" << std::endl;
	}
	
	else{
		std::cout << "Proceeding to add new path on the map" << std::endl;
		
		std::cout<<"Please enter first location: ";
		std::cin>>name1;
		
		std::cout<<"Enter name of neighbouring location: ";
		std::cin>>name2;
		
		std::cout<<"Enter distance between locations: ";
		std::cin>>dist;
		
		int index1 = refer(name1);
		int index2 = refer(name2);
		
		if(index1 != -1 && index2 != -1 && map.getEdgeWeight(index1, index2) > 0) // This won't give errors
		{
			std::cout << "WARNING: Existing path is getting changed!" << std::endl;
			std::cout << "It is NOT recommended to update existing paths this way. " << std::endl;
			std::cout << "Contact Administrator if you want to update the map not extend it." << std::endl;
		}
		
		std::ofstream file;
		file.open(filePath, std::ios::app);    			//define at the start
		
		file << std::endl;
		file << name1 << " " << name2 << " " << dist;
		file.close();
		
		char outputMsg[] = "Please not that these changes will NOT be in effect till the program is restarted.";
		std::cout << outputMsg << std::endl;
		
		char option;
		std::cout << "Exit Program [y/n]: ";
		std::cin >> option;
		
		if(std::tolower(option) == 'y')
			std::exit(0);
		
		// in all other cases the program doesn't stop
	}

	std::cout << "Returning to home page." << std::endl;	
	
	return(0);
}

int UI :: displayCity(){
	/*
	Displays the list of locations on the map.
	*/
	
	std::cout<<"Locations: \n";
	
	for (int i=0;i<map.getNumOfVertices();i++){
		std::cout << i+1 << ". " << table[i] << std::endl;
	}
	
	std::cout << "Returning to home page." << std::endl;	

	return(0);
}

int UI :: printVisual()
{
	/*
	Displays starting visual
	*/
	
	std::cout<<"                        ___              \n";
	std::cout<<"                        |  ~~--.         \n";
	std::cout<<"                        |\%=@\%\%/          \n";
	std::cout<<"                        |o\%\%\%/           \n";
	std::cout<<"                     __ |\%\%o/            \n";
	std::cout<<"               _,--~~ | |(_/ ._          \n";
	std::cout<<"            ,/'  m\%\%\%\%| |o/ /  `\\.       \n";
	std::cout<<"           /' m\%\%o(_)\%| |/ /o\%\%m `\\      \n";
	std::cout<<"         /' \%\%@=\%o\%\%\%o|   /(_)o\%\%\% `\\    \n";
	std::cout<<"        /  \%o\%\%\%\%\%=@\%\%|  /\%\%o\%\%@=\%\%  \\   \n";
	std::cout<<"       |  (_)\%(_)\%\%o\%\%| /\%\%\%=@(_)\%\%\%  |  \n";
	std::cout<<"       | \%\%o\%\%\%\%o\%\%\%(_|/\%o\%\%o\%\%\%\%o\%\%\% |  \n";
	std::cout<<"       | \%\%o\%(_)\%\%\%\%\%o\%(_)\%\%\%o\%\%o\%o\%\% |  \n";
	std::cout<<"       |  (_)\%\%=@\%(_)\%o\%o\%\%(_)\%o(_)\%  |  \n";
	std::cout<<"        \ ~\%\%o\%\%\%\%\%o\%o\%=@\%\%o\%\%@\%\%o\%~ /   \n";
	std::cout<<"         \. ~o\%\%(_)\%\%\%o\%(_)\%\%(_)o~ ,/    \n";
	std::cout<<"           \_ ~o\%=@\%(_)\%o\%\%(_)\%~ _/      \n";
	std::cout<<"             `\_~~o\%\%\%o\%\%\%\%\%~~_/'        \n";
	std::cout<<"                `--..____,,--'           \n";
	std::cout<<"\n \n \n";
	
	std::cout<<"WELCOME TO FASTEST PIZZA SERVICES! \n";
	std::cout<<"We help you reach your customers in the fastest manner possible, so that you may serve them your pizzas as fresh as possible. \n";
	
	return(0);
}

Graph UI :: getMap()
{
	/*
	Returns the map graph prepared from the file. 
	*/
	return(map);
}


