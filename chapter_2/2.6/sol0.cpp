#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>

using namespace std;

struct node {
    char val;
    struct node *next;
    node(int v) : val(v), next(NULL) {}
};

//build a singly linked list with a dummy node at the beginning
node * buildLinkedList(string &str) {
    node *head;
    node *tail;

    head = new node(0);
    head->next = NULL;
    tail = head;
    for (int i = 0; i < str.length(); i++) {
        node *newNode = new node(str[i]);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

void printLinkedList(node *head) {
    node *curr = head->next;
    while (true) {
        if (curr == NULL)
            break;
        cout << curr->val;
        curr = curr->next;
    }
    cout << endl;
}

node * getLoopStart(node *head) {
    set<node *> nodes;
    node *curr = head->next;

    while (true) {
        if (nodes.find(curr) != nodes.end())
            break;
        nodes.insert(curr);
        curr = curr->next;
    }
    return curr;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string str = "ABCDEC";
    node *head = buildLinkedList(str);
    node *middle = head->next;
    node *curr = head->next;
    while (true) {
        if (middle->val == 'C')
            break;
        middle = middle->next;
    }
    while (true) {
        if (curr->next == NULL)
            break;
        curr = curr->next;
    }
    curr->next = middle;
    node *loopStart = getLoopStart(head);
    cout << loopStart->val << endl;
    return 0;
}
