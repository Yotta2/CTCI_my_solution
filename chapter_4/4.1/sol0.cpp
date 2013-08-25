#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int treeHeight(TreeNode *root, bool &flag) {
    if (root == NULL)
        return 0;
    else {
        int leftHeight = treeHeight(root->left, flag);
        int rightHeight = treeHeight(root->right, flag);
        if (abs(leftHeight - rightHeight) > 1)
            flag = false;
        return max(leftHeight, rightHeight) + 1;
    }
}

bool isBalanced(TreeNode *root) {
    bool flag = true;
    treeHeight(root, flag);
    return flag;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    return 0;
}
