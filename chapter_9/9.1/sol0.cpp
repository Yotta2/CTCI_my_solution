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

using namespace std;

int climbStairs(int n) {
    vector<int> f(n + 1, 0);
    f[1] = 1;
    f[2] = 2;
    f[3] = f[2] + f[1] + 1;
    for (int i = 4; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    //for (int i = 3; i <= n; i++)
    //    f[i] = f[i - 1] + f[i - 2];
    return f[n];
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n = 10;
    cout << climbStairs(n) << endl;
    return 0;
}
