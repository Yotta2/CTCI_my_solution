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

int swapBits(int num) {
    return ((num & 0xAAAAAAAA) >> 1) | ((num & 0x55555555) << 1);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int num = 2342;
    cout << swapBits(num) << endl;
    return 0;
}
