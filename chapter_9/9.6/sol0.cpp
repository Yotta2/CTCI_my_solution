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

void put(vector<string> &tmp, string str, unordered_map<string, bool> &flag) {
    if (flag.find(str) == flag.end()) {
        tmp.push_back(str);
        flag[str] = true;
    }
}

vector<string> generateParenthesis(int n) {
    vector<vector<string> > cache;
    vector<string> tmp;
    tmp.push_back("");
    cache.push_back(tmp); // n == 0
    tmp.clear();
    tmp.push_back("()");
    cache.push_back(tmp); // n == 1
    tmp.clear();
    tmp.push_back("()()");
    tmp.push_back("(())");
    cache.push_back(tmp); // n == 2
    for (int i = 3; i <= n; i++) {
        tmp.clear();
        unordered_map<string, bool> flag;
        for (int left = i; left >= 1; left--) {
            int right = i - left;
            if(left == i) {
                for (int j = 0; j < cache[left - 1].size(); j++) {
                    string str = "(" + cache[left - 1][j] + ")";
                    put(tmp, str, flag);
                }
            } else {
                for (int j = 0; j  < cache[left].size(); j++)
                    for (int k = 0; k < cache[right].size(); k++) {
                        string str = cache[left][j] + cache[right][k];
                        put(tmp, str, flag);
                    }
            }
        }
        cache.push_back(tmp);
    }
    return cache[n];
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
