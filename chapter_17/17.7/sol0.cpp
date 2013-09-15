#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>
#include <list>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <map>
#include <time.h>

#define EPS 1e-6
#define SIZE 300

using namespace std;

string getSubPhrase(int unit) {
    int count = 0;
    char tens[][10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty",
                    "Sixty", "Seventy", "eighty", "ninety"};
    char digits[][10] = {"", "One", "Two", "Three", "Four", "Five",
                        "Six", "Seven", "Eight", "Nine"};
    char teens[][10] = {"Teen", "Eleven", "Twelve", "Thirteen", "Fourteen",
                        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string subPhrase;
    //convert hundred place
    if (unit >= 100) {
        subPhrase += string() + digits[unit / 100] + " Hundred";
        unit %= 100;
    }

    //convert tens place
    if (unit >= 11 && unit <= 19) {
        subPhrase += string() + " " + teens[unit - 10];
        unit = 0;
    } else if (unit >= 20) {
        subPhrase += string() + " " + tens[unit / 10];
        unit %= 10;
    }

    //convert ones place
    if (unit > 0)
        subPhrase += string() + " " + digits[unit];

    return subPhrase;
}

string getEnglishPhrase(int num) {
    string englishPhrase;
    vector<string> bigs;
    bigs.push_back("");
    bigs.push_back("Thousand");
    bigs.push_back("Million");
    bigs.push_back("Billion");
    int count = 0;
    while (num != 0) {
        int unit = num - num / 1000 * 1000;
        string subPhrase = getSubPhrase(unit);
        if (!subPhrase.empty())
            englishPhrase = subPhrase + " " + bigs[count] + ", " + englishPhrase;
        count++;
        num /= 1000;
    }
    return englishPhrase;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int num = 1231313;
    cout << getEnglishPhrase(num) << endl;
    return 0;
}
