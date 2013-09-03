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

bool isOutOfBound(int x, int y, int m, int n) {
    return x < 0 || x >= m || y < 0 || y >= n;
}

bool isLegal(int x, int y, vector<string> &board) {
    int dir[3][2] = {{-1, -1}, {-1, 0}, {-1, 1}};
    int xNext = x;
    int yNext = y;

    // \ | / directions
    for (int i = 0; i < 3; i++) {
        xNext = x;
        yNext = y;
        while (true) {
            xNext += dir[i][0];
            yNext += dir[i][1];
            if (isOutOfBound(xNext, yNext, board.size(), board[0].size()))
                break;
            if (board[xNext][yNext] == 'Q')
                return false;
        }
    }
    return true;
}

void dfs(int i, int n, vector<string> &board, vector<vector<string> > &ans) {
    if (i == n) {
        ans.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++)
        if (isLegal(i, j, board)) {
            board[i][j] = 'Q';
            dfs(i + 1, n, board, ans);
            board[i][j] = '.';
        }
}

vector<vector<string> > solveNQueens(int n) {
    vector<string> board;
    vector<vector<string> > ans;
    string row;
    row.assign(n, '.');
    for (int i = 0; i < n; i++) {
        board.push_back(row);
        //cout << row << endl;
    }
    dfs(0, n, board, ans);

    return ans;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    vector<vector<string> > ans = solveNQueens(8);
    cout << ans.size() << endl;
    return 0;
}
