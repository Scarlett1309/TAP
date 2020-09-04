#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

//structura pentru memorarea intervalelor
struct Interval {
	int x, y;
};

//functia de comparare pt qsort
int compare(Interval A, Interval B) {
	if (A.x > B.x)
		return 0;
	if (A.x <= B.x)
		return 1;
}

int main() {
	//1. Citirea din fisier
	ifstream f("date.in");
	ofstream g("date.out");

	int a, b, n;
	vector <Interval> interval;
	// citire interval principal + nr intervale
	f >> a >> b;
	f >> n;
	Interval aux;

	//citim si salvam intervalele
	for (int i = 1; i <= n; i++) {
		f >> aux.x >> aux.y;
		interval.push_back(aux);
	}

	//sortam intervalele crescator dupa coordonata x folosind QSORT (O(nlogn))
	sort(interval.begin(), interval.end(), compare);

	//vector pt memorarea solutiei
	vector <Interval> solutie;

	//retinem cea mai buna solutie in variabila de tip interval greed, fie aceasta primul interval dat
	Interval greed = interval[0];
	for (int i = 1; i < interval.size(); i++) {
		if (interval[i].x > a)
			//verificam intersectia cu intervalul dorit
			//nu cautam in toata multimea de intervale, deoarece mereu se micsoreaza intervalul dat
			//la inceput, astfel incat noua lui margine stanga(x) fiind marginea dreapta(y) a lui greed
			if (greed.x <= a && greed.y > a) {
				a = greed.y;
				solutie.push_back(greed);
				greed = interval[i];
			}
			else
				;

		else
			if (greed.y < interval[i].y)
				greed = interval[i];
	}

	if (greed.x <= a && greed.y > a) {
		a = greed.y;
		solutie.push_back(greed);
	}

	//afisare solutie
	//daca nu a fost acoperit tot intervalul -> -1
	if (a < b)
		g << -1;
	else
		for (int i = 0; i < solutie.size(); i++)
			g << "[" << solutie[i].x << " " << solutie[i].y << "] \n";

	system("pause");
	return 1;
}
