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

TreeNode *createBST(vector<int> &num, int s, int e) {
    TreeNode *root;
    if (s > e)
        return NULL;
    else {
        int m = (s + e) / 2;
        root = new TreeNode(num[m]);
        root->left = createBST(num, s, m - 1);
        root->right = createBST(num, m + 1, e);
        return root;
    }
}

TreeNode *sortedArrayToBST(vector<int> &num) {
    return createBST(num, 0, num.size() - 1);
}

int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");


    return 0;
}
