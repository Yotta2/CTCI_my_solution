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

int findLargestSubquence(int nums[], int n) {
    int currSum = 0;
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += nums[i];
        if (currSum > maxSum)
            maxSum = currSum;
        else if (currSum < 0)
            currSum = 0;
    }
    return maxSum;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int nums[] = {2, -8, 3, -2, 4, -10};
    int n = 6;
    cout << findLargestSubquence(nums, n) << endl;
}
