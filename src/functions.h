#pragma once
#include "Graph.h"
#include <string>

//required functions
Graph build_random_graph(double p, int V);
int diameter(const Graph& graph);
bool is_isolated(const Graph& graph);
bool connectivity(const Graph& graph);

//additional functions
void simulation1(const double *, const int&);//connectivity
void simulation2(const double*, const int&);//diameter
void simulation3(const double*, const int&);//vertex isolated
void write_csv(string fileName, int arrSize,const double* p_arr, double* result_arr, int* numOfsuccessfulGraphs);//write to csv file
bool writeFiles();

