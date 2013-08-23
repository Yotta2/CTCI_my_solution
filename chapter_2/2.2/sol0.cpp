#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>

using namespace std;

struct node {
    char val;
    struct node *next;
};

//build a singly linked list with a dummy node at the beginning
node * buildLinkedList(string &str) {
    node *head;
    node *tail;

    head = new node;
    head->next = NULL;
    tail = head;
    for (int i = 0; i < str.length(); i++) {
        node *newNode = new node;
        newNode->val = str[i];
        newNode->next = NULL;
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

node * findKthToLast(node *head, int k) {
    node *first;
    node *second;  // second is always kth nodes behind first;
    first = head->next;
    second = head->next;

    for (int i = 0; i < k; i++)
        if (first != NULL)
            first = first->next;
        else
            return NULL;

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    return second;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    //string str = "FOLLOW UPP";
    string str = "FELLOW ME, DUMMY";
    node *head = buildLinkedList(str);
    int k = 5;
    node *nodeTmp = findKthToLast(head, k);
    if (nodeTmp != NULL)
        cout << nodeTmp->val << endl;
    else
        cout << "Not exist!" << endl;
    return 0;
}
