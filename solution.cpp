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
    bool isValidBST(TreeNode *root) {
        bool isTreeValid = true;
        return _isValidBST(root, LONG_MAX, LONG_MIN);
    }
private:
    bool _isValidBST(TreeNode *root, long int minRange, long int maxRange) {
        if (root == nullptr) return true;
        if (root->val <= minRange || root->val >= maxRange) return false;
        if (_isValidBST(root->left, minRange, root->val) 
        && _isValidBST(root->right, root->val, maxRange)) return true;
        return false;
    }
};

int main() {
    Solution s;
    TreeNode zero(0), one(1), two(2),three(3), four(4), five(5), six(6), seven(7), eight(8), nine(9);
    six.link(&two,&eight);
    two.link(&zero, &four); eight.link(&seven, &nine);
    four.link(&three, &five);
    if(s.isValidBST(&five)) cout<<"binary tree is valid"<<endl;
    else cout<<"binary tree is in-valid"<<endl;
    return 0;
}