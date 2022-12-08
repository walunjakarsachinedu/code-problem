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

// 872. Leaf-Similar Trees
class Solution {
  vector<int> leafs;
  bool isSimilar = true;
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      vector<int> l1, l2;
      getLeafs(root1, l1);
      getLeafs(root2, l2);
      if(l1.size() != l2.size()) return false;
      for(int i=0; i<l1.size(); i++) {
        if(l1[i] != l2[i]) return false;
      }
      return true;
    }

    void getLeafs(TreeNode* root, vector<int>& l) {
      if(root==NULL) return;
      if(root->left==NULL && root->right==NULL) l.push_back(root->val);
      getLeafs(root->left, l);
      getLeafs(root->right, l);
    }
};

int main() {
  TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode* root1 = new TreeNode(1, new TreeNode(2), new TreeNode(2));
  bool isSimilar = Solution().leafSimilar(root, root1);
  cout << isSimilar << endl;
  return 0;
}