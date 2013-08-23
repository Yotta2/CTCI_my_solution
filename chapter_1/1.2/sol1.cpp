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
    char *end = str;
    if (*str == NULL)
        return;
    else {
        while (*end != NULL)
            end++;
    }
    end--;
    while (str < end) {
        swap(*str, *end);
        str++;
        end--;
    }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    char str[] = "a&(^(sdf";
    reverse(str);
    cout << str << endl;
    return 0;
}
