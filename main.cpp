#include "algorithms.h" 
#include "genetic.h"
#include "timecalc.h"

int main() {
	int numbercities;
	cin >> numbercities;
	genetic g(numbercities);
	algorithms a(numbercities);
	double x = g.getbest();
	double y = a.getcurrentbestcost();
	cout<<"the genetic algorithm was" << (x / y)*100<<"% accurate" << endl;
	return 0;
}