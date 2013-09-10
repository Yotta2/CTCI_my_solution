#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>
#include <list>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <map>
#include <time.h>

#define EPS 1e-6
#define SIZE 300

using namespace std;

int **my2DAlloc(int row, int col) {
    int headerSize = row * sizeof(int *);
    int dataSize = row * col * sizeof(int);
    int **p1 = (int **)malloc(headerSize + dataSize);
    //malloc fail
    if (p1 == NULL)
        return NULL;
    for (int i = 0; i < row; i++)
        p1[i] = (int *)(p1 + row + col * i);
    return p1;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int **arr = my2DAlloc(3, 2);
    arr[1][1] = 1314;
    cout << arr[1][1] << endl;
    return 0;
}
