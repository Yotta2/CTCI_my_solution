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

int rand5() {
    srand (time(NULL));
    return rand() % 5;
}

int rand7() {
    while (true) {
        int  x = rand5() * 5 + rand5();
        if (x < 21)
            return x % 7;
    }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    cout << rand7() << endl;
    return 0;
}
