#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 100. Same Tree
class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if((p==NULL) != (q==NULL)) return false;
    if(p==NULL) return true;
    return (p->val == q->val) && 
      isSameTree(p->left, q->left) && 
      isSameTree(p->right, q->right);
  }
};

int main() {
  TreeNode* root = new TreeNode(1, NULL, new TreeNode(2, new TreeNode(3), NULL));
  cout << Solution().isSameTree(root, root) << endl;
  return 0;
}