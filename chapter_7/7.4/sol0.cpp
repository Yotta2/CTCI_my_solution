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

int _negate(int x) {
    if (x == 0)
        return x;
    int d = x > 0 ? -1 : 1;
    int res = 0;
    while (true) {
        res += d;
        x += d;
        if (x == 0)
            break;
    }
    return res;
}

int subtract(int a, int b) {
    return a + _negate(b);
}

int multiply(int a, int b) {
    if (a < b)
        return multiply(b, a);
    int sum = 0;
    bool flag = false; // if flag == true, we need to negate sum
    if (b < 0) {
        flag = true;
        b = _negate(b);
    }
    for (int i = 0; i < b; i++)
        sum += a;
    if (flag)
        sum = _negate(sum);
    return sum;
}

int abs(int x) {
    if (x >= 0)
        return x;
    else
        return _negate(x);
}

int divide(int a, int b) {
    if (b == 0)
        throw "divide error: a / 0";
    int count = 0;
    int sign;
    if (a > 0 && b > 0 || a < 0 && b < 0)
        sign = 1;
    else
        sign = -1;
    a = abs(a);
    b = abs(b);
    while (true) {
        a = subtract(a, b);
        count++;
        if (a < 0)
            break;
    }
    count--;
    if (sign == -1)
        count = _negate(count);
    return count;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int a = -65536;
    int b = -2;
    cout << a << " - " << b << " = " << subtract(a, b) << endl;
    cout << a << " * " << b << " = " <<  multiply(a, b) << endl;
    cout << a << " / " << b << " = " <<  divide(a, b) << endl;
    return 0;
}
