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
#define MIN(x, y) (x < y ? x : y)
#define ll long long

using namespace std;

int findMagicIndex(vector<int> &arr, int i, int j) {
    if (i > j)
        return -1;
    int m = (i + j) / 2;
    if (arr[m] == m)
        return m;
    if (arr[m] > m)
        return findMagicIndex(arr, i, m - 1);
    else
        return findMagicIndex(arr, m + 1, j);
}

int findMagicIndexWithDuplicate(vector<int> &arr, int i, int j) {
    if (i > j)
        return -1;
    int m = (i + j) / 2;
    if (arr[m] == m)
        return m;

    int index = findMagicIndexWithDuplicate(arr, i, min(m - 1, arr[m]));
    if (index != -1)
        return index;
    index = findMagicIndexWithDuplicate(arr, max(m + 1, arr[m]), j);
    return index;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n;
    fin >> n;
    vector<int> arr;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        fin >> arr[i];
    //cout << findMagicIndex(arr, 0, n - 1) << endl;
    cout << findMagicIndexWithDuplicate(arr, 0, n - 1) << endl;
    return 0;
}
