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
#define SIZE 10000100

using namespace std;

int f[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        f[i] = -1;
    f[0] = f[1] = 0;
    for (int i = 2; i <= 9; i++)
        f[i] = 1;
}

int DP(int i) {
    if (f[i] != -1)
        return f[i];
    int b = 10;
    while (true) {
        if (i / b >= 1 && i / b / 10 == 0)
            break;
        b *= 10;
    }
    f[i] = 0;
    f[i] += DP(i % b);
    f[i] += i / b * DP(b - 1);
    if (i / b > 2)
        f[i] += b;
    else if (i / b == 2)
        f[i] += i % b  + 1;
    return f[i];
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    init();
    int n = 312323423;
    cout << DP(n) << endl;
    return 0;
}
