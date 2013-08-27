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

using namespace std;


bool fetchBit(int arr[], int i, int j) {
    return ((arr[i] & (1 << j)) != 0);
}

int fetchNum(int arr[], int i) {
    int num = 0;
    for (int j = 0; j < 32; j++)
        if (fetchBit(arr, i, j))
            num |= (1 << j);
    return num;
}

int findMissingInt(int arr[]) {
    if (fetchBit(arr, 0, 0))
        return 0;
    for (int i = 1; i < 9; i++) {
        bool prevLastBit = fetchBit(arr, i - 1, 0);
        bool currLastBit = fetchBit(arr, i, 0);
        if (prevLastBit == currLastBit)
            return fetchNum(arr, i) - 1;
    }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int arr[] = {0, 1, 2, 3, 4, 5, 7, 8, 9};
    cout << findMissingInt(arr) << endl;
    return 0;
}
