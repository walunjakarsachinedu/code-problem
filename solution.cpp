#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        if(n-1 != edges.size()) return false;
        int rank[n];
        int parent[n];
        for(int i=0;i<n;i++) { 
            parent[i] = i; 
            rank[i] = 1;
        }

        for(auto edge : edges) {
            if(!unionNode(edge[0], edge[1], parent, rank)) return false;
        }
        return true;
    }

private:
    int findRoot(int node, int parent[]) {
        while(node != parent[node]) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }
    // return boolean indicating success of union of node
    bool unionNode(int node1, int node2, int parent[], int rank[]) {
        node1 = findRoot(node1, parent);
        node2 = findRoot(node2, parent);
        if(node1 == node2) return false;
        if(rank[node1] >= rank[node2]) {
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
    vector<vector<int>> edges = {{0,1}, {1,2}, {3,4}, {2,3}};
    bool count = s.validTree(5,edges);
    cout<<count<<endl;
    return 0;
}