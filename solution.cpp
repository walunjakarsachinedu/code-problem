#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;


// 144. Binary Tree Preorder Traversal
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
  vector<int> ans;
    preOrder(root, ans);
    return ans;
  }

  void preOrder(TreeNode* root, vector<int>& node) {
    if(root==NULL) return;
    node.push_back(root->val);
    preOrder(root->left, node);
    preOrder(root->right, node);
  }
};

int main() {
  TreeNode* root = new TreeNode(1, NULL, new TreeNode(2, new TreeNode(3), NULL));
  cout << Solution().preorderTraversal(root) << endl;
  return 0;
}