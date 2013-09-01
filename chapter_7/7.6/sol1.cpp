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
//#include <unordered_map>
#include <map>

#define EPSILON 0.000001

using namespace std;

class Line {
public:
    int kNum, kDen;
    int bNum, bDen;
    int count;
    Line(int kn, int kd, int bn, int bd, int c) :
        kNum(kn), kDen(kd), bNum(bn), bDen(bd), count(c) {}
    Line() {}
    bool operator < (const Line &rhs) const {
        if (kNum != rhs.kNum)
            return kNum < rhs.kNum;
        else if (kDen != rhs.kDen)
            return kDen < rhs.kDen;
        else if (bNum != rhs.bNum)
            return bNum < rhs.bNum;
        else if (bDen != rhs.bDen)
            return bDen < rhs.bDen;
        return false;
    }
};

struct Point {
    int x, y;
};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

Line buildLine(Point p1, Point p2) {
    int kNum, kDen;
    int bNum, bDen;

    kNum = p1.y - p2.y;
    kDen = p1.x - p2.x;
    int g = gcd(kNum, kDen);
    if (g != 0) {
        kNum /= g;
        kDen /= g;
    }

    bNum = p2.x * p1.y - p1.x * p2.y;
    bDen = p2.x - p1.x;
    g = gcd(bNum, bDen);
    if (g != 0) {
        bNum /= g;
        bDen /= g;
    }
    Line line(kNum, kDen, bNum, bDen, 0);
    return line;
}

Line findBestLine(const vector<Point> &points) {
    Line ans;
    map<Line, int> lineHm;
    int max = 0;

    for (int i = 0; i < points.size(); i++)
        for (int j = i + 1; j < points.size(); j++) {
            Line line = buildLine(points[i], points[j]);
            if (lineHm.find(line) == lineHm.end())
                lineHm[line] = 1;
            else
                lineHm[line]++;
            line.count = lineHm[line];
            if (max < lineHm[line]) {
                max = lineHm[line];
                ans = line;
            }
        }
    ans.count = (1 + sqrt(1 + 8 * ans.count)) / 2;
    return ans;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n;

    //fin >> n;
    while(true) {
        cin >> n;
        if (n == 0)
            break;
        vector<Point> points;
        for (int i = 0; i < n; i++) {
            Point point;
            //fin >> point.x >> point.y;
            cin >> point.x >> point.y;
            points.push_back(point);
        }
        Line ans = findBestLine(points);
        //fout << ans.count << endl;
        cout << ans.count << endl;
    }
    return 0;
}
