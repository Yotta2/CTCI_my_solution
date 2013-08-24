#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

template<typename T>
class setOfStacks {
public:
    setOfStacks() : capacity(3) {}

    void push(T val) {
        if (empty()) {
            stack<T> s;
            s.push(val);
            stacks.push_back(s);
        } else {
            stack<T> lastStack = stacks[stacks.size() - 1];
            if (lastStack.size() == capacity) {
                stack<T> s;
                s.push(val);
                stacks.push_back(s);
            } else {
                stacks.pop_back();
                lastStack.push(val);
                stacks.push_back(lastStack);
            }
        }
    }

    void pop() {
        if (empty())
            throw "pop error: empty stack";
        int len = stacks.size();
        stack<T> lastStack = stacks[len - 1];
        //stacks.erase(stacks.begin() + len - 1);
        stacks.pop_back();
        lastStack.pop();
        if (!lastStack.empty())
            stacks.push_back(lastStack);
    }

    void popAt(int index) {
        if (index >= stacks.size())
            throw "popAt error: stack at index does not exist!";
        stacks[index].pop();
        if (stacks[index].empty())
            stacks.erase(stacks.begin() + index);
    }

    T top() {
        if (empty())
            throw "pop error: empty stack";
        stack<T> lastStack = stacks[stacks.size() - 1];
        return lastStack.top();
    }

    bool empty() {
        return stacks.size() == 0;
    }
private:
    const int capacity;
    vector<stack<T> > stacks;   // can use list(linked list) to improve time complexity
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    setOfStacks<int> s;
    for (int i = 0; i < 5; i++)
        s.push(i);
    /*for (int i = 0; i < 5; i++) {
        cout << s.top() << endl;
        s.pop();
    }*/
    cout << s.top() << endl;
    s.popAt(2);
    cout << s.top() << endl;
    s.popAt(0);
    cout << s.top() << endl;
    s.popAt(0);
    cout << s.top() << endl;
    s.popAt(0);
    cout << s.top() << endl;
    s.popAt(0);
    return 0;
}
