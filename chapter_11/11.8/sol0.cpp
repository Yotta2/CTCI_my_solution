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

struct Node {
    Node *left, *right;
    int leftSubtreeSize;
    int val;
    Node(int lTreeSize, int _val, Node *_left = NULL, Node *_right = NULL) :
        leftSubtreeSize(lTreeSize), val(_val), left(_left), right(_right) {}
};

using namespace std;

void track(int x, Node * &root) {
    if (root == NULL) {
        root = new Node(0, x);
    } else {
        Node *curr = root;
        while (true) {
            if (x <= curr->val) {
                curr->leftSubtreeSize++;
                if (curr->left == NULL) {
                    curr->left = new Node(0, x);
                    break;
                }
                curr = curr->left;
            } else {
                if (curr->right == NULL) {
                    curr->right = new Node(0, x);
                    break;
                }
                curr = curr->right;
            }
        }
    }
}

//return -1 if x is not in the tree
int getRankOfNumber(int x, Node *root) {
    int count = 0;
    Node *curr = root;
    while (true) {
        if (curr == NULL)
            return -1;
        if (curr->val == x) {
            count += curr->leftSubtreeSize + 1;
            break;
        }
        if (x < curr->val) {
            curr = curr->left;
        } else {
            count += curr->leftSubtreeSize + 1;
            curr = curr->right;
        }
    }
    return count - 1;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    int n;
    Node *root = NULL;
    fin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        track(x, root);
    }

    cout << getRankOfNumber(12, root) << endl;
    cout << getRankOfNumber(1, root) << endl;
    cout << getRankOfNumber(3, root) << endl;
    cout << getRankOfNumber(4, root) << endl;
    cout << getRankOfNumber(5, root) << endl;
    cout << getRankOfNumber(9, root) << endl;
    cout << getRankOfNumber(13, root) << endl;

    return 0;
}
