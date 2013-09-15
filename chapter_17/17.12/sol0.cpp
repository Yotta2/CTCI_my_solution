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

vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> matchnumToIndexMap;
    vector<int> ans;
    for (int i = 0; i < numbers.size(); i++)
        if (matchnumToIndexMap.find(numbers[i]) != matchnumToIndexMap.end()) {
            ans.push_back(matchnumToIndexMap[numbers[i]] + 1);
            ans.push_back(i + 1);
            return ans;
        } else {
            matchnumToIndexMap[target - numbers[i]] = i;
        }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
