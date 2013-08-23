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

void deleteMiddle(node *middle) {
    node *next = middle->next;
    middle->val = next->val;
    middle->next = next->next;
    delete next;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    //string str = "FBF";
    string str = "FELLOW ME, DUMMY";
    node *head = buildLinkedList(str);
    node *middle = head;
    for (int i = 0; i < str.length() / 2; i++)
        middle = middle->next;
    if (str.length() % 2 == 1)
        middle = middle->next;
    printLinkedList(head);
    deleteMiddle(middle);
    printLinkedList(head);
    return 0;
}
