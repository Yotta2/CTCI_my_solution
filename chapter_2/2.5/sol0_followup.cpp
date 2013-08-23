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

int recAdd(node *ans, node *tmp) {
    if (ans->next == NULL) {
        ans->val += tmp->val;
        int carry = ans->val / 10;
        ans->val %= 10;
        return carry;
    }
    ans->val += recAdd(ans->next, tmp->next);
    ans->val += tmp->val;
    int carry = ans->val / 10;
    ans->val %= 10;
    return carry;
}

int getLen(node *head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

void padWithZero(node *head, int count) {
    for (int i = 0; i < count; i++) {
        node *newNode = new node(0);
        newNode->next = head->next;
        head->next = newNode;
    }
}

node * add(node *head1, node *head2) {
    node *ans = NULL;
    node *tmp = NULL;
    int ansLen = 0;
    int tmpLen = 0;
    copyList(ans, head1);
    copyList(tmp, head2);
    ansLen = getLen(ans);
    tmpLen = getLen(tmp);
    padWithZero(ans, max(ansLen, tmpLen) + 1 - ansLen);
    padWithZero(tmp, max(ansLen, tmpLen) + 1 - tmpLen);
    printLinkedList(ans);
    printLinkedList(tmp);
    recAdd(ans, tmp);
    if (ans->next->val == 0) {
        tmp = ans->next;
        ans->next = ans->next->next;
        delete tmp;
    }
    return ans;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");


    string str1 = "0";
    string str2 = "0";
    node *head1 = buildLinkedList(str1);
    node *head2 = buildLinkedList(str2);
    printLinkedList(add(head1, head2));
    return 0;
}
