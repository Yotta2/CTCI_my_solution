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

string fracToBinary(double d) {
    string res = ".";
    while (d > 0) {
        d *= 2;
        if (d >= 1) {
            res += '1';
            d--;
        } else {
            res += '0';
        }
        if (res.length() >= 32)
            return "ERROR";
    }
    return res;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    double d = 0.125;
    cout << fracToBinary(d) << endl;
    return 0;
}
