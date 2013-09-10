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

struct Node {
    int val;
    Node *left, *right;
    Node(int _val, Node *l = NULL, Node *r = NULL) : val(_val), left(l), right(r) {}
    Node() {}
};

Node * recurCopy(Node * oldNode, map<Node *, Node *> &nodeMap) {
    if (oldNode == NULL)
        return NULL;
    Node *newNode;
    if (nodeMap.find(oldNode) != nodeMap.end()) {
        newNode = new Node(oldNode->val);
        newNode->left = recurCopy(oldNode->left, nodeMap);
        newNode->right = recurCopy(oldNode->right, nodeMap);
    } else {
        newNode = nodeMap[oldNode];
    }
    return newNode;
}

Node *getCopy(Node *oldNode) {
    map<Node *, Node *> nodeMap;
    return recurCopy(oldNode, nodeMap);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    Node *node = new Node(5);
    Node *newNode = getCopy(node);
    return 0;
}
