#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

// not using additional data structure, and assuming the string only contains a-z

bool allUnique(const string &str) {
    if (str.length() > 256)
        return false;
    int checker = 0;

    for (int i = 0; i < str.length(); i++) {
        int shift = str[i] - 'a';
        if ((1 << shift) & checker)
            return false;
        checker |= 1 << shift;
    }
    return true;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string str;
    fin >> str;
    if (allUnique(str))
        fout << "Yes" << endl;
    else
        fout << "No" << endl;
    return 0;
}
