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

int findPivot(int A[], int n) {
    int i, j, m;
    i = 0;
    j = n - 1;
    while (true) {
        if (i + 1 >= j)
            return i;
        m = (i + j) / 2;
        if (A[i] <= A[m])
            i = m;
        else
            j = m;
    }
}

// binary search an increasing array from index i to j
int bsearch(int A[], int i, int j, int target) {
    int m;

    while (i <= j) {
        m = (i + j) / 2;
        if (A[m] == target)
            return m;
        if (A[m] < target)
            i = m + 1;
        else
            j = m - 1;
    }
    return -1;
}

int search(int A[], int n, int target) {
    int pivot = findPivot(A, n);
    int index;
    index = bsearch(A, 0, pivot, target);
    if (index != -1)
        return index;
    index = bsearch(A, pivot + 1, n - 1, target);
    return index;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
