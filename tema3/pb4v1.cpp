#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{

    int n, k;
    int vectors[100][100];
    int sizes[100];
    bool t[100][100];
    int prev[100][100];

    //citim fiecare vector si il adaugam in vectorul de vectori
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {

        cin >> sizes[i];
        for (int j = 0; j < sizes[i]; j++)
            cin >> vectors[i][j];
    }

    // t[0][elementDinPrimulVector]=turue ; prev[0][analog]=-1;
    for (int j = 0; j < sizes[0]; j++)
    {
        t[0][vectors[0][j]] = true;
        prev[0][vectors[0][j]] = -1;

    }

    //Pentru fiecare vector
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < sizes[i + 1]; j++) //Pentru fiecare element din vector
        {
            for (int l = 0; l < k; l++) //parcurgem primele k pozitii
            {
                cout << i << " si " << l << " " << t[i][l] << endl;
                if (t[i][l] == true)
                {
                    t[i + 1][l + vectors[i + 1][j]] = true;
                    prev[i + 1][l + vectors[i + 1][j]] = vectors[i + 1][j];
                }
            }
        }
    }

    if (t[n - 1][k] == true)
    {
        int i = n - 1;
        while (i > 0) {
            cout << prev[i][k] << ' ';
            k = k - prev[i][k];
            i--;
        }
        if (prev[i][k] == -1)
            cout << k;
    }
    else {
        cout << 0;
    }

}
