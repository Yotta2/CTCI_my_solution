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

using namespace std;

void setBit(char screen[], int x, int y, int width) {
    int i = (y * width + x) / 8;
    int j = (y * width + x) % 8;
    screen[i] |= 1 << j;
}

void drawHorizontalLine(char screen[], int width, int x1, int x2, int y) {
    int i;
    for (i = y * width + x1; i < (y * width + x1 + 8) / 8 * 8 && i <= (y * width + x2); i++)
        setBit(screen, i, y, width);
    for (; i <= (y * width + x2) / 8 * 8; i += 8)
        screen[i] |= 0xFF;
    for (i = i - 8 + 1; i <= (y * width + x2); i++)
        setBit(screen, i, y, width);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    char screen[] = {0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 13, 23,22, 2 , 2};
    drawHorizontalLine(screen, 16, 3, 10, 3);
    return 0;
}
