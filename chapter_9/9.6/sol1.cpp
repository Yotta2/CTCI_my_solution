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

void dfs(int lRem, int rRem, string soFar, vector<string> &ans) {
    if (lRem > rRem)
        return;
    if (lRem == 0 && rRem == 0) {
        ans.push_back(soFar);
        return;
    }
    if (lRem > 0) {
        soFar += "(";
        lRem--;
        dfs(lRem, rRem, soFar, ans);
        lRem++;
        soFar.pop_back();
    }

    if (rRem > 0) {
        soFar += ")";
        rRem--;
        dfs(lRem, rRem, soFar, ans);
        rRem++;
        soFar.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    dfs(n, n, "", ans);
    return ans;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n = 15;
    vector<string> ans = generateParenthesis(n);
    //for (int i = 0; i < ans.size(); i++)
    //    cout << ans[i] << endl;
    cout << ans.size() << endl;
    return 0;
}
