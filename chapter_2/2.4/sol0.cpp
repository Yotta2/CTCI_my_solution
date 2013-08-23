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

void mergeList(node *head, node *lessHead, node *target, node *greaterHead) {
    node *curr = head;
    node *prev;
    head->next = lessHead;
    prev = head;
    curr = head->next;
    while (curr != NULL) {
        curr = curr->next;
        prev = prev->next;
    }
    prev->next = target;
    target->next = greaterHead;
}

void partition(node *head, char x) {
    node *lessHead = NULL;
    node *greaterHead = NULL;
    node *curr = head->next;
    node *target = NULL;

    while (curr != NULL) {
        node *tmp = curr->next;
        if (curr->val < x) {
            curr->next = lessHead;
            lessHead = curr;
        } else {
            if (curr->val == x && target == NULL) {
                target = curr;
                target->next = NULL;
            } else {
                curr->next = greaterHead;
                greaterHead = curr;
            }

        }
        curr = tmp;
    }
    head->next = NULL;
    mergeList(head, lessHead, target, greaterHead);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    //string str = "FBF";
    string str = "FFFFELLOW ME, DUMMY";
    //string str = "F";
    node *head = buildLinkedList(str);
    char x = 'F';
    printLinkedList(head);
    partition(head, x);
    printLinkedList(head);
    return 0;
}
