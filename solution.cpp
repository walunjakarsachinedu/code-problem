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
    TreeNode* invertTreeIterative(TreeNode* root) {
        stack<TreeNode*> st;
        if(root) st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();

            st.pop();

            swapTreeNode(node->left, node->right);

            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        swapTreeNode(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    void swapTreeNode(TreeNode *&node1, TreeNode *&node2) {
        TreeNode* temp = node1;
        node1 = node2;
        node2 = temp;
    }
    
};


int main() {
    Solution s;
    TreeNode* root = new TreeNode(1,new TreeNode(20, new TreeNode(5), new TreeNode(6)), new TreeNode(10));
    s.invertTree(root)->print();
    return 0;
}