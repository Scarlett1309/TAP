#include<iostream>
#include <string.h>
using namespace std;
int d[100][100];
#define MIN(x,y) ((x) < (y) ? (x) : (y))
int main()
{
    //citim datele de intrare
    int i, j, m, n, aux, diferenta, minim;
    char cuvant1[] = "carte";
    char cuvant2[] = "antet";
    char temp;
    //retinem in m si n lungimea primul respectiv al celui de-al doilea cuvant
    m = strlen(cuvant1);
    n = strlen(cuvant2);
    //matricea d[i][j] reprezinta numarul minim de operatii ce trebuie efectuate asupra primelor i caractere din primul cuvant
        // pentru a se obtine primele j caractere in al doilea cuvant.
    for (i = 0; i <= m; i++)
        d[0][i] = i;
    for (j = 0; j <= n; j++)
        d[j][0] = j;
    for (j = 1; j <= m; j++)
    {
        for (i = 1; i <= n; i++)
        {
            if (cuvant1[i - 1] == cuvant2[j - 1]) //diferenta este 0 daca al i-lea caracter din primul cuvant este identic cu al j-lea caracte din al doilea
                diferenta = 0;
            else
                diferenta = 1; //si 1 daca cele 2 caractere sunt diferite.
            aux = MIN((d[i - 1][j] + 1), (d[i][j - 1] + 1));
            d[i][j] = MIN(aux, (d[i - 1][j - 1] + diferenta));
        }
    }

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }

    int k = n;
    int l = m;
    while (d[k - 1][l] != 0 && d[k][l - 1] != 0)
    {


        if (d[k - 1][l - 1] == d[k][l])
        {
            cout << "pastram " << cuvant1[k - 1] << endl;
            k--;
            l--;
        }
        if (d[k - 1][l - 1] != d[k][l])
        {
            aux = MIN((d[k - 1][l]), (d[k][l - 1]));
            minim = MIN(aux, (d[k - 1][l - 1]));
            if (minim == d[k - 1][l])
            {
                cout << "Stergem " << cuvant1[k - 1] << endl;
                k--;
                l--;
            }
            else if (minim == d[k][l - 1])
            {
                cout << "A fost inserat caracterul " << cuvant2[l - 1] << endl;
                l--;
            }

            else if (minim == d[k - 1][l - 1])
            {
                cout << cuvant1[k] << " devine " << cuvant2[l - 1] << endl;
                k--;
                l--;
            }
        }
    }

    cout << "Distanta Levenshtein este " << d[n][m];
    return 0;
}
