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
    int goodNodes(TreeNode* root) {
        int count = 0;
        goodNodes(root, root->val, count);
        return count;
    }

private:
    void goodNodes(TreeNode *root, int maxValue, int &count) {
        if (root->val >= maxValue) {
            ++count;
            maxValue = root->val;
        }
        if(root->left) goodNodes(root->left, maxValue, count); 
        if(root->right) goodNodes(root->right, maxValue, count); 
    }
};

int main() {
    Solution s;
    TreeNode three = TreeNode(3), five = TreeNode(5);
    TreeNode zero = TreeNode(0), four = TreeNode(4, &three, &five), seven = TreeNode(7), nine = TreeNode(9);
    TreeNode two = TreeNode(2, &zero, &four), eight = TreeNode(8, &seven, &nine);
    TreeNode *root = new TreeNode(6, &two, &eight);
    auto count = s.goodNodes(root);
    cout<<"number of good nodes are: "<<count<<endl;
    return 0;
}