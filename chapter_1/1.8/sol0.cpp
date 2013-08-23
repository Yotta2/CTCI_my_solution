#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#define M 3
#define N 3

using namespace std;

bool isSubstring(string s1, string s2){
    return (s1.find(s2) != string::npos);
}

bool isRotation(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;
    return isSubstring(str1 + str1, str2);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string str1 = "waterbottle";
    string str2 = "erbottlewat";

    if (isRotation(str1, str2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
