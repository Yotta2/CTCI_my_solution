#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

//not using additional data structure

bool allUnique(const string &str) {
    for (int i = 0; i < str.length(); i++)
        for (int j = i + 1; j < str.length(); j++)
            if (str[i] == str[j])
                return false;
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
