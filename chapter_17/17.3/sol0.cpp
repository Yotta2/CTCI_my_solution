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

int computeTrailingZero(int n) {
    int count = 0; //count the number of 5 in the product
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        while (true) {
            if (tmp % 5 != 0)
                break;
            tmp /= 5;
            count++;
        }
    }
    return count;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n = 25;
    cout << computeTrailingZero(n) << endl;
    return 0;
}
