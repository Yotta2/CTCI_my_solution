#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;

void dfs(int matrix[10][10], bool visited[10], int currNode, int target, bool &found) {
    if (found)
        return;
    visited[currNode] = true;
    if (currNode == target) {
        found = true;
        return;
    }
    for (int i = 0; i < 10; i++)
        if (matrix[currNode][i] && !visited[i])
            dfs(matrix, visited, i, target, found);
}

bool isConnected(int matrix[10][10], int start, int end) {
    bool visited[10];
    memset(visited, 0, sizeof(visited));
    bool found = false;
    dfs(matrix, visited, start, end, found);
    return found;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int matrix[10][10];
    memset(matrix, 0, sizeof(matrix));
    matrix[0][7] = 1;
    matrix[1][3] = 1;
    matrix[1][8] = 1;
    matrix[2][4] = 1;
    matrix[2][5] = 1;
    matrix[3][2] = 1;
    matrix[4][6] = 1;
    matrix[5][7] = 1;
    matrix[6][7] = 1;

    if (isConnected(matrix, 1, 7))
        cout << "a route exists!" << endl;
    else
        cout << "no route" << endl;
    return 0;
}
