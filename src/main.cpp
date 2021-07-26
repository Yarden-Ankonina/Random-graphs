/*
	Class :Algorithms 2 - Assignment number 1
	id:205415564
	Name: Yarden Ankonina 
*/

#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include "functions.h"
#include "Graph.h"
using namespace std;

int main()
{
	int choice, v =1000; // choice - witch feature to check, v - amount of vertices in graph
	bool end = false;  //menu end flag

	double p_arr1[10] = { 0.005, 0.006, 0.0065, 0.0067, 0.006900, 0.0075, 0.0085, 0.009, 0.0095, 0.01 }; //connectivity probabilityt array
	double p_arr2[10] = { 0.07, 0.08, 0.09,0.1,0.115, 0.118, 0.119, 0.12 ,0.122, 0.125 }; //diameter probabilityt array
	double p_arr3[10] = { 0.005, 0.0055, 0.006, 0.0065, 0.0068, 0.007, 0.0075, 0.008,0.0085, 0.009 }; //is isolated probabilityt array

	//menu
	while(end == false)
	{
		cout << " please choose simulation (ENTER):" << endl;
		cout << " connectivity(1) | diameter(2) | isolated vertex(3) | exit(4)	" << endl;
		cin >> choice;
		switch (choice)
		{
		case(1):
			simulation1(p_arr1,v); //connectivity
			break;
		case(2):
			simulation2(p_arr2,v);//diameter
			break;
		case(3):
			simulation3(p_arr3, v);//it there a isolated vertex
			break;
		case(4):
			end = true;
			cout << " THANK YOU, BYE BYE " << endl; // exit
			break;
		}
	}
	
	return 0;
}
