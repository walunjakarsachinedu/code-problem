#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    void link(TreeNode* left, TreeNode* right) {
        this->left = left;
        this->right = right;
    }
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
    //normal code
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() && inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int pos = find(inorder.begin(), inorder.end(), preorder[0])-inorder.begin();
        vector<int> leftTreePreorder(preorder.begin()+1,preorder.begin()+pos+1);
        vector<int> leftTreeInorder(inorder.begin(),inorder.begin()+pos);
        vector<int> rightTreePreorder(preorder.begin()+pos+1,preorder.end());
        vector<int> rightTreeInorder(inorder.begin()+pos+1,inorder.end());

        root->left = _buildTree(leftTreePreorder, leftTreeInorder);
        root->right = _buildTree(rightTreePreorder, rightTreeInorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return _buildTreeOptimize(preorder, inorder, rootIdx, 0,inorder.size()-1);
    }

    // space and time optimize code
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

int main() {
    Solution s;
    TreeNode zero(0), one(1), two(2),three(3), four(4), five(5), six(6), seven(7), eight(8), nine(9), ten(10);
    six.link(&two,&eight);
    two.link(&zero, &four); eight.link(&seven, &ten);
    four.link(&three, &five);
    int rootIdx = 0;
    vector<int> preorder = {1,2,3};
    vector<int> inorder = {2,1,3};
    s.buildTree(preorder, inorder)->print();
    return 0;
}