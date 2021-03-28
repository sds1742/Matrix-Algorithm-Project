#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <utility>
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
	double elite1cost;
	int* elite2;
	double elite2cost;
	int timesprinted;
	int genscompleted;
public:
	genetic(int newcities);
	void perm2(int permsthiscall);
	void printS(int start);
	void sortingalgorithm();
	void mutate(int i);
	void newgens();
	double getbest();
	
};