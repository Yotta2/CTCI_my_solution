#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#define N 3
using namespace std;

void rotate(int matrix[N][N]) {
    for (int layer = 0; layer < N / 2; layer++) {
        for (int i = layer; i < N - layer - 1; i++) { // the last one should not be rotated
            int tmp = matrix[layer][i]; // save top
            matrix[layer][i] = matrix[N - i - 1][layer]; // left -> top
            matrix[N - i - 1][layer] = matrix[N - layer - 1][N - i - 1]; // bottom -> left
            matrix[N - layer - 1][N - i - 1] = matrix[i][N - layer - 1]; // right -> bottom
            matrix[i][N - layer - 1] = tmp; // top -> right
        }
    }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int matrix[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> matrix[i][j];
    rotate(matrix);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            fout << matrix[i][j] << " ";
        fout << endl;
    }

    return 0;
}
