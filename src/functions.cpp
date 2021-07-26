#include "Graph.h"
#include "functions.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#define INFINITE -2

//function gets a probability and amount of vertices and creates a random graph with probability of p to create a edge between every two vertices
Graph build_random_graph(double p, int v)
{
	Graph graph(v);
	double threshold1 = log(v) / v;
	srand((unsigned)time(NULL));//randomize the seed
	double r;
	for (int i = 0; i < v - 1; i++)
	{
		for (int j = i + 1; j < v; j++)
		{
				r = ((double)rand() / RAND_MAX);//get a random number between 0 to 1
				if (p >= r) 
					graph.addEdge(i, j);//create edge
		}
	}
	return graph;
}

//calculates a graph's diameter using breadth first search algorithm
int diameter(const Graph& graph)
{
	//first to check if the graph is connected - if not the diameter is infinity and were done
	int src = 0, max = 0, diameter = 0;
	if (graph.bfs(src, true, max) == false)
		return INFINITE;//infinite is -2 in my program
	else //graph is connected now we will go through every node and check if there is a bigger diameter than the one we found 
	{
		diameter = max;
		int v = graph.getVertices();
		for (int i = 1; i < v; i++)//start from 1 because we check node 0 before
		{
			graph.bfs(i, false, max);
			if (diameter < max)
				diameter = max;
			
		}
		return diameter;
	}
}


//Get a graph and returns if there is a vertex that has no neighbours
bool is_isolated(const Graph& graph)
{
	if (graph.allNodesHaveNeighbours() == true)//if all nodes have neighbours the graph is not isolated
		return false;
	else 
		return true;
}

//Use bfs to determine if the graph is connected
bool connectivity(const Graph& graph)
{
	int src = 0, max = 0; //src doesn't matter in this case
	if(graph.bfs(src, true, max))//bfs returns if the graph is connected
		return true;
	else
		return false;

}

// Assignment requires three seperate simulations therefore the simulations 1,2,3 are not combined

/*Simulate the first feature - connectivity. 
Get an array of probabilities and amount of vertices.
will go through all the probabilities and create random graphs.
Then check for each p - 500 random graphs and calculate how many times the feature accured.
Calculate the probability for the feature to accure and output to a csv file.
*/
void simulation1(const double* p_arr, const int& v)
{
	//double threshold_1 = 0.006907;
	int numOfsuccessfulGraphs[10] = {};//how many graphs traits are succseful
	double result_arr[10] = {};//probability for each graph to 

		//loop for each probabillity
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 500; j++)
			{
				Graph graph = build_random_graph(p_arr[i], v);
				//bool connected = connectivity(graph);
				//if ((connected == true && p_arr[i] > threshold_1) || (connected == false && p_arr[i] < threshold_1)) -  check when feature accures
				if(connectivity(graph))
					numOfsuccessfulGraphs[i]++;
				cout << "Graph num " << j << " been checked" << endl;//print feedback 

			}
			result_arr[i] = (double)numOfsuccessfulGraphs[i] / 500; //chances to get feature by probability - amount divide by total graph per p
			cout << "[" << p_arr[i] << "] -> " << numOfsuccessfulGraphs[i] << " are successful " << endl;//print feedback 
		}
	if(writeFiles() == true)
			write_csv("simulation_1.csv", 10, p_arr, result_arr, numOfsuccessfulGraphs);
}

/*Simulate the second feature - diameter is equal to 2.
Get an array of probabilities and amount of vertices.
will go through all the probabilities and create random graphs.
Then check for each p - 500 random graphs and calculate how many times the feature accured.
Calculate the probability for the feature to accure and output to a csv file.
*/
void simulation2(const double* p_arr, const int& v)
{
	//double threshold_2 = 0.117539;
	int numOfsuccessfulGraphs[10] = {};//how many graphs traits are succseful
	double result_arr[10] = {};//probability for each graph to 
	
		//loop for each probabillity
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 500; j++)
			{
				Graph graph = build_random_graph(p_arr[i], v);
				//int diam = diameter(graph);
				//if ((diam == 2 && p_arr[i] > threshold_2)||(diam > 2 && p_arr[i]<threshold_2)) - check when feature accures
				if (diameter(graph) == 2)
					numOfsuccessfulGraphs[i]++;
				cout << "Graph num " << j << " been checked" << endl;//print feedback 

			}
			result_arr[i] = (double)numOfsuccessfulGraphs[i] / 500;//chances to get feature by probability - amount divide by total graph per p
			cout << "[" << p_arr[i] << "] -> " << numOfsuccessfulGraphs[i] << " are successful " << endl;//print feedback 
		}
	if (writeFiles() == true)
			write_csv("simulation_2.csv", 10, p_arr, result_arr, numOfsuccessfulGraphs);
}

/*Simulate the third feature - isolated vertex.
Get an array of probabilities and amount of vertices.
will go through all the probabilities and create random graphs.
Then check for each p - 500 random graphs and calculate how many times the feature accured.
Calculate the probability for the feature to accure and output to a csv file.
*/
void simulation3(const double* p_arr, const int& v)
{
	//double threshold_3 = 0.006907;
	int numOfsuccessfulGraphs[10] = {};//how many graphs traits are succseful
	double result_arr[10] = {};//probability for each graph to 

	//loop for each probabillity
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			Graph graph = build_random_graph(p_arr[i], v);
			//bool iso = is_isolated(graph);
			//if ((iso == true && p_arr[i] < threshold_3)||(iso == false && p_arr[i] > threshold_3)) -check when feature accures
			if(is_isolated(graph))
				numOfsuccessfulGraphs[i]++;
			cout << "Graph num " << j << " been checked" << endl;//print feedback 
		}
		result_arr[i] = (double)numOfsuccessfulGraphs[i] / 500;//chances to get feature by probability - amount divide by total graph per p
		cout << "[" << p_arr[i] << "] -> " << numOfsuccessfulGraphs[i] << " are successful " << endl;//print feedback 
	}
	if (writeFiles() == true)
			write_csv("simulation_3.csv", 10, p_arr, result_arr, numOfsuccessfulGraphs);
}

//Ask the user if he wants to write to a csv file
bool writeFiles()
{
	cout << " Do you wish to export results to a csv file? (ENTER) " << endl;
	cout << " Yes(1) | No(0)" << endl;
	char result;
	bool end = true;
	while (end)
	{
		cin >> result;
		if (result == '0' || result == '1')
			end = false;
		else
			cout << "please enter again " << endl;

	}
	if (result == '0')
		return false;
	return true;
}


//write to file 
void write_csv(string fileName, int arrSize,const double* p_arr, double* result_arr, int* numOfsuccessfulGraphs)
{
	ofstream myFile(fileName);
	myFile << "P";
	for (int i = 0; i < arrSize; i++)
	{
		myFile << ",";
		myFile << p_arr[i];
	}
	myFile << endl;
	myFile << "Amount of graphs with the feature";
	for (int i = 0; i < arrSize; i++)
	{
		myFile << "," << numOfsuccessfulGraphs[i];
	}
	myFile << endl;
	myFile << "Probability that the feature exists";
	for (int i = 0; i < arrSize; i++)
	{
		myFile << "," << result_arr[i];
	}

	myFile.close();
	cout << " File export successful "<<endl;
}
