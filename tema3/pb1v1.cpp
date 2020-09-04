#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int main() {
	int n;
	vector <pair<int, int>> vect;
	int m[100];
	int next[100];
	int road = 0;
	int aux = 0;


	cin >> n;
	for (int i = 0; i < n; i++) {
		pair<int, int> domino;
		cin >> domino.first >> domino.second;
		vect.push_back(domino);
		m[i] = 1;
		next[i] = -1;
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++)
			if (vect[i].second == vect[j].first && m[i] <= m[j]) {
				m[i] = m[j] + 1;
				next[i] = j;
			}
		aux = road;
	}

	int i;
	for (i = 0; i < n; i++)
		if (next[i] != -1)
			break;

	while (i != -1) {
		cout << vect[i].first << " " << vect[i].second;
		cout << endl;
		i = next[i];
	}

	system("pause");
	return 1;
}