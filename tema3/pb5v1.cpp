#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>
//spectacole

using namespace std;


struct Show {
	int x, y, w;
};

bool compare(Show i, Show j) {
	if (i.y > j.y) return false;
	else return true;
}

int main() {
	int n;
	vector <Show> s;
	int profit[100];
	int prev[100];
	int maxi = 0;
	int maxval = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		Show aux;
		cin >> aux.x >> aux.y >> aux.w;
		s.push_back(aux);
	}

	sort(s.begin(), s.end(), compare);


	for (int i = 0; i < n; i++) {
		profit[i] = s[i].w;
		prev[i] = -1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (s[j].y <= s[i].x) {
				if (profit[j] + s[i].w > profit[i]) {
					profit[i] = profit[j] + s[i].w;
					prev[i] = j;
				}
				if (maxval < profit[i]) {
					maxi = i;
					maxval = profit[i];
				}
			}

		}
	}

	vector <Show> aux;
	int i = maxi;
	int size = 0;

	while (prev[i] != -1) {
		aux.push_back(s[i]);
		i = prev[i];
		size++;
	}

	aux.push_back(s[i]);
	size++;
	int sum = 0;
	for (int j = size - 1; j >= 0; j--) {
		cout << aux[j].x << ' ' << aux[j].y;
		cout << endl;
		sum = sum + aux[j].w;
	}

	cout << "Profit : " << sum << endl;
	system("pause");
	return 1;
}