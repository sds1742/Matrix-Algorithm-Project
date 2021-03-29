
#include "genetic.h"

genetic::genetic(int newcities,int toursgen, int numbgen, double permut)
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    using std::chrono::minutes;
    numcities = newcities;
    NUMELEMENTS = numcities;
    numgens = numbgen;
    tourspergen = toursgen;
    percentmutations = permut;
    currentgen = new int* [tourspergen];
    for (int i = 0; i < tourspergen; ++i) {
        currentgen[i] = new int[numcities];
    }
    elite1 = new int[numcities];
    elite2 = new int[numcities];
    //initialize the costs. this is what's needed for all the rest of the logic. 
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
    for (int i = 0; i < numcities; i++) {
        s[i] = i;
    }
    auto t1 = high_resolution_clock::now();
    perm2(tourspergen);
    sortingalgorithm();
    elite1 = currentgen[0];
    elite2 = currentgen[1];
    genscompleted = 1;
    newgens();
    auto t2 = high_resolution_clock::now();
    auto min_int = duration_cast<minutes>(t2 - t1);
    auto sec_int = duration_cast<milliseconds>(t2 - t1);
    cout <<"genetic algoritm took "<< sec_int.count()<<" milliseconds which works out to "<<min_int.count()<<" minutes" << endl;
}


void genetic::perm2(int permsthiscall)
{
    int offset = tourspergen - permsthiscall;
    timesprinted = 0;
    int m, k, p, q, i;
    printS(offset);
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
        swap(s[m], s[k]);
        p = m + 1;
        q = NUMELEMENTS - 1;
        while (p < q)
        {
            swap(s[p], s[q]);
            p++;
            q--;
        }
        printS(offset);
        timesprinted++;
    }
}

void genetic::printS(int start)
{
    for (int i = 0; i < numcities; i++) {
        currentgen[start + timesprinted][i] = s[i];
        if (start != 0) {
            //cout << s[i];
        }
    }
   //cout << endl;
}

void genetic::sortingalgorithm()
{
    double* costarr = new double[tourspergen];
    for (int i = 0; i < tourspergen; i++) {
        double cost = 0;
        for (int j = 0; j < numcities - 1; j++) {
            cost = cost + costmatrix[currentgen[i][j]][currentgen[i][j + 1]];
        }
        costarr[i] = cost;
    }
    vector<pair<double, int*>> v(tourspergen);
    for (int i = 0; i < tourspergen; ++i) {
        v.at(i) = make_pair(costarr[i], currentgen[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < tourspergen; ++i) {
        costarr[i] = v.at(i).first;
        currentgen[i] = v.at(i).second;
    }
    
}



void genetic::mutate(int i)
{
    int numberswapped = rand() % 4 + 1;
    for (int j = 1; j < numberswapped+1; j++) {
        swap(currentgen[i][j], currentgen[i][numcities - j]);
    }
}

void genetic::newgens()
{
    int numbermutants = percentmutations * tourspergen;
    sortingalgorithm();
    elite1 = currentgen[0];
    elite2 = currentgen[1];
    if (genscompleted == numgens) {
        return;
    }
    else {
        for (int i = 2; i < numbermutants + 2; i++) {
            mutate(i);
        }
        perm2(tourspergen - numbermutants - 2);
        genscompleted++;
        newgens();
    }
        
}

double genetic::getbest()
{
    double elite1cost = 0;
    double elite2cost = 0;
    for (int i = 0; i < numcities-1; i++) {
        elite1cost  = elite1cost + costmatrix[elite1[i]][elite1[i + 1]];
        elite2cost = elite2cost + costmatrix[elite2[i]][elite2[i+1]];
    }
    return elite1cost;
}







