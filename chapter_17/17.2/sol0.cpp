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

bool hasWinner(char board[3][4]) {
    //-
    if (board[0][0] != '.' && board[0][0] == board[0][1] && board[0][0] == board[0][2])
        return true;
    if (board[1][0] != '.' && board[1][0] == board[1][1] && board[1][0] == board[1][2])
        return true;
    if (board[2][0] != '.' && board[2][0] == board[2][1] && board[2][0] == board[2][2])
        return true;

    //|
    if (board[0][0] != '.' && board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return true;
    if (board[0][1] != '.' && board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return true;
    if (board[0][2] != '.' && board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return true;

    //'\'
    if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    //'/'
    if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    char board[3][4] = {"X..", {".X."}, {"..X"}};
    if (hasWinner(board))
        cout << "someone has won!" << endl;
    else
        cout << "no winner yet!" << endl;
    return 0;
}
