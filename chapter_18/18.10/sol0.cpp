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

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    queue<State> q;
    unordered_set<string> visitedWord;
    vector<vector<string>> ans;
    bool found = false;
    int minLen = INT_MAX;
    State state;
    state.word = start;
    state.path.push_back(start);
    visitedWord.insert(start);
    q.push(state);
    while (!q.empty()) {
        State currState = q.front();
        q.pop();
        for (int i = 0; i < currState.word.size(); i++)
            if (currState.word[i] != end[i]) {
                string newWord = currState.word;
                if (found && currState.path.size() >= minLen)
                    break;
                for (int j = 0; j < 26; j++) {
                    newWord[i] = 'a' + j;
                    State newState;
                    newState.word = newWord;
                    newState.path = currState.path;
                    newState.path.push_back(newWord);
                    if (newWord == end) {
                        if (found == false)
                            minLen = newState.path.size();
                        found = true;
                        ans.push_back(newState.path);
                    }
                    if (visitedWord.find(newWord) == visitedWord.end()) {
                        visitedWord.insert(newWord);
                        if (dict.find(newWord) != dict.end())
                            q.push(newState);
                    }
                }
            }
    }
    return ans;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
