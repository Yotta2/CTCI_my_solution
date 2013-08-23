#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#define M 3
#define N 3

using namespace std;

void clear(int matrix[M][N]) {
    bool row[M];
    bool col[N];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (row[i] || col[j])
                matrix[i][j] = 0;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int matrix[M][N];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            fin >> matrix[i][j];
    clear(matrix);
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++)
            fout << matrix[i][j] << " ";
        fout << endl;
    }

    return 0;
}
