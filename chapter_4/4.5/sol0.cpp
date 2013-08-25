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

void inorderTraverse(TreeNode *root, int &lastVisited, bool &flag) {
    if (flag == false || root == NULL)
        return;
    inorderTraverse(root->left, lastVisited, flag);
    if (root->val < lastVisited)
        flag = false;
    lastVisited = root->val;
    inorderTraverse(root->right, lastVisited, flag);
}

bool isValidBST(TreeNode *root) {
    int lastVisited = INT_MIN;
    bool flag = true;
    inorderTraverse(root, lastVisited, flag);
    return flag;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);
    return 0;
}
