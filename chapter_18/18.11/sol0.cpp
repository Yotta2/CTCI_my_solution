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
#include <unordered_set>
#include <map>
#include <time.h>
#include <functional>
#include <queue>

#define EPS 1e-6
#define SIZE 4

using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point() {}
};

struct Square {
    Point upperLeftCorner;
    int sideLen;
    Square(Point ulc, int sl) : upperLeftCorner(ulc), sideLen(sl) {}
    Square() {}
};

bool hasBlackBorder(int matrix[SIZE][SIZE], Square &square) {
    Point upperLeftCorner = square.upperLeftCorner;
    int sideLen = square.sideLen;
    //upper border
    for (int j = upperLeftCorner.y; j < upperLeftCorner.y + sideLen; j++)
        if (matrix[upperLeftCorner.x][j] != 1)
            return false;
    //lower border
    for (int j = upperLeftCorner.y; j < upperLeftCorner.y + sideLen; j++)
        if (matrix[upperLeftCorner.x + sideLen - 1][j] != 1)
            return false;
    //left border
    for (int i = upperLeftCorner.x; i < upperLeftCorner.x + sideLen; i++)
        if (matrix[i][upperLeftCorner.y] != 1)
            return false;
    //right border
    for (int i = upperLeftCorner.x; i < upperLeftCorner.x + sideLen; i++)
        if (matrix[i][upperLeftCorner.y + sideLen - 1] != 1)
            return false;
    return true;
}

Square findMaxSubsquare(int matrix[SIZE][SIZE], Square &square) {
    if (hasBlackBorder(matrix, square))
        return square;
    Square maxSubsquare;
    if (square.sideLen <= 1) {
        maxSubsquare = square;
        maxSubsquare.sideLen = matrix[maxSubsquare.upperLeftCorner.x][maxSubsquare.upperLeftCorner.y];
        return maxSubsquare;
    }
    Square subsquare[5];
    int maxSubsquareSideLen = 0;

    for (int i = 0; i < 5; i++) {
        subsquare[i] = square;
        subsquare[i].sideLen--;
    }

    subsquare[2].upperLeftCorner.y++;
    subsquare[3].upperLeftCorner.x++;
    subsquare[3].upperLeftCorner.y++;
    subsquare[4].upperLeftCorner.x++;
    for (int i = 1; i < 5; i++) {
        Square tmpMaxSubsquare = findMaxSubsquare(matrix, subsquare[i]);
        if (tmpMaxSubsquare.sideLen > maxSubsquareSideLen) {
            maxSubsquare = tmpMaxSubsquare;
            maxSubsquareSideLen = maxSubsquare.sideLen;
        }
    }
    return maxSubsquare;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int matrix[SIZE][SIZE] = {{0, 0, 0, 0},   // 1 for black, 0 for white
                              {1, 1, 1, 0},
                              {1, 1, 1, 1},
                              {0, 0, 1, 1}};
    Point upperLeftCorner(0, 0);
    Square square(upperLeftCorner, 4);
    Square maxSubsquare = findMaxSubsquare(matrix, square);
    cout << "upper left corner: x = " << maxSubsquare.upperLeftCorner.x << endl;
    cout << "upper left corner: y = " << maxSubsquare.upperLeftCorner.y << endl;
    cout << "sideLen = " << maxSubsquare.sideLen << endl;
    return 0;
}
