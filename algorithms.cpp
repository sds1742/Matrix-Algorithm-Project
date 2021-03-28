#include "algorithms.h"


algorithms::algorithms(int newcities)
{
    numcities = newcities;
    NUMELEMENTS = numcities;
    currentbestcost = 1000000;
    ifstream is;
    is.open("distances.txt");
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (j == i) {
                    continue;
                }
                else {
                    is >> costmatrix[i][j];
                }
            }
        }
    
    if (is.eof()) {
        is.close();
    }
    s = new int[numcities];
    currentbesttour = new int[numcities];
    for (int i = 0; i < numcities; i++) {
        s[i] = i;
    }
    BF();
  }

void algorithms::BF()
{
    int i = factorial(numcities - 1);
    perm1(i);
}

void algorithms::perm1(int permsthiscall)
{
    int m, k, p, q, i;
    printS();
    timesprinted++;
    for (i = 1; i < permsthiscall; i++)
    {
        m = NUMELEMENTS - 2;
        while (s[m] > s[m + 1])
        {
            m = m - 1;
        }
        k = NUMELEMENTS - 1;
        while (s[m] > s[k])
        {
            k = k - 1;
        }
        testswap(m, k);
        p = m + 1;
        q = NUMELEMENTS - 1;
        while (p < q)
        {
            testswap(p, q);
            p++;
            q--;
        }
        printS();
        timesprinted++;
    }
}

void algorithms::printS()
{

    double cost = 0;
    for (int i = 0; i < NUMELEMENTS; i++) {
        //cout << s[i];
    }
    //cout << endl;
    for (int i = 0; i < NUMELEMENTS - 1; ++i) {
        cost = cost + costmatrix[s[i]][s[i + 1]];
    }
    if ((cost < currentbestcost)) {
        currentbesttour = s;
        currentbestcost = cost;
    }
}

void algorithms::testswap(int a, int b)
{
    swap(s[a], s[b]);
}

double algorithms::getcurrentbestcost()
{
    return currentbestcost;
}

int algorithms::factorial(int n)
{
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}