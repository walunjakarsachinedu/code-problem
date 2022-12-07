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

// 938. Range Sum of BST
class Solution {
  int sum = 0;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
      helper(root, low, high);
      return sum;
    }

    void helper(TreeNode* root, int low, int high) {
      if(root==NULL) return;
      if (root->val >= low && root->val <= high) {
        sum += root->val;
        helper(root->left, low, high);
        helper(root->right, low, high);
      }
      else if (root->val < low) helper(root->right, low, high);
      else if (root->val > high) helper(root->left, low, high);
    }
};

int main() {
  TreeNode* root = new TreeNode(3, new TreeNode(1, new TreeNode(0), new TreeNode(2)), new TreeNode(5, new TreeNode(4), new TreeNode(6)));
  int sum = Solution().rangeSumBST(root, 1, 4);
  cout << "sum: " << sum << endl;
  return 0;
}