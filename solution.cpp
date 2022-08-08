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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        return (p && q) 
        && (p->val == q->val) 
        && isSameTree(p->left, q->left) 
        && isSameTree(p->right, q->right);
    }
};


int main() {
    Solution s;
    TreeNode* root1 = new TreeNode(1,new TreeNode(2), new TreeNode(1));
    TreeNode* root2 = new TreeNode(1,new TreeNode(1), new TreeNode(2));
    cout<<(s.isSameTree(root1,root2) ? "tree are equal" : "tree are unequal")<<endl;
    return 0;
}