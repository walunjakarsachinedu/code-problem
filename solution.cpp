#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 886. Possible Bipartition
class Solution {
    unordered_set<int> visited;
    unordered_map<int, int> visitedCount;
public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<int> adj[n+1];
    for(auto& edge : dislikes) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }
    for(int i=1; i<=n; i++) {
      if(!visited.count(i) && hasOddLengthCycle(adj, i, -1, 1)) return false;
    }
    return true;
  }
  bool hasOddLengthCycle(vector<int> adj[], int node, int parent, int count) {
    visited.insert(node);
    visitedCount[node] = count;
    for(int nei : adj[node]) {
      if(nei == parent) continue;
      if(visited.count(nei)) {
        int cycleLength = visitedCount[nei] - visitedCount[node] + 1;
        if(cycleLength % 2 != 0) return true;
      }
      else if(hasOddLengthCycle(adj, nei, node, count+1)) return true;
    }
    return false;
  }
};

int main() {
  int n = 10;
  vector<vector<int>> tokens = {{1,2},{3,4},{5,6},{6,7},{7,8},{8,9}};
  cout << Solution().possibleBipartition(n, tokens) << endl;
  return 0;
}