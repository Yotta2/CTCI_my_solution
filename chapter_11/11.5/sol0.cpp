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

int bsearch(vector<string> &strings, int i, int j, string target) {
    if (i > j)
        return -1;
    int m = (i + j) / 2;
    if (strings[m] == target)
        return m;
    if (strings[m] == "") {
        int index = bsearch(strings, i, m - 1, target);
        if (index != -1)
            return index;
        return bsearch(strings, m + 1, j, target);
    } else if (strcmp(target.c_str(), strings[m].c_str()) < 0) {
        return bsearch(strings, i, m - 1, target);
    } else {
        return bsearch(strings, m + 1, j, target);
    }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    vector<string> strings;
    strings.push_back("at");
    strings.push_back("");
    strings.push_back("");
    strings.push_back("");
    strings.push_back("ball");
    strings.push_back("");
    strings.push_back("");
    strings.push_back("car");
    strings.push_back("");
    strings.push_back("");
    strings.push_back("dad");
    strings.push_back("");
    strings.push_back("");
    strings.push_back("");
    string target = "ball";
    cout << bsearch(strings, 0, strings.size() - 1, target) << endl;
    return 0;
}
