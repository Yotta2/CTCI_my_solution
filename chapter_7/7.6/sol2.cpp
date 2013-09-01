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

#define EPS 1e-6

using namespace std;

struct Point {
    int x, y;
};

class Line {
public:
    double k, b;
    bool infiniteK;
    Line() {}
    Line(Point p1, Point p2) {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        if (fabs(dx) > EPS) {
            k = dy / dx;
            b = p1.y - k * p1.x;
            infiniteK = false;
        } else {
            infiniteK = true;
            b = p1.x;
        }
    }

};

class KeyHash
{
public:
    size_t operator () (const Line &line) const {
        return (hash<int>() ((int)line.k)) ^ (hash<int>() ((int)line.b));
    }
};

class KeyEqual {
public:
    bool isEqual(double a, double b) const {
        return fabs(a - b) < EPS;
    }

    bool operator () (const Line &line1, const Line &line2) const {
        return isEqual(line1.k, line2.k) && isEqual(line1.b, line2.b)
                && line1.infiniteK == line2.infiniteK;
    }
};

Line findBestLine(const vector<Point> &points) {
    Line ans;
    unordered_map<Line, int, KeyHash, KeyEqual> lineHm;
    int max = 0;

    for (int i = 0; i < points.size(); i++)
        for (int j = i + 1; j < points.size(); j++) {
            Line line(points[i], points[j]);
            if (lineHm.find(line) == lineHm.end())
                lineHm[line] = 1;
            else
                lineHm[line]++;
            if (max < lineHm[line]) {
                max = lineHm[line];
                ans = line;
            }
        }
    return ans;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n;
    fin >> n;
    vector<Point> points;
    for (int i = 0; i < n; i++) {
        Point point;
        fin >> point.x >> point.y;
        points.push_back(point);
    }
    Line ans = findBestLine(points);
    if (ans.infiniteK)
        fout << "k = infinite, a = " << ans.b << endl;
    else
        fout << "k = " << ans.k << " b = " << ans.b << endl;
    //cout << KeyHash() ans << endl;
    return 0;
}
