#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;
class algorithms
{
private:
	double costmatrix[20][20];
	int NUMELEMENTS;
	int numcities;
	double currentbestcost;
	int* currentbesttour;
	int* s;
	int timesprinted = 0;
public:
	algorithms(int newcities);
	void BF();
	void perm1(int permsthiscall);
	void printS();
	void testswap(int a,int b);
	double getcurrentbestcost();
	int factorial(int n);
};

