#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

bool allUnique(const string &str) {
    if (str.length() > 256)
        return false;

    bool flags[260];
    memset(flags, 0, sizeof(flags));
    for (int i = 0; i < str.length(); i++)
        if (flags[str[i]])
            return false;
        else
            flags[str[i]] = true;
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
