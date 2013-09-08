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

bool bsearch(vector<int> &arr, int target) {
    int i, j, m;
    i = 0;
    j = arr.size() - 1;

    while (i <= j) {
        m = (i + j) / 2;
        if (arr[m] == target)
            return true;
        if (arr[m] < target)
            i = m + 1;
        else
            j = m - 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int i, j, m;

    i = 0;
    j = matrix.size() - 1;
    if (matrix[i][0] > target)
        return false;
    while (j - i > 1) {
        m = (i + j) / 2;
        if (matrix[m][0] == target)
            return true;
        if (matrix[m][0] < target)
            i = m;
        else
            j = m - 1;
    }
    if (i + 1 < matrix.size() && matrix[i + 1][0] <= target)
        return bsearch(matrix[i + 1], target);
    else
        return bsearch(matrix[i], target);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    vector<vector<int> > matrix;
    int m, n, target;
    fin >> m >> n >> target;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int num;
            fin >> num;
            row.push_back(num);
        }
        matrix.push_back(row);
    }
    cout << searchMatrix(matrix, target) << endl;
    return 0;
}
