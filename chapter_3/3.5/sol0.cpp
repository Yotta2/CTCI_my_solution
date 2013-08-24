#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

template<typename T>
class MyQueue {
public:
    void enqueue(T val) {
        inStack.push(val);
    }

    T dequeue() {
        if (empty())
            throw "dequeu error: queue is empty";
        if (outStack.empty())
            move();
        T top = outStack.top();
        outStack.pop();
        return top;
    }

    void move() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

    bool empty() {
        return outStack.empty() && inStack.empty();
    }

    int size() {
        return outStack.size() + inStack.size();
    }

    T front() {
        if (empty())
            throw "front error: queue is empty";
        if (outStack.empty())
            move();
        T top = outStack.top();
        return top;
    }

private:
    stack<T> inStack;
    stack<T> outStack;
};

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    MyQueue<int> q;
    for (int i = 0; i < 10; i++)
        q.enqueue(i);
    cout << "size: " << q.size() << endl;
    cout << "front: " << q.front() << endl;
    for (int i = 0; i < 10; i++)
        cout << q.dequeue() << endl;
    return 0;
}
