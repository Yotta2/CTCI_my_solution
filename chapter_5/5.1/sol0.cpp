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

int insert(int N, int M, int i, int j) {
    int mask = (1 << (j - i + 1)) - 1;
    mask <<= i;
    mask = ~mask;
    N &= mask;
    N |= M << i;
    return N;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int N = 1024;
    int M = 19;
    cout << insert(N, M, 2, 6) << endl;
    return 0;
}
