#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <utility>
#include <chrono>
using namespace std;
class genetic
{
private:
	double costmatrix[20][20];
	int NUMELEMENTS;
	int numcities;
	int tourspergen;
	int numgens;
	double percentmutations;
	int* s;
	int** currentgen;
	int currentcost;
	int* elite1;
	int* elite2;
	int timesprinted;
	int genscompleted;
public:
	genetic(int newcities,int toursgen,int numbgen,double permut);
	void perm2(int permsthiscall);
	void printS(int start);
	void sortingalgorithm();
	void mutate(int i);
	void newgens();
	double getbest();
};