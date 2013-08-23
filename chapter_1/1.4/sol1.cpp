#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

//cannot use extra space
void replace(char *str) {
    int spaceCount = 0;
    int len = strlen(str);
    int newLen;
    for (int i = 0; i < len; i++)
        if (str[i] == ' ')
            spaceCount++;
    newLen = len + 2 * spaceCount;
    str[newLen] = '\0';
    for (int i = len - 1; i >= 0; i--)
        if (str[i] == ' ') {
            str[newLen - 1] = '0';
            str[newLen - 2] = '2';
            str[newLen - 3] = '%';
            newLen -= 3;
        } else {
            str[newLen - 1] = str[i];
            newLen--;
        }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    char str[256] = "Mr John Smith";
    //fin >> str;
    replace(str);
    cout << str << endl;
    return 0;
}
