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

using namespace std;

void dfs(vector<vector<int> > &matrix, int x, int y, int originalColor, int color) {
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (int i = 0; i < 4; i++) {
        int xNext = x + dir[i][0];
        int yNext = y + dir[i][1];
        if (xNext < 0 || xNext >= matrix.size() || yNext < 0 || yNext >= matrix[0].size())
            continue;
        if (matrix[xNext][yNext] == originalColor) {
            matrix[xNext][yNext] = color;
            dfs(matrix, xNext, yNext, originalColor, color);
        }
    }
}

void paintFill(vector<vector<int> > &matrix, int x, int y, int color) {
    int originalColor = matrix[x][y];
    if (originalColor == color)
        return;
    dfs(matrix, x, y, originalColor, color);
}

void printMatrix(vector<vector<int> > &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int m = 10;
    int n = 10;
    vector<vector<int> > matrix;
    /* initialize random seed: */
    srand (time(NULL));
    for (int i = 0; i < m; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            int color = rand() % 2;
            tmp.push_back(color);
        }
        matrix.push_back(tmp);
    }
    int x = rand() % m;
    int y = rand() % n;
    int color = rand() % 2;
    printMatrix(matrix);
    cout << "original matrix:" << endl;
    cout << "Paint point : x = " << x << " y = " << y << endl;
    cout << "Paint color : " << color << endl;
    paintFill(matrix, x, y, color);
    cout << "After painting:" << endl;
    printMatrix(matrix);
    return 0;
}
