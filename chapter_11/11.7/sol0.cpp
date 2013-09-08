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

struct Person {
    int height;
    int weight;
    Person(int h, int w) : height(h), weight(w) {}
    Person() {}
};

bool cmp(const Person &a, const Person &b) {
    if (a.height != b.height)
        return a.height <= b.height;
    else
        return a.weight <= b.weight;
}

void init(int f[SIZE], int n) {
    for (int i = 0; i < n; i++)
        f[i] = 1;
}

int DP(vector<Person> &persons) {
    int n = persons.size();
    int f[SIZE];
    int ans = 0;
    init(f, n); // initialize all element to be 1;

    for (int i = 1; i < n; i++) {
        int max = 0;;
        for (int j = 0; j < i; j++)
            if (persons[i].height > persons[j].height && persons[i].weight > persons[j].weight && max < f[j])
                max = f[j];
        f[i] = max + 1;
        if (f[i] > ans)
            ans = f[i];
    }
    return ans;
}

//vector<Person> findLargestTower(vector<Person> &persons) {
int findLargestTower(vector<Person> &persons) {
    sort(persons.begin(), persons.end(), cmp);
    return DP(persons);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n;
    vector<Person> persons;
    fin >> n;
    for (int i = 0; i < n; i++) {
        int h, w;
        fin >> h >> w;
        Person person(h, w);
        persons.push_back(person);
    }
    cout << findLargestTower(persons) << endl;
    return 0;
}
