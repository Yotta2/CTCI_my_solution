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

void dfs(TreeNode *root, int tmp, int sum, vector<vector<int> > &ans, vector<int> &path) {
    if (root == NULL)
        return;
    path.push_back(root->val);
    if (tmp + root->val == sum) {
        ans.push_back(path);
    }
    dfs(root->left, tmp + root->val, sum, ans, path);
    dfs(root->right, tmp + root->val, sum, ans, path);
    path.pop_back();
}

void preorderTraverse(TreeNode *root, int sum, vector<vector<int> > &ans) {
    if (root == NULL)
        return;
    vector<int> path;
    dfs(root, 0, sum, ans, path);
    preorderTraverse(root->left, sum, ans);
    preorderTraverse(root->right, sum, ans);
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > ans;

    preorderTraverse(root, sum, ans);
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
    vector<vector<int> > ans = pathSum(root, 3);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }



    return 0;
}
