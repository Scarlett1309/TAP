#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAX 5000
using namespace std;

vector<int> v;
vector < vector<int> > a;
int nr, n;

void citire() {

    int b;
    ifstream f("date.txt");
    while (f >> b) {

        nr++;
        v.push_back(b);

    }

    for (int i = 0; i < nr; i++)
    {
        vector <int> row;
        a.push_back(row);
    }

}

int cautare(vector<int> vec, int i, int s, int x) {

    if (x < vec[0]) return -1;
    if (x > vec[s]) return MAX;

    while (i <= s) {
        int m = i + (s - 1) / 2;

        if (vec[m] == x) return m;
        if (x<vec[m + 1] && x>vec[m]) return m;
        if (vec[m] < x) i = m + 1;
        if (vec[m] > x) s = m - 1;
    }
}

void descompunere() {
    vector<int> aux(nr);
    a[0].push_back(v[0]);

    aux[0] = v[0]; n++;
    for (int i = 1; i < nr; i++) {

        if (cautare(aux, 0, n - 1, v[i]) == MAX)
        {
            aux[n] = v[i];
            a[n].push_back(v[i]);
            n++;
        }


        else if (cautare(aux, 0, n - 1, v[i]) == -1) {
            aux[0] = v[i];
            a[0].push_back(v[i]);
        }
        else {
            int p = cautare(aux, 0, n - 1, v[i]);
            aux[p] = v[i];
            a[p].push_back(v[i]);

        }
    }
}

void afisare() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i].size(); j++)
            cout << a[i][j] << " ";

        cout << endl;
    }
}


int main()
{
    citire();
    descompunere();
    afisare();
    return 0;
}
