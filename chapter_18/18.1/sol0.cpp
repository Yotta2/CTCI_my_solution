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

int add(int a, int b) {
    if (b == 0)
        return a;
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return add(sum, carry);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int a = -10;
    int b = 23;
    cout << add(a, b) << endl;
    return 0;
}
