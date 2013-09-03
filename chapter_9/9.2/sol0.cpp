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

#define EPS 1e-6
#define SIZE 110

using namespace std;

struct Loc {
    int x, y;
};

void init(int f[SIZE][SIZE], int m, int n) {
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            f[i][j] = 0;
    f[m - 1][n - 1] = 1;
}

void DP(int f[SIZE][SIZE], int m, int n, vector<vector<int> > &obstacleGrid, Loc nextStep[SIZE][SIZE]) {
    for (int i = m - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            if (i == m - 1 && j == n - 1)
                continue;
            else {
                Loc next;
                if (i + 1 <= m - 1 && obstacleGrid[i + 1][j] == 0) {
                    f[i][j] += f[i + 1][j];
                    if (f[i + 1][j] != 0) {
                        next.x = i + 1;
                        next.y = j;
                    }
                }
                if (j + 1 <= n - 1 && obstacleGrid[i][j + 1] == 0) {
                    f[i][j] += f[i][j + 1];
                    if (f[i][j + 1] != 0) {
                        next.x = i;
                        next.y = j + 1;
                    }
                }
                nextStep[i][j] = next;
            }
}

void printAPath(int m, int n, Loc nextStep[SIZE][SIZE]) {
    int x = 0;
    int y = 0;
    int nextX = 0;
    int nextY = 0;
    cout << "0 0" << endl;

    while (true) {
        if (x == m - 1 && y == n - 1)
            break;
        nextX = nextStep[x][y].x;
        nextY = nextStep[x][y].y;
        cout << nextX << " " << nextY << endl;
        x = nextX;
        y = nextY;
    }
}

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int f[SIZE][SIZE];
    Loc nextStep[SIZE][SIZE];
    init(f, m, n);

    if (obstacleGrid[m - 1][n - 1])
        f[m - 1][n - 1] = 0;
    if (obstacleGrid[0][0])
        return 0;

    DP(f, m, n, obstacleGrid, nextStep);
    if (f[0][0] != 0)
        printAPath(m, n, nextStep);
    return f[0][0];
}

int uniquePaths(int m, int n) {
    int f[SIZE][SIZE];
    init(f, m, n);

    for (int i = m - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            if (i == m - 1 && j == n - 1)
                continue;
            else {
                if (i + 1 <= m)
                    f[i][j] += f[i + 1][j];
                if (j + 1 <= n)
                    f[i][j] += f[i][j + 1];
            }
    return f[0][0];
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int m;
    int n;
    vector<vector<int> > obstacleGrid;
    fin >> m >> n;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int tmp;
            fin >> tmp;
            row.push_back(tmp);
        }
        obstacleGrid.push_back(row);
    }
    uniquePathsWithObstacles(obstacleGrid);
    //cout << uniquePaths(m, n) << endl;
    return 0;
}
