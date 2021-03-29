#include "algorithms.h" 
#include "genetic.h"

int main() {
	int numbercities;
	cin >> numbercities;
	cout << "enter the number of tours per generation" << endl;
	int tourspergen;
	cin >> tourspergen;
	cout << "enter the percent of the tours that will be mutated, as a decimal" << endl;
	double percentmutations;
	cin >> percentmutations;
	cout << "enter the number of generations" << endl;
	int numgens;
	cin >> numgens;
	genetic g(numbercities, tourspergen, numgens, percentmutations);
	algorithms a(numbercities);
	double x = g.getbest();
	double y = a.getcurrentbestcost();
	cout<<"the genetic algorithm was " << (x / y)*100<<"% accurate" << endl;
	return 0;
}