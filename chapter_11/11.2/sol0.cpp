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

void groupAnagrams(vector<string> &strings) {
    unordered_map<string, vector<string> > hm;
    for (int i = 0; i < strings.size(); i++) {
        string sortedStr = strings[i];
        sort(sortedStr.begin(), sortedStr.end());
        if (hm.find(sortedStr) == hm.end()) {
            vector<string> strs;
            strs.push_back(sortedStr);
            hm[sortedStr] = strs;
        } else {
            hm[sortedStr].push_back(strings[i]);
        }
    }
    vector<string> result;
    for (unordered_map<string, vector<string> >::iterator itr = hm.begin(); itr != hm.end(); itr++) {
        vector<string> strs = (*itr).second;
        for (int j = 0; j < strs.size(); j++)
            result.push_back(strs[j]);
    }
    strings = result;
}

void output(vector<string> &strings) {
    for (int i = 0; i < strings.size(); i++)
        cout << strings[i] << endl;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n;
    vector<string> strings;
    fin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        fin >> str;
        strings.push_back(str);
    }

    groupAnagrams(strings);
    output(strings);
    return 0;
}
