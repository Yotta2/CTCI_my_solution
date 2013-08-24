#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

struct stackFrame {
    int begin, end;
    char src, tmp, dst;
    stackFrame(int b, int e, char s, char t, char d) : begin(b), end(e), src(s), tmp(t), dst(d) {}
};

//stack/iterative version
void hanoi(int n) {
    stack<stackFrame> s;
    stackFrame sf(1, n, 'A', 'B', 'C');
    s.push(sf);
    while (!s.empty()) {
        stackFrame sfTop = s.top();
        s.pop();
        if (sfTop.begin == sfTop.end)
            cout << "move disk " << sfTop.begin << " from " << sfTop.src << " to " << sfTop.dst << endl;
        else {
            stackFrame newFrame3(sfTop.begin, sfTop.end - 1, sfTop.tmp, sfTop.src, sfTop.dst);
            s.push(newFrame3);
            stackFrame newFrame2(sfTop.end, sfTop.end, sfTop.src, sfTop.tmp, sfTop.dst);
            s.push(newFrame2);
            stackFrame newFrame1(sfTop.begin, sfTop.end - 1, sfTop.src, sfTop.dst, sfTop.tmp);
            s.push(newFrame1);
        }
    }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n = 10;
    hanoi(n);
    return 0;
}
