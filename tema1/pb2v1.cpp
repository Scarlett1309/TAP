#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <limits>
#include <fstream>
using namespace std;

//strucutra folosita pentru memorarea fiecarei activitati
struct activitate
{
	int h, till, nr;
};

//functie cmp folosita pentru quicksort
int cmp(activitate a, activitate b)
{
	if ((a.till - a.h) - (b.till - b.h) > 0)
		return 0;
	else
		return 1;
}

int main()
{
	//declarare date
	int n, i, maxi;
	int greed = 0;
	//maxi are cea mai mare valoare folsibila (folosind limits)
	maxi = numeric_limits<int>::max();
	vector <activitate> activitati;
	//citire date
	cin >> n;
	activitate aux;

	//citire activitati si memorarea acestora
	for (i = 0; i < n; i++)
	{
		cin >> aux.h >> aux.till;
		aux.nr = i + 1;
		activitati.push_back(aux);
	}

	//sortarea activitatilor dupa intarzierea meaxima.
	sort(activitati.begin(), activitati.end(), cmp);

	//afisare solutie
	for (i = 0; i < activitati.size(); i++)
	{
		cout << "activitatea " << activitati[i].nr << ": intervalul " << greed << " ";
		greed = greed + activitati[i].h;
		cout << greed << " intarziere ";
		maxi = max(0, greed - activitati[i].till);
		cout << maxi << endl;
	}
	cout << "Intarziere TOTALA: " << maxi << endl;

	return 0;
}
