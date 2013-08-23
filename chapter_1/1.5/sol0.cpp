#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

string toString(int num) {
    string result;
    while (true) {
        if (num == 0)
            break;
        char ch = '0' + num % 10;
        result = ch + result;
        num /= 10;
    }
    return result;
}

string compress(string &str) {
    int i = 0;
    string result;
    while (true) {
        if (i >= str.length())
            break;
        char curr = str[i];
        int count = 1;
        result += curr;
        while (i + 1 < str.length() && str[i] == str[i + 1]) {
            i++;
            count++;
        }
        string countStr = toString(count);
        result += countStr;
        i++;
    }
    if (result.length() < str.length())
        return result;
    else
        return str;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string str = "abcd";
    cout << "After compression: " << compress(str) << endl;
    return 0;
}
