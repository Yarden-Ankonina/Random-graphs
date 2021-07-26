#pragma once
#include <vector>
using namespace std;

class Graph
{
private:
	int vertices;	//amount of vertices
	vector<vector<int>> adj; //adjacency list of edges - using vector for efficiancy -add to end of list in constant time
public:
	Graph(const int &v);
	Graph(const Graph& graph);
	void addEdge(const int &v,const int &w);
	int getVertices()const;
	void print()const;
	bool allNodesHaveNeighbours()const;
	bool bfs(const int &src,const bool &flag, int & max)const;
};


