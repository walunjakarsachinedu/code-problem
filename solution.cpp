#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    void print() {
        postOrderTraversal(this);
        cout<<endl;
    }

private:  
    void postOrderTraversal(TreeNode* node) {
        cout<<node->val<<" ";
        if(node->left) postOrderTraversal(node->left);
        if(node->right) postOrderTraversal(node->right);
    }
};

class Solution {
    bool isTreeBalanced = true;
public:

    bool isBalanced(TreeNode* root) {
        depth(root);
        return isTreeBalanced;
    }

    int depth(TreeNode* root) {
        if(root==nullptr)return -1;
        int left = depth(root->left);
        int right = depth(root->right);
        isTreeBalanced &= abs(left-right) <= 1;
        return 1 + max(left, right);
    }
};


int main() {
    Solution s;
    TreeNode* root = new TreeNode(1,new TreeNode(20, new TreeNode(5), new TreeNode(6)), new TreeNode(10));
    cout<<(s.isBalanced(root) ? "tree is balanced" : "tree is unbalanced")<<endl;
    return 0;
}