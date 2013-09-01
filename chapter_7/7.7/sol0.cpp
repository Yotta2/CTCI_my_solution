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
#include <queue>

#define EPSILON 1e-6

using namespace std;

int findKth(int k) {
    queue<int> q3;
    queue<int> q5;
    queue<int> q7;
    int count = 0;

    q3.push(3);
    q5.push(5);
    q7.push(7);
    while (true) {
        int num = min(q3.front(), min(q5.front(), q7.front()));
        if (num == q3.front()) {
            q3.pop();
            q3.push(3 * num);
            q5.push(5 * num);
            q7.push(7 * num);
        }
        if (num == q5.front()) {
            q5.pop();
            q5.push(5 * num);
            q7.push(7 * num);
        }
        if (num == q7.front()) {
            q7.pop();
            q7.push(7 * num);
        }
        count++;
        if (k == count)
            return num;
    }

}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int k = 1000;
    cout << findKth(k) << endl;
    return 0;
}
