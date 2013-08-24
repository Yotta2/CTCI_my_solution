#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>

using namespace std;

template<typename T>
class stackWithMin {
public:
    stackWithMin() {}

    T push(T val) {
        rawStack.push(val);
        if (mins.empty())
            mins.push(val);
        else
            mins.push(std::min(mins.top(), val));
    }

    void pop() {
        rawStack.pop();
        mins.pop();
    }

    T min() {
        return mins.top();
    }

private:
    stack<T> rawStack;
    stack<T> mins;   // keep track of the minimum element from a certain node down to the bottom of the stack
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    stackWithMin<int> s;
    s.push(5);
    cout << s.min() << endl;
    s.push(6);
    cout << s.min() << endl;
    s.push(3);
    cout << s.min() << endl;
    s.push(7);
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    return 0;
}
