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

void swap(int &a, int &b) {
    b = a + b;
    a = b - a;
    b = b - a;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int a = 3;
    int b = 2;
    swap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}
