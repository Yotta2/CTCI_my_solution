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

int getLeftBoundary(int arr[], int n) {
    int index = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[i - 1])
            break;
        else
            index = i;
    return index;
}

int getRightBoundary(int arr[], int n) {
    int index = n - 1;
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > arr[i + 1])
            break;
        else
            index = i;
    return index;
}

int getMax(int arr[], int left, int right) {
    int max = 0;
    for (int i = left; i <= right; i++)
        if (max < arr[i])
            max = arr[i];
    return max;
}

int getMin(int arr[], int left, int right) {
    int min = INT_MAX;
    for (int i = left; i <= right; i++)
        if (min > arr[i])
            min = arr[i];
    return min;
}

void shrinkLeft(int arr[], int n, int middleMin, int &index1) {
    for (int i = index1; i >= 0; i--) {
        if (arr[i] <= middleMin)
            break;
        index1 = i;
    }
}

void shrinkRight(int arr[], int n, int middleMax, int &index2) {
    for (int i = index2; i < n; i++) {
        if (arr[i] >= middleMax)
            break;
        index2 = i;
    }
}
void findMiddlePartIndices(int arr[], int n, int &index1, int &index2) {
    index1 = getLeftBoundary(arr, n);
    index2 = getRightBoundary(arr, n);
    int leftMax = getMax(arr, 0, index2 - 1);
    int rightMin = getMin(arr, index1 + 1, n);
    shrinkLeft(arr, n, rightMin, index1);
    shrinkRight(arr, n, leftMax, index2);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int arr[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int n = 13;
    int index1, index2;
    findMiddlePartIndices(arr, n, index1, index2);
    cout << "m = " << index1 << endl;
    cout << "n = " << index2 << endl;
    return 0;
}
