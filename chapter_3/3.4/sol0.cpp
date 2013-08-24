#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

//recursive version
void hanoi(int n, char src, char tmp, char dst) {
    if (n == 1) {
        cout << "move disk " << n << " from " << src << " to " << dst << endl;
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    cout << "move disk " << n << " from " << src << " to " << dst << endl;
    hanoi(n - 1, tmp, src, dst);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n = 3;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
