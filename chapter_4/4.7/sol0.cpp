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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isAncestor(TreeNode *root, TreeNode *node) {
    if (root == NULL)
        return false;
    if (root->left == node || root->right == node)
        return true;
    else
        return isAncestor(root->left, node) || isAncestor(root->right, node);
}

void preorderTraverse(TreeNode *root, TreeNode *node1, TreeNode *node2, TreeNode* &ans) {
    if (root == NULL || node1 == NULL || node2 == NULL)
        return;
    if (isAncestor(root, node1) && isAncestor(root, node2)) {
        ans = root;
        preorderTraverse(root->left, node1, node2, ans);
        preorderTraverse(root->right, node1, node2, ans);
    }
}

TreeNode *firstCommonAncestor(TreeNode *root, TreeNode *node1, TreeNode *node2) {
    if (root == node1 || root == node2)
        return root;
    TreeNode *ans;
    preorderTraverse(root, node1, node2, ans);
    return ans;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    cout << firstCommonAncestor(root, root, root->right)->val << endl;

    return 0;
}
