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

bool isSameTree(TreeNode *root1, TreeNode *root2) {
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL)
        return false;
    if (root1->val != root2->val)
        return false;
    else
        return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}

void postorderTraverse(TreeNode *root1, TreeNode *root2, bool &flag) {
    if (flag)
        return;
    postorderTraverse(root1->left, root2, flag);
    postorderTraverse(root1->right, root2, flag);
    if (isSameTree(root1, root2))
        flag = true;
}

bool isSubtree(TreeNode *root1, TreeNode *root2) {
    if (root2 == NULL)
        return true;
    bool flag = false;
    postorderTraverse(root1, root2, flag);
    return flag;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    //cout << firstCommonAncestor(root, root, root->right)->val << endl;

    return 0;
}
