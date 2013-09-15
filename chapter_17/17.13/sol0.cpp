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

struct BiNode {
    BiNode *node1, *node2;
    int val;
    BiNode(int v, BiNode *n1 = NULL, BiNode *n2 = NULL) : val(v), node1(n1), node2(n2) {}
    BiNode() {}
};

void inorderTraverse(BiNode * &tail, BiNode *node) {
    if (node == NULL)
        return;
    inorderTraverse(tail, node->node1);
    tail->node2 = node;
    node->node1 = tail;
    tail = tail->node2;
    inorderTraverse(tail, node->node2);
}

//convert a BST to a linked list with a dummy node at last
BiNode * convertBSTtodoublyLinkedlist(BiNode *root) {
    BiNode *head = new BiNode(0);
    BiNode *tail = head;
    inorderTraverse(tail, root);
    return head;
}

void printLinkedlist(BiNode *head) {
    BiNode *curr = head->node2;
    if (head == NULL)
        return;
    while (curr != NULL) {
        cout << curr->val << endl;
        curr = curr->node2;
    }
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    BiNode *head = NULL;
    BiNode *root = new BiNode(3);
    root->node1 = new BiNode(2);
    root->node1->node1 = new BiNode(1);
    root->node1->node1->node1 = new BiNode(0);
    root->node2 = new BiNode(5);
    head = convertBSTtodoublyLinkedlist(root);
    printLinkedlist(head);
    return 0;
}
