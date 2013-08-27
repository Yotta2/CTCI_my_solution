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

int bitSwapRequired(int A, int B) {
    int tmp = A ^ B;
    int count = 0;
    while (tmp != 0) {
        if (tmp & 1)
            count++;
        tmp >>= 1;
    }
    return count;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int A = 31;
    int B = 14;
    cout << bitSwapRequired(A, B) << endl;
    return 0;
}
