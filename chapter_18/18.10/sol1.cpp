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
#include <functional>
#include <queue>

#define EPS 1e-6
#define SIZE 10000100

using namespace std;

struct State {
    string word;
    vector<string> path;
};

int ladderLength(string start, string end, unordered_set<string> &dict) {
    queue<State> q;
    unordered_set<string> visitedWord;
    State state;
    state.word = start;
    state.path.push_back(start);
    visitedWord.insert(start);
    q.push(state);
    while (!q.empty()) {
        State currState = q.front();
        q.pop();
        for (int i = 0; i < currState.word.size(); i++) {
            string newWord = currState.word;
            for (int j = 0; j < 26; j++) {
                newWord[i] = 'a' + j;
                if (newWord == end)
                    return currState.path.size() + 1;
                if (visitedWord.find(newWord) == visitedWord.end() && dict.find(newWord) != dict.end()) {
                    visitedWord.insert(newWord);
                    State newState;
                    newState.word = newWord;
                    newState.path = currState.path;
                    newState.path.push_back(newWord);
                    q.push(newState);
                }
            }
        }
    }
    return 0;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
