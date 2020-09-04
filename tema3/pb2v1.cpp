#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m, c[100][100];

	int t[100][100], prev[100];

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> t[i][j];
			c[i - 1][j - 1] = 0;
			c[i + 1][j - 1] = 0;
			c[i][j] = 0;
		}

	for (int j = 1; j <= m; j++)
		for (int i = 1; i <= n; i++) {
			c[i][j] = max(c[i - 1][j - 1], max(c[i][j - 1], c[i + 1][j - 1])) + t[i][j];
			if (max(c[i - 1][j - 1], max(c[i][j - 1], c[i + 1][j - 1])) == c[i - 1][j - 1])
				prev[c[i][j]] = 3;
			if (max(c[i - 1][j - 1], max(c[i][j - 1], c[i + 1][j - 1])) == c[i][j - 1])
				prev[c[i][j]] = 2;
			if (max(c[i - 1][j - 1], max(c[i][j - 1], c[i + 1][j - 1])) == c[i + 1][j - 1])
				prev[c[i][j]] = 1;
		}
	for (int i = 1; i <= n; i++)
		prev[t[i][1]] = 0;

	int maxi = 0, ii = 0, jj = 0;

	for (int j = 1; j <= n; j++)
		if (c[j][m] > maxi) {
			maxi = c[j][m];
			ii = j;
			jj = m;
		}

	cout << maxi << endl;

	while (prev[maxi] != 0) {
		cout << ii << " " << jj << endl;
		jj--;
		if (prev[maxi] == 1) ii++;
		if (prev[maxi] == 3) ii--;

		maxi = c[ii][jj];
	}

	cout << ii << " " << jj << endl;

	system("pause");
	return 1;

}