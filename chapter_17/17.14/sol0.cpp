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

vector<int> DP(string str, unordered_map<string, bool> &dict) {
    vector<int> f;
    vector<int> wordendIndex;
    f.assign(str.size() + 1, 0);
    wordendIndex.assign(str.size() + 1, 0);
    wordendIndex[str.size()] = -1;
    for (int i = str.size() - 1; i >= 0; i--) {
        int min = INT_MAX;
        int endIndex;
        for (int j = i; j < str.size(); j++) {
            int tmp = f[j + 1];
            if (dict.find(str.substr(i, j - i + 1)) == dict.end())
                tmp += j - i + 1;
            if (tmp <= min) {
                min = tmp;
                endIndex = j;
            }
        }
        f[i] = min;
        wordendIndex[i] = endIndex;
    }
    return wordendIndex;
}

string unconcatenateString(string str, unordered_map<string, bool> &dict) {
    vector<int> wordendIndex = DP(str, dict);
    int start = 0;
    int end = wordendIndex[start];
    string res;
    while (end != -1) {
        res += str.substr(start, end - start + 1) + " ";
        start = end + 1;
        end = wordendIndex[start];
    }
    res.erase(res.size() - 1, 1);
    return res;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    unordered_map<string, bool> dict;
    string word;
    while (fin >> word) {
        dict[word] = true;
    }
    string str = "jesslookedjustliketimherbrother";
    cout << unconcatenateString(str, dict) << endl;
    return 0;
}
