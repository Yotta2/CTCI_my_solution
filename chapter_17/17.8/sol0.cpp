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
    int subSums[n + 1]; //subSums[i] denotes the sum of all integer from 0..i
    memset(subSums, 0, sizeof(subSums));
    subSums[0] = subSums[0];
    for (int i = 1; i < n; i++)
        subSums[i] = subSums[i - 1] + nums[i];
    int max = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            int tmp;
            if (i != 0)
                tmp = subSums[j] - subSums[i - 1];
            else
                tmp = subSums[j];
            if (tmp > max)
                max = tmp;
        }
    return max;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int nums[] = {2, -8, 3, -2, 4, -10};
    int n = 6;
    cout << findLargestSubquence(nums, n) << endl;
}
