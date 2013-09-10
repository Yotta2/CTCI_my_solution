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

void * align_malloc(int requiredBytes, int alignment) {
    int offset = alignment - 1 + sizeof(void *);
    void *p1;   //original block
    void **p2;   //aligned block
    if ((p1 = (void *)malloc(requiredBytes + offset)) == NULL)
        return NULL;
    p2 = (void **) (((int)p1 + offset) & ~(offset));
    p2[-1] = p1;
    return p2;
}

void aligned_free(void *p2) {
    void *p1 = ((void **)p2)[-1];
    free(p1);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    void *p = align_malloc(1000, 128);
    aligned_free(p);
    return 0;
}
