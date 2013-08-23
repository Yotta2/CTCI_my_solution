#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

template<typename T>
void _swap(T &a, T &b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
        swap(str[i], str[len - i - 1]);
        //_swap(str[i], str[len - i - 1]);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    char str[] = "abcdefg";
    reverse(str);
    cout << str << endl;
    return 0;
}
