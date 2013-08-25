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

void inorderTraverse(TreeNode *root, int depth, vector<list<TreeNode *> > &ans) {
    if (root == NULL)
        return;
    if (depth + 1 > ans.size()) {
        list<TreeNode *> l;
        ans.push_back(l);
    }
    inorderTraverse(root->left, depth + 1, ans);
    ans[depth].push_back(root);
    inorderTraverse(root->right, depth + 1, ans);
}

vector<list<TreeNode *> > levelOrder(TreeNode *root) {
    vector<list<TreeNode *> > ans;
    inorderTraverse(root, 0, ans);
    return ans;
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);
    vector<list<TreeNode *> > ans = levelOrder(root);
    /*for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }*/
    return 0;
}
