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

unordered_map<string, int> generateMap(ifstream &fin) {
    unordered_map<string, int> wordToCountMap;

    string word;
    while (fin >> word) {
        if (wordToCountMap.find(word) != wordToCountMap.end())
            wordToCountMap[word]++;
        else
            wordToCountMap[word] = 1;
    }

    return wordToCountMap;
}

int getFrequency(unordered_map<string, int> &wordToCountMap, string word) {
    if (wordToCountMap.find(word) != wordToCountMap.end())
        return wordToCountMap[word];
    else
        return 0;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    unordered_map<string, int> wordToCountMap = generateMap(fin);
    string word = "afjsf";
    cout << getFrequency(wordToCountMap, word) << endl;
}
