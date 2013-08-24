#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// simulate insertion sort
void sortStack(stack<int> &s) {
    stack<int> tmp;
    while (!s.empty()) {
        tmp.push(s.top());
        s.pop();
    }
    while (!tmp.empty()) {
        int insert = tmp.top();
        tmp.pop();
        while (!s.empty() && s.top() > insert) {
            tmp.push(s.top());
            s.pop();
        }
        s.push(insert);
    }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int arr[] = {3, 5, 1, 10, 2, 33};
    stack<int> s;
    for (int i = 0; i < 6; i++)
        s.push(arr[i]);
    sortStack(s);
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
