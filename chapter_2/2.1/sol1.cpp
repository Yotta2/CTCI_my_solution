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

void removeDuplicate(node *head) {
    set<char> vals;
    node *prev = head;
    node *curr = head->next;
    while (true) {
        if (curr == NULL)
            break;
        if (vals.find(curr->val) == vals.end()) {
            vals.insert(curr->val);
            prev = prev->next;
            curr = curr->next;
        } else {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
    }
}

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

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    //string str = "FOLLOW UPP";
    string str = "FELLOW ME, DUMMY";
    node *head = buildLinkedList(str);
    printLinkedList(head);
    removeDuplicate(head);
    printLinkedList(head);
    return 0;
}
