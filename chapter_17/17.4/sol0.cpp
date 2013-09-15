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

int max1(int a, int b) {
    int arr[2] = {a, b};
    int d = a - b;
    int sign = (d >> 31) & 1;
    return arr[sign];
}

int max2(int a, int b) {
    int d = a - b;
    int sign = (d >> 31) & 1;
    return a - sign * d;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int a = 102342;
    int b = 110;
    cout << max1(a, b) << endl;
    cout << max2(a, b) << endl;
    return 0;
}
