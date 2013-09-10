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

template<typename T>
class SmartPointer {
public:
    SmartPointer(T *ptr) {
        ref = ptr;
        refCountPtr = new int;
        *refCountPtr = 1;
    }

    SmartPointer(SmartPointer<T> &sptr) {
        ref = sptr.ref;
        refCountPtr = sptr.refCountPtr;
        (*refCountPtr)++;
    }

    ~SmartPointer() {
        remove();
    }

    SmartPointer & operator=(SmartPointer<T> &sptr) {
        if (*refCountPtr > 0)
            remove();
        ref = sptr.ref;
        refCountPtr = sptr.refCountPtr;
        (*refCountPtr)++;
        return *this;
    }

    //remove one reference to the object and delete the obj if the refCount is 0
    void remove() {
        (*refCountPtr)--;
        if (*refCountPtr == 0) {
            delete ref;
            delete refCountPtr;
            ref = NULL;
            refCountPtr = NULL;
        }
    }

    T *ref;
private:
    int *refCountPtr;
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int *p1 = new int;
    *p1 = 5;
    SmartPointer<int> sptr1(p1);
    SmartPointer<int> sptr2 = sptr1;
    cout << *(sptr2.ref) << endl;
    return 0;
}
