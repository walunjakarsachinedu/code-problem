#include<bits/stdc++.h>
using namespace std;

enum order {
    preorder,inorder,postorder
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    TreeNode(vector<int> preorder, vector<int> inorder) {
        buildTree(preorder, inorder);
    }

    void print(order order=order::preorder) {
        switch(order) {
            case order::inorder:
                inOrderTraversal(this);
                break;
            case order::preorder:
                preOrderTraversal(this);
                break;
            case order::postorder:
                postOrderTraversal(this);
                break;
        }
        cout<<endl;
    }
    
    void buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        auto root = _buildTreeOptimize(preorder, inorder, rootIdx, 0,inorder.size()-1);
        this->val = root->val;
        this->left = root->left;
        this->right = root->right;
    }

private:  
    void preOrderTraversal(TreeNode* node) {
        if(node==nullptr) return;
        cout<<node->val<<" ";
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
    }
    void inOrderTraversal(TreeNode* node) {
        if(node==nullptr) return;
        inOrderTraversal(node->left);
        cout<<node->val<<" ";
        inOrderTraversal(node->right);
    }
    void postOrderTraversal(TreeNode* node) {
        if(node==nullptr) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout<<node->val<<" ";
    }

    TreeNode* _buildTreeOptimize(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int l, int r) {
        if(l > r) return nullptr;
        TreeNode* root = new TreeNode(preorder[rootIdx]);
        int pos = find(inorder.begin()+l, inorder.end(), preorder[rootIdx]) - inorder.begin();
        ++rootIdx;
        root->left = _buildTreeOptimize(preorder, inorder, rootIdx, l, pos-1);
        root->right = _buildTreeOptimize(preorder, inorder, rootIdx, pos+1, r);
        return root;
    }
};

class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        _maxPathSum(root);
        return res;
    }
    int _maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0; 

        auto rootVal = root->val;
        auto left = max(_maxPathSum(root->left),0);
        auto right = max(_maxPathSum(root->right),0);
        
        res = max(res, rootVal + left + right);
        return rootVal + max(left, right);
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode({6, 2, 0, 4, 3, 5, 8, 7, 9}, {0, 2, 3, 4, 5, 6, 7, 8, 9});
    TreeNode* n = new TreeNode({-3}, {-3});
    cout<<"max path sum : "<<s.maxPathSum(n)<<endl;
    return 0;
}