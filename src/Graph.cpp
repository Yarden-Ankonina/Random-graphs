#include "Graph.h"
#include <list>
#include <iostream>
#define INFINITE -2

//constructor
Graph::Graph(const int &v)
	:vertices(v)
{
	adj.resize(v);
}


//copy constructor
Graph::Graph(const Graph& graph)
{
	this->vertices = graph.vertices;
	this->adj.resize(graph.adj.size());
	int size = adj.size();
	for (int i = 0; i < size; i++)
	{
		this->adj[i] = graph.adj[i];
	}
}

//add edge to adj for both nodes - undirected graph
void Graph::addEdge(const int &v,const int &w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

int Graph::getVertices()const
{
	return this->vertices;
}


//additional function to print the adjacency list
void Graph::print() const
{
	int size = adj.size();
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] ";
		for (auto j : adj[i])
		{
			cout << "-> " << j;
		}
		cout << endl;
	}
}

//Go through each list and check if its empty - size is 0 - one is enough to determine that there is a vertex without neighbours
bool Graph::allNodesHaveNeighbours()const
{
	int size = adj.size();
	for (int i = 0; i < size; i++)
	{
		if (adj[i].size() == 0)
			return false;
	}
	return true;
}

/*breadth first search algorithm - without color or father array ( not needed ).
function gets source vertex , connectivity flag , and max diameter by reference,and returns if the graph is connected.
The function will be used in two ways :1.check if graph is connected. 2.If connected than find a maximum distance from the source to a different vertex.
*/

bool Graph::bfs(const int &src,const bool &connectivity, int & max)const
{
	int* distance = new int[vertices];
	bool *visited = new bool[vertices];
	for (int i = 0; i < vertices; i++)//reset arrays
	{
		visited[i] = false;
		distance[i] = INFINITE;
	}
	list<int> queue; //use list for pop_front functionallity

	visited[src] = true; 
	distance[src] = 0; //distance to itself is 0
	queue.push_back(src);

	//go through the queue and for each neighbour that is not visited - add to queue and calculate distance
	while (!queue.empty())
	{
		int t = queue.front();
		queue.pop_front();

		for (auto i : adj[t]) //loop through all edges of the current vertex
		{
			if (!visited[i])
			{
				visited[i] = true;
				distance[i] = distance[t] + 1;
				queue.push_back(i);
			}
		}
	}
	if (connectivity)//connectivity check
	{
		for (int i = 0; i < vertices; i++)
		{
			if (visited[i] == 0)
			{
				delete[]distance;
				delete[] visited;
				return false;//not connected
			}
		}
	}
	//  max distance check
		max = 0;
		for (int i = 0; i < vertices; i++)
		{
			if (distance[i] > 0)
			{
				max = distance[i];
			}
		}
	delete[]distance; 
	delete[] visited;
	return true;//connected
}

