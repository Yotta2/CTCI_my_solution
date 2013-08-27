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
    int mask0 = 1;
    int mask1 = 1 << 1;
    int mask2 = mask0 | mask1;
    for (int i = 0; i < 14; i++) {
        int tmp0 = num & mask0;
        int tmp1 = num & mask1;
        if (tmp0 == 0 && tmp1 == 0 || tmp0 != 0 && tmp1 != 0);
        else num ^= mask2;
        mask0 <<= 2;
        mask1 <<= 2;
        mask2 <<= 2;
    }
    return num;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int num = 500;
    cout << swapBits(num) << endl;
    return 0;
}
