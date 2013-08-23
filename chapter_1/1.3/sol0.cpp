#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

void getCount(string &str, int count[260]) {
    for (int i = 0; i < str.length(); i++)
        count[str[i]]++;
}

bool isAnagram(string &str1, string &str2) {
    int count1[260];
    int count2[260];

    memset(count1, 0, sizeof(count1));
    memset(count2, 0, sizeof(count2));
    getCount(str1, count1);
    getCount(str2, count2);
    for (int i = 0; i < 256; i++)
        if (count1[i] != count2[i])
            return false;
    return true;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string str1;
    string str2;
    fin >> str1;
    fin >> str2;
    if (isAnagram(str1, str2))
        fout << "Yes" << endl;
    else
        fout << "No" << endl;
    return 0;
}
