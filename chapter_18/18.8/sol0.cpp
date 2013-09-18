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

//return the starting index of the substring word in s
//return -1, if word is not in s
int searchForOcurrence(string s, string word) {
    for (int i = 0; i < s.size(); i++)
        if (s.substr(i, word.size()) == word)
            return i;
    return -1;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string s = "catbananadognanawalkwalkerdogwalker";
    vector<string> words;
    string word;
    while (fin >> word) {
        words.push_back(word);
        //cout << word << endl;
    }
    for (string word : words)
        cout << searchForOcurrence(s, word) << endl;
    return 0;
}
