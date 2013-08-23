#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

struct node {
    char val;
    struct node *next;
};

void removeDuplicate(node *head) {
    node *curr1;
    node *curr2;
    node *prev;
    curr1 = head->next;
    while (true) {
        if (curr1 == NULL)
            break;
        curr2 = curr1->next;
        prev = curr1;
        while (true) {
            if (curr2 == NULL)
                break;
            if (curr1->val == curr2->val) {
                prev->next = curr2->next;
                delete curr2;
                curr2 = prev->next;
            } else {
                prev = prev->next;
                curr2 = curr2->next;
            }

        }
        curr1 = curr1->next;
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
