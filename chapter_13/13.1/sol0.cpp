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
#define NULL 0

using namespace std;

//if k is not very big
void printLastKLine(ifstream &fin, int k) {
    vector<string> lines;
    int fileLinesCount = 0;
    lines.assign(k, "");

    int i = 0;
    string line;
    while (true) {
        getline(fin, line);
        if (fin.eof())
            break;
        lines[i] = line;
        fileLinesCount++;
        i++;
        i %= k;
    }

    // if there are less than k lines in the file, output all lines
    if (fileLinesCount < k) {
        k = fileLinesCount;
        i = 0;
    }

    int count = 0;
    while (count < k) {
        cout << lines[i] << endl;
        count++;
        i++;
        i %= k;
    }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int k = 2;
    printLastKLine(fin, k);
    return 0;
}
