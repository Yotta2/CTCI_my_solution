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

void addNewNode(node *curr) {
    node *newNode = new node(0);
    curr->next = newNode;
}

void copyList(node* &dst, node* &src) {
    dst = new node(src->val);
    node *dstCurr = dst;
    node *srcCurr = src->next;

    while (srcCurr != NULL) {
        node *newNode = new node(srcCurr->val);
        dstCurr->next = newNode;
        srcCurr = srcCurr->next;
        dstCurr = dstCurr->next;
    }
}

node * add(node *head1, node *head2) {
    node *ans = NULL;
    node *curr1;
    node *curr2;
    copyList(ans, head1);
    printLinkedList(ans);
    printLinkedList(head2);
    curr1 = ans->next;
    curr2 = head2->next;
    while (curr2 != NULL) {
        curr1->val += curr2->val;
        if (curr1->val >= 10) {
            if (curr1->next == NULL)
                addNewNode(curr1);
            curr1->next->val += curr1->val / 10;
            curr1->val %= 10;
        }
        curr2 = curr2->next;
        if (curr2 == NULL)
            break;
        if (curr1->next == NULL)
            addNewNode(curr1);
        curr1 = curr1->next;
    }
    return ans;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");


    string str1 = "716";
    string str2 = "592";
    node *head1 = buildLinkedList(str1);
    node *head2 = buildLinkedList(str2);
    printLinkedList(add(head1, head2));
    return 0;
}
