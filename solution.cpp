#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int parent[n];
        int rank[n];
        for(int node=0; node<n; node++) {
            parent[node] = n;
            rank[node] = 1;
        }

        int count = n;
        for(auto edge : edges) count -= unionNode(edge[0], edge[1], parent, rank);

        return count;
    }

private:
    int findRoot(int node, int parent[]) {
        while(node == parent[node]) node = parent[node] = parent[parent[node]];
        return node;
    }

    int unionNode(int node1, int node2, int parent[], int rank[]) {
        node1 = findRoot(node1, parent);
        node2 = findRoot(node2, parent);

        if(node1==node2) return 0;

        if(rank[node1] >= rank[node2]) {
            parent[node2] = node1;
            rank[node1] += rank[node2];
        } else {
            parent[node1] = node2;
            rank[node2] += rank[node1];
        }
        return 1;
    }
};


int main() {
    Solution s;
    vector<vector<int>> edges = {{0,1}, {1,2}, {3,4}};
    int count = s.countComponents(5,edges);
    cout<<'\n'<<count<<'\n';
    return 0;
}