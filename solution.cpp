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
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        bool isRootElement = root->left==nullptr && root->right==nullptr;
        if(isRootElement) return 1;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};


int main() {
    Solution s;
    TreeNode* root = new TreeNode(1,new TreeNode(20, new TreeNode(5), new TreeNode(6)), new TreeNode(10));
    cout<<s.maxDepth(root)<<endl;
    return 0;
}