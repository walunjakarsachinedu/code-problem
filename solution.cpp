#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 1519. Number of Nodes in the Sub-Tree With the Same Label
class Solution {
public:
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    unordered_map<char, vector<int>> ch_node; // ch -> [node]
    vector<int> ans(n, 0);
    vector<vector<int>> adj(n);

    for(auto edge: edges) {
      adj[edge[0]].push_back(edge[1]); 
      adj[edge[1]].push_back(edge[0]); 
    }

    dfs(0, -1, adj, labels, ch_node, ans);
    return ans;
  }

  void dfs(int root, int parent, vector<vector<int>>& adj, string& labels,  
    unordered_map<char, vector<int>>& ch_node, vector<int>& ans) {

      ch_node[labels[root]].push_back(root);
      for(int node : ch_node[labels[root]]) ++ans[node];
      for(int node : adj[root]) if(node!=parent) 
        dfs(node, root, adj, labels, ch_node, ans);
      ch_node[labels[root]].pop_back();
  }
};

int main() {
  int n = 7;
  vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
  string labels = "abaedcd";
  cout << Solution().countSubTrees(n, edges, labels) << endl;
  return 0;
}