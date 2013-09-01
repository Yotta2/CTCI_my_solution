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

#define EPSILON 0.000001

using namespace std;

struct Line {
    double k, a, b;
    bool vertical;
};

struct Point {
    double x, y;
};

Line buildLine(Point point1, Point point2) {
    Line res;
    if (fabs(point1.x - point2.x) < EPSILON) {
        res.vertical = true;
        res.a = point1.x;
        return res;
    }
    res.k = (point1.y - point2.y) / (point1.x - point2.x);
    res.b = point1.y - point1.x * res.k;
    res.vertical = false;
    return res;
}

bool pointOnLine(Point point, Line line) {
    if (line.vertical)
        return fabs(point.x - line.a) < EPSILON;
    return fabs(point.y - (point.x * line.k + line.b)) < EPSILON;
}

Line findBestLine(const vector<Point> &points) {
    Line ans;
    if (points.size() == 1) {
        ans.vertical = true;
        return ans;
    }
    int max = 0;
    for (int i = 0; i < points.size(); i++)
        for (int j = i + 1; j < points.size(); j++) {
            Line line = buildLine(points[i], points[j]);
            int count = 0;
            for (int k = 0; k < points.size(); k++)
                if (pointOnLine(points[k], line))
                    count++;
            if (count > max) {
                ans = line;
                max = count;
            }
        }
    return ans;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n;
    vector<Point> points;
    fin >> n;
    for (int i = 0; i < n; i++) {
        Point point;
        fin >> point.x >> point.y;
        points.push_back(point);
    }
    Line ans = findBestLine(points);
    if (ans.vertical) {
        cout << "The line is vertical" << endl;
        cout << "a = " << ans.a << endl;
    } else {
        cout << "k = " << ans.k << endl;
        cout << "b = " << ans.b << endl;
    }
    return 0;
}
