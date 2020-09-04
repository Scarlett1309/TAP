
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int table[1000][1000];
int mark = 0;

void fillTable(int x, int y, int size, int hx, int hy) {
    mark++;

    if (size == 2) {
        if (table[x][y] == 0)
            table[x][y] = mark;
        if (table[x][y + 1] == 0)
            table[x][y + 1] = mark;
        if (table[x + 1][y] == 0)
            table[x + 1][y] = mark;
        if (table[x + 1][y + 1] == 0)
            table[x + 1][y + 1] = mark;
    }
    else {
        int cx = x + size / 2; //coord centru
        int cy = y + size / 2;
        if (hx >= cx && hy >= cy) {
            table[cx - 1][cy - 1] = mark;
            table[cx][cy - 1] = mark;
            table[cx - 1][cy] = mark;
            fillTable(x, y, size / 2, cx - 1, cy - 1);
            fillTable(x, cy, size / 2, cx, cy - 1);
            fillTable(cx, y, size / 2, cx - 1, cy);
            fillTable(cx, cy, size / 2, hx, hy);


        }
        if (hx < cx && hy >= cy) {
            table[cx - 1][cy - 1] = mark;
            table[cx][cy] = mark;
            table[cx][cy - 1] = mark;
            fillTable(x, y, size / 2, cx - 1, cy - 1);
            fillTable(x, cy, size / 2, hx, hy);
            fillTable(cx, y, size / 2, cx, cy - 1);
            fillTable(cx, cy, size / 2, cx, cy);
        }
        if (hx >= cx && hy < cy) {
            table[cx - 1][cy - 1] = mark;
            table[cx][cy] = mark;
            table[cx - 1][cy] = mark;
            fillTable(x, y, size / 2, cx - 1, cy - 1);
            fillTable(x, cy, size / 2, cx - 1, cy);
            fillTable(cx, y, size / 2, hx, hy);
            fillTable(cx, cy, size / 2, cx, cy);

        }
        if (hx < cx && hy < cy) {
            table[cx][cy] = mark;
            table[cx][cy - 1] = mark;
            table[cx - 1][cy] = mark;
            fillTable(x, y, size / 2, hx, hy);
            fillTable(x, cy, size / 2, cx, cy - 1);
            fillTable(cx, y, size / 2, cx - 1, cy);
            fillTable(cx, cy, size / 2, cx, cy);

        }



    }
}

int main() {
    int n, hole_x, hole_y;

    cin >> n >> hole_x >> hole_y;
    table[hole_x][hole_y] = -1;
    int size = pow(2, n);

    fillTable(0, 0, size, hole_x, hole_y);

    table[hole_x][hole_y] = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << table[i][j] << "  ";
        }
        cout << endl;
    }


}
