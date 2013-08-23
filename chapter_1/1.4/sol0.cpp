#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

void replace(string &str) {
    string result;
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ' ')
            result += "%20";
        else
            result += str[i];
    str = result;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string str = "Mr John Smith";
    //fin >> str;
    replace(str);
    cout << str << endl;
    return 0;
}
