#pragma once
//#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
class timecalc
{
private:
	long i;
	struct timeval* t;
	long s;
public:
	timecalc();
	int getfinal();
};

