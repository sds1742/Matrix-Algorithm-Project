#include "timecalc.h"

timecalc::timecalc()
{
	t = (struct timeval*)malloc(sizeof(timeval));
	gettimeofday(t, NULL);
	time_t startSec = t->tv_sec;
	s = startSec;

}

int timecalc::getfinal()
{
	long f;
	gettimeofday(t, NULL);
	f = (t->tv_sec) - startSec;
	return 0;
}
