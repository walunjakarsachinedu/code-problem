#include<bits/stdc++.h>
using namespace std;

class Solution { // UnionFind Alogrithm Is Used
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int total_nodes = edges.size()+1;
        int rank[total_nodes]; // size of tree with node as root
        int parent[total_nodes];
        for(int node=0;node<total_nodes;node++) {
            rank[node] = 1;
            parent[node] = node;
        }
        
        for(auto edge : edges) {
            if(!unionNode(edge[0], edge[1], parent, rank)) return edge;
        }
        return {1,1}; // this statement will not be reach
    }

 private:   
    int findRoot(int node, int parent[]) {
        while(parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }
    
    bool unionNode(int node1, int node2, int parent[], int rank[]) {
        node1 = findRoot(node1, parent);
        node2 = findRoot(node2, parent);
        if(node1 == node2) return false;
        if(rank[node1] > rank[node2]) {
            parent[node2] = node1;
            rank[node1] += rank[node2];
        } else {
            parent[node1] = node2;
            rank[node2] += rank[node1];
        }
        return true;
    }
};


int main() {
    Solution s;
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<int> redundantEdge = s.findRedundantConnection(edges);
    cout<<redundantEdge[0]<<"-"<<redundantEdge[1]<<endl;
    return 0;
}