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

class DataStore {
public:
    void insert(int num) {
        if (maxHeap.size() <= minHeap.size()) {  // need to insert to maxHeap
            if (maxHeap.size() == 0) {
                maxHeap.push(num);
            } else if (minHeap.top() < num) {
                int tmp = minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(tmp);
            } else {
                maxHeap.push(num);
            }
        } else {    // need to insert to minHeap
            if (maxHeap.top() > num) {
                int tmp = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(tmp);
            } else {
                minHeap.push(num);
            }
        }

    }

    double getMedian() {
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else
            return ((double)maxHeap.top() + minHeap.top()) / 2;
    }

private:
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;
};

void printAllNum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int num : nums)
        cout << num << ", ";
    cout << endl;
}
int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    DataStore ds;
    vector<int> nums;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int num = rand() % 100;
        nums.push_back(num);
        printAllNum(nums);
        ds.insert(num);
        if (i % 3 == 0)
            cout << "Median: " << ds.getMedian() << endl;
    }
    return 0;
}
