#include <iostream>

using namespace std;

int binarySearch(int a[], int low, int high) {
	if (high >= low) {
		int mid = (low + high) / 2;
		if (mid == a[mid])
			return mid;
		else if (mid > a[mid])
			return binarySearch(a, (mid + 1), high);
		else return binarySearch(a, low, (mid - 1));
	}
	return -1;
}

int main() {
	int i, n, a[100];

	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];

	cout << binarySearch(a, 0, n - 1);
	system("pause");
	return 1;
}