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

void dfs(vector<int> &S, int i, vector<int> &soFar, vector<vector<int> > &ans) {
    if (i == S.size()) {
        ans.push_back(soFar);
        return;
    }
    soFar.push_back(S[i]);
    dfs(S, i + 1, soFar, ans);
    soFar.pop_back();
    dfs(S, i + 1, soFar, ans);
}

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > ans;
    vector<int> soFar;
    sort(S.begin(), S.end());
    dfs(S, 0, soFar, ans);
    return ans;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
