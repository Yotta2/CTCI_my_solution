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

void dfs(string soFar, string rest) {
    if (rest.size() == 0) {
        cout << soFar << endl;
        return;
    }
    for (int i = 0; i < rest.size(); i++) {
        soFar += rest[i];
        //string restTmp = rest.substr(0, i) + rest.substr(i + 1);
        string restTmp = rest;
        restTmp.erase(i, 1);
        dfs(soFar, restTmp);
        soFar.pop_back();
    }
}

void permutation(string &str) {
    dfs("", str);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string str = "abcd";
    permutation(str);
    return 0;
}
