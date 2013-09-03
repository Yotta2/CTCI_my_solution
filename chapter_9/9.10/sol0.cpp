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
#define SIZE 5

using namespace std;

struct Box {
    int w, h, d;
    Box(int _w, int _h, int _d) : w(_w), h(_h), d(_d) {}
    Box() {}
};

bool cmp(const Box &a, const Box &b) {
    if (a.h != b.h)
        return a.h < b.h;
    else if (a.w != b.w)
        return a.w < b.w;
    else
        return a.d < b.d;
}

void outputBoxes(vector<int> &f, vector<int> &aboveIndices, int bestBottomIndex, vector<Box> &boxes) {
    int index = bestBottomIndex;
    while (true) {
        if (index == -1)
            break;
        cout << boxes[index].w << " " << boxes[index].h << " " << boxes[index].d << endl;
        index = aboveIndices[index];
    }
}

void output(vector<Box> &boxes) {
    for (int i = 0; i < boxes.size(); i++)
        cout << boxes[i].w << " " << boxes[i].h << " " << boxes[i].d << endl;
}

void findMaxHeight(int n, vector<Box> &boxes) {
    sort(boxes.begin(), boxes.end(), cmp);
    //output(boxes);
    int ans = 0;
    int bestBottomIndex = 0;
    vector<int> aboveIndices;
    vector<int> f;

    aboveIndices.assign(n, -1);
    f.assign(n, 0);
    f[0] = boxes[0].h;

    for (int i = 1; i < n; i++) {
        int max = 0;
        int bestAboveIndex = 0;
        for (int j = 0; j < i; j++)
            if (boxes[i].h > boxes[j].h && boxes[i].w > boxes[j].w && boxes[i].d > boxes[j].d && f[j] > max) {
                max = f[j];
                bestAboveIndex = j;
            }
        f[i] = max + boxes[i].h;
        //cout << f[i] << endl;
        aboveIndices[i] = bestAboveIndex;
        if (ans < f[i]) {
            ans = f[i];
            bestBottomIndex = i;
        }
    }
    cout << ans << endl;
    outputBoxes(f, aboveIndices, bestBottomIndex, boxes);

}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n;
    fin >> n;
    vector<Box> boxes;
    for (int i = 0; i < n; i++) {
        Box box;
        fin >> box.w >> box.h >> box.d;
        boxes.push_back(box);
    }
    findMaxHeight(n, boxes);
    return 0;
}
