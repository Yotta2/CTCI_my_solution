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

using namespace std;

int nextSmallest(int num) {
    if (num == INT_MAX) //if num is INT_MAX return itself
        return num;
    int mask = 1;
    int i = 0;
    while (i < 31) {
        if ((mask & num) != 0)
            break;
        i++;
        mask <<= 1;
    }
    num = num & (~mask);
    mask <<= 1;
    i++;
    while (i < 31) {
        if ((num & mask) == 0)
            break;
        i++;
        mask <<= 1;
    }
    num |= mask;
    return num;
}

bool test(int num) {
    int mask = 1;
    for (int i = 0; i < 30; i++) {
        if (mask - 1 == num)
            return true;
        mask <<= 1;
    }
    return false;
}

int nextLargest(int num) {
    //if num is the smallest number that has the same amount of digits, return itself
    if (test(num))
        return num;
    int mask1 = 1;
    int mask2;
    int i = 0;
    while (i < 31) {
        if ((mask1 & num) == 0)
            break;
        i++;
        mask1 <<= 1;
    }
    mask2 = mask1;
    num |= mask1;
    mask2 <<= 1;
    while (i < 31) {
        if ((mask2 & num) != 0)
            break;
        i++;
        mask2 <<= 1;
    }
    num = num & (~mask2);
    return num;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int num = 500;
    cout << "next smallest: " << nextSmallest(num) << endl;
    cout << "next largest: " << nextLargest(num) << endl;
    return 0;
}
