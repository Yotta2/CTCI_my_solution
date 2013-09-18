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
#include <unordered_set>
#include <map>
#include <time.h>

#define EPS 1e-6
#define SIZE 10000100

using namespace std;

bool canBeMadeOf(string word, unordered_set<string> &wordSet, bool subStr) {
    string prefix;
    if (subStr && wordSet.find(word) != wordSet.end())
        return true;
    for (int i = 0; i < word.size() - 1; i++) {
        prefix += word[i];
        if (wordSet.find(prefix) != wordSet.end() && canBeMadeOf(word.substr(i + 1), wordSet, true))
            return true;
    }
    return false;
}

string findLongestWord(vector<string> &words) {
    int maxLen = 0;
    string ans;
    unordered_set<string> wordSet;
    for (int i = 0; i < words.size(); i++)
        wordSet.insert(words[i]);
    for (int i = 0; i < words.size(); i++)
        if (canBeMadeOf(words[i], wordSet, false)) {
            if (maxLen < words[i].size()) {
                ans = words[i];
                maxLen = words[i].size();
            }
        }
    return ans;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    vector<string> words;
    string word;
    while (fin >> word) {
        words.push_back(word);
        //cout << word << endl;
    }
    cout << findLongestWord(words) << endl;
    return 0;
}
