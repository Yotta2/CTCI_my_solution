#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>

using namespace std;

struct node {
    int val;
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
        node *newNode = new node(str[i] - '0');
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

void recCheck(node *head, node* &curr, bool &flag) {
    if (head == NULL)
        return;
    recCheck(head->next, curr, flag);
    if (head->val != curr->val)
        flag = false;
    curr = curr->next;
}

bool isPalindrome(node *head) {
    node *curr = head->next;
    bool flag = true;
    recCheck(head->next, curr, flag);
    return flag;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    string str = "010";
    node *head = buildLinkedList(str);
    //printLinkedList(head);
    if (isPalindrome(head) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
