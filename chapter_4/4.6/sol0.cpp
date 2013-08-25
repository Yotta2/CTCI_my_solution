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

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* leftMostNode(TreeNode* node) {
    if (node == NULL)
        return NULL;
    TreeNode *curr = node;

    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

TreeNode* nextNode(TreeNode* node) {
    if (node->parent == NULL || node->right != NULL)
        return leftMostNode(node->right);
    else {
        TreeNode *parent = node->parent;
        TreeNode *curr = node;
        while (parent != NULL) {
            if (parent->left == curr)
                break;
            parent = curr->parent;
        }
        return parent;
    }

}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    TreeNode *root = new TreeNode(3);
    root->parent = NULL;
    root->left = new TreeNode(2);
    root->left->parent = root;
    root->left->left = new TreeNode(1);
    root->left->left->parent = root->left;
    root->right = new TreeNode(4);
    root->right->parent = root;
    root->right->right = new TreeNode(5);
    root->right->right->parent = root->right;
    cout << nextNode(root->right)->val << endl;
    return 0;
}
