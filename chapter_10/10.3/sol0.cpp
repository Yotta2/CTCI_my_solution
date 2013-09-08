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
#define SIZE1 5368//70920
#define SIZE2 4000000000

using namespace std;

void createFile() {
    ofstream fout("sol.in");
    int notContainedNum = 234234;
    for (unsigned i = 0; i < SIZE2; i++)
        if (i != notContainedNum)
            fout << i << " ";

}

void setAllBit(unsigned *bits) {
    ifstream fin("sol.in");
    while (true) {
        if (fin.eof())
            break;
        int num;
        fin >> num;
        int index = num / 8;
        int remainder = num % 8;
        bits[index] |= (1 << remainder);
    }
}

unsigned findLackNumber() {
    unsigned *bits = new unsigned[SIZE1];
    memset(bits, 0, sizeof(bits));
    int num;
    setAllBit(bits);
    for (int i = 0; i < SIZE1; i++)
        if ((bits[i] ^ 0xffffffff) != 0) {
            for (int j = 0; j < 32; j++)
                if ((bits[i] & (1 < j)) == 0)
                    return i * 8 + j;
        }
}

int main() {
    //ofstream fout("sol.out");
    //ifstream fin("sol.in");

    createFile();
    //cout << findLackNumber() << endl;
    return 0;
}
