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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root) que.push(root);
        while(!que.empty()) {
            vector<int> level;
            int size = que.size();
            for(int i=0;i<size;i++) {
                TreeNode* node = que.front();
                level.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                que.pop();
            }
            res.push_back(level);
        }
        return res;
    }
};


int main() {
    Solution s;
    TreeNode three = TreeNode(3), five = TreeNode(5);
    TreeNode zero = TreeNode(0), four = TreeNode(4, &three, &five), seven = TreeNode(7), nine = TreeNode(9);
    TreeNode two = TreeNode(2, &zero, &four), eight = TreeNode(8, &seven, &nine);
    TreeNode *root = new TreeNode(6, &two, &eight);
    auto result = s.levelOrder(nullptr);
    for(auto level : result) {
        for(auto node : level) {
            cout<<node<<" ";
        }
        cout<<endl;
    }
    return 0;
}