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
    // iterative
    int kthSmallestIterative(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(node != nullptr) {
            st.push(node);
            node = node->left;
        }
        while(k!=0 && !st.empty()) {
            node = st.top();
            st.pop(); --k;
            if(k == 0) return node->val;
            node = node->right;
            while(node != nullptr) {
                st.push(node);
                node = node->left;
            }
        }
        return 0;
    }

    // recursive optimize
    int kthSmallest(TreeNode* root, int k) {
        int smallestValue = 0;
        _kthSmallest(root, k, smallestValue);
        return smallestValue;
    }

    int _kthSmallest(TreeNode* root, int &k, int &value) {
        if(root==nullptr || k<0) return 0;
        _kthSmallest(root->left,k, value);
        --k;
        if(k==0) value = root->val;
        _kthSmallest(root->right,k, value);
        return 0;
    }

};

int main() {
    Solution s;
    TreeNode zero(0), one(1), two(2),three(3), four(4), five(5), six(6), seven(7), eight(8), nine(9), ten(10);
    six.link(&two,&eight);
    two.link(&zero, &four); eight.link(&seven, &ten);
    four.link(&three, &five);
    cout<<s.kthSmallest(&six,5)<<endl;
    return 0;
}