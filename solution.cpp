#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(): val(0), neighbors(vector<Node*>()) {}
    Node(int _val): val(_val), neighbors(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbors): val(_val), neighbors(_neighbors) {}
};

// algorithm : store all node in old graph in list & use that list to create cloned graph

class Solution {
public:
    Node* cloneGraph(Node* root) {
        if(root == nullptr) return nullptr;

        // bfs traversal of graph
        set<Node*> visited; 
        queue<Node*> que;
        que.push(root);
        while(!que.empty()) {
            Node* node = que.front(); que.pop();
            if(visited.find(node) != visited.end()) continue;
            visited.insert(node);
            for(auto i : node->neighbors) que.push(i);
        }

        map<int, Node*> newGraphNodes;
        for(auto oldNode : visited) newGraphNodes.insert({oldNode->val, new Node(oldNode->val)}); // copying values
        for(auto oldNode : visited) { // copying links
            Node* node = newGraphNodes[oldNode->val];
            for(auto neighbor: oldNode->neighbors) {
                node->neighbors.push_back(newGraphNodes[neighbor->val]); 
            }
        }
        return newGraphNodes[root->val];
    }
};

int main() {
    Solution s;
    return 0;
}
