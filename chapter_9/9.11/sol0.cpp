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
#define SIZE 50

using namespace std;

void init(int f[SIZE][SIZE][SIZE], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                f[i][j][k] = -1;
}

void dfs(int f[SIZE][SIZE][SIZE], int i, int j, int k, string &expr) {
    if (f[i][j][k] != -1)
        return;
    if (i == j) {
        if (expr[i] - '0' == k)
            f[i][j][k] = 1;
        else
            f[i][j][k] = 0;
        return;
    }
    f[i][j][k] = 0;
    for (int l = i + 1; l <= j - 1; l += 2) {
        dfs(f, i, l - 1, 0, expr);
        dfs(f, i, l - 1, 1, expr);
        dfs(f, l + 1, j, 0, expr);
        dfs(f, l + 1, j, 1, expr);
        if (k == 0) {
            switch(expr[l]) {
                case '&':
                    f[i][j][k] += f[i][l - 1][0] * f[l + 1][j][0];
                    f[i][j][k] += f[i][l - 1][1] * f[l + 1][j][0];
                    f[i][j][k] += f[i][l - 1][0] * f[l + 1][j][1];
                case '|':
                    f[i][j][k] += f[i][l - 1][0] * f[l + 1][j][0];
                    break;
                case '^':
                    f[i][j][k] += f[i][l - 1][0] * f[l + 1][j][0];
                    f[i][j][k] += f[i][l - 1][1] * f[l + 1][j][1];
                    break;
            }
        } else {
            switch(expr[l]) {
                case '|':
                case '^':
                    f[i][j][k] += f[i][l - 1][1] * f[l + 1][j][0];
                    f[i][j][k] += f[i][l - 1][0] * f[l + 1][j][1];
                    break;
                case '&':
                    f[i][j][k] += f[i][l - 1][1] * f[l + 1][j][1];
                    break;
            }
        }
    }
}

int getParenWays(string &expr, int result) {
    int n = expr.size();
    int f[SIZE][SIZE][SIZE];
    init(f, n);
    dfs(f, 0, n - 1, result, expr);
    return f[0][n - 1][result];
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string expr = "1^0|0|1";
    //string expr = "0|1";
    cout << expr << endl;
    int result = 0;
    cout << getParenWays(expr, result) << endl;
    return 0;
}
