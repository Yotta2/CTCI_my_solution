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
#define SIZE 5

using namespace std;

void DP(int n, int coins[SIZE]) {
    int f[SIZE][n + 1];
    memset(f, 0, sizeof(f));
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j <= n; j++) {
            if (j == 0) {
                f[i][j] = 1;
                continue;
            }
            if (i - 1 >= 0)
                f[i][j] += f[i - 1][j];
            if (j - coins[i] >= 0)
                f[i][j] += f[i][j - coins[i]];
        }
    cout << f[3][n] << endl;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n = 1511;
    int coins[SIZE] = {1, 5, 10, 25};
    DP(n, coins);
    return 0;
}
