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

void countHits(string &solution, string &guess, int &hits, int & pseudoHits) {
    int solutionCount[4] = {0, 0, 0, 0}; //color counts, excluding hit color
    int guessCount[4] = {0, 0, 0, 0};

    hits = pseudoHits = 0;
    for (int i = 0; i < 4; i++)
        if (solution[i] == guess[i])
            hits++;
        else {
            switch (solution[i]) {
                case 'R':
                    solutionCount[0]++;
                    break;
                case 'Y':
                    solutionCount[1]++;
                    break;
                case 'G':
                    solutionCount[2]++;
                    break;
                case 'B':
                    solutionCount[3]++;
                    break;
            }
            switch (guess[i]) {
                case 'R':
                    guessCount[0]++;
                    break;
                case 'Y':
                    guessCount[1]++;
                    break;
                case 'G':
                    guessCount[2]++;
                    break;
                case 'B':
                    guessCount[3]++;
                    break;
            }
        }
    for (int i = 0; i < 4; i++)
        pseudoHits += min(solutionCount[i], guessCount[i]);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string solution = "RGBY";
    string guess = "BBBB";
    int hits = 0;
    int pseudoHits = 0;
    countHits(solution, guess, hits, pseudoHits);
    cout << "the number of hits: " << hits << endl;
    cout << "the number of pseudo-hits: " << pseudoHits << endl;
    return 0;
}
