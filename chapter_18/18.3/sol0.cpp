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

void randPick(int arr[], int n, int m) {
    srand(time(NULL));
    for (int i = n - 1; i >= n - m; i--) {
        int index = rand() % (i + 1);
        swap(arr[index], arr[i]);
        cout << arr[i] << endl;
    }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int m = 3;
    randPick(arr, n, m);
    return 0;
}
