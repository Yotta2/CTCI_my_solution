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
#define SIZE 10000100

using namespace std;

void createMap(ifstream &fin, unordered_map<string, unordered_map<string, int> > &wordMap) {
    vector<string> words;
    string word;
    while (fin >> word) {
        words.push_back(word);
    }
    for (int i = 0; i < words.size(); i++) {
        if (wordMap.find(words[i]) == wordMap.end()) {
            unordered_map<string, int> wordToDistMap;
            wordMap[words[i]] = wordToDistMap;
        }
        for (int j = i; j < words.size(); j++) {
            if (wordMap[words[i]].find(words[j]) == wordMap[words[i]].end())
                wordMap[words[i]][words[j]] = j - i;
            else if (wordMap[words[i]][words[j]] > j - i)
                wordMap[words[i]][words[j]] = j - i;
        }
    }
}

//precondition: word1 and word2 both exist in the file
int findShortestDist(string word1, string word2, unordered_map<string, unordered_map<string, int> > &wordMap) {
    return wordMap[word1][word2];
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    unordered_map<string, unordered_map<string, int> > wordMap;
    createMap(fin, wordMap);
    string word1 = "Cloud";
    string word2 = "the";
    cout  << findShortestDist(word1, word2, wordMap) << endl;
    return 0;
}
