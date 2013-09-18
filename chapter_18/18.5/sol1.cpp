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

//precondition: word1 and word2 both exist in the file
int findShortestDist(string word1, string word2, ifstream &fin) {
    int word1LastPos = -1;
    int word2LastPos = -1;
    int pos = 0;
    int min = INT_MAX;
    string word;

    while (fin >> word) {
        if (word == word1)
            word1LastPos = pos;
        if (word == word2)
            word2LastPos = pos;
        if (word1LastPos != -1 && word2LastPos != -1 && min > abs(word1LastPos - word2LastPos))
            min = abs(word1LastPos - word2LastPos);
        pos++;
    }
    return min;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string word1 = "Cloud";
    string word2 = "the";
    cout  << findShortestDist(word1, word2, fin) << endl;
    return 0;
}
