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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        _serialize(root, res);
        return res;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> arr = split(data, ',');
        if(arr[0] == "n") return nullptr;
        int i=0;
        return _deserialize(arr, i);
    }

private:
    void _serialize(TreeNode* root, string& res) {
        if (root == nullptr) {
            res.append("n,");
        }
        else {
            res.append(to_string(root->val) + ",");
            _serialize(root->left, res);
            _serialize(root->right, res);
        }
    }

    TreeNode*  _deserialize(vector<string>& data, int& i) {
        TreeNode *root = new TreeNode(stoi(data[i]));
        ++i;
        if(data[i]!="n") root->left = _deserialize(data, i);
        ++i;
        if(data[i]!="n") root->right = _deserialize(data, i);
        return root;
    }

    vector<string> split(string text, char delim) {
        string line;
        vector<string> vec;
        stringstream ss(text);
        while (getline(ss, line, delim)) {
            vec.push_back(line);
        }
        return vec;
    };
};

int main() {
    Codec s;
    TreeNode* root = new TreeNode({6, 2, 0, 4, 3, 5, 8, 7, 9}, {0, 2, 3, 4, 5, 6, 7, 8, 9});
    return 0;
}