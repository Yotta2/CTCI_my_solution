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
#include <unordered_set>
#include <map>
#include <time.h>
#include <functional>
#include <queue>

#define EPS 1e-6
#define SIZE 110

using namespace std;

int findMaxSubseq(int arr[SIZE], int n) {
    int currSum = 0;
    int max = -INT_MAX;
    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        if (currSum > max)
            max = currSum;
        if (currSum < 0)
            currSum = 0;
    }
    return max;
}

void addUp(int arr[SIZE], int upperRow, int lowerRow, int matrix[SIZE][SIZE], int n) {
    for (int i = upperRow; i <= lowerRow; i++)
        for (int j = 0; j < n; j++)
            arr[j] += matrix[i][j];
}

int solve(int matrix[SIZE][SIZE], int n) {
    int ans = -INT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            int arr[SIZE];
            memset(arr, 0 , sizeof(arr));
            addUp(arr, i, j, matrix, n);
            int max = findMaxSubseq(arr, n);
            if (max > ans)
                ans = max;
        }
    return ans;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n;
    int matrix[SIZE][SIZE];
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    cout << solve(matrix, n) << endl;
    return 0;
}
