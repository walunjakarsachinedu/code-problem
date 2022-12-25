#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

/// ## algorithm
///
/// n: root of tree ;  i: ith child  
/// f(n): sumOfDistanceInTree ; nCount(i): number of nodes in substree i
///
/// f(n) = sum(f(stree(i)) + nCount(stree(i))) {repeat for all childrens} 
/// nCount(n-i) = nCount(stree(n)) - nCount(stree(i)) // no. of nodes execluding ith child
/// re-rooting(i) = f(n) + nCount(n-i) - nCount(i) // re-rooting to ith node
/// e.g.,   1
///       /   \
///      2     3
/// f(1) = 2
/// f(2) = 2 + 3 - 1 - 1 = 3
/// f(3) = 2 + 3 - 1 - 1 = 3
/// result = f(1) + f(2) + f(3) = 2 + 3 + 3 = 8


// 834. Sum of Distances in Tree
class Solution {
  vector<int> nodes_count;
  vector<bool> visited;
  vector<int> distance;
public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    nodes_count = vector<int>(n, -1);
    visited = vector<bool>(n,false);
    distance = vector<int>(n);
    unordered_map<int, vector<int>> adj;
    for(auto edge : edges) adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);

    int root_distance = dfs(adj, 0, 1).second;
    fill(visited.begin(), visited.end(), false);
    re_rooting(adj, 0, root_distance);
    return distance;
  }

  /// @returns {node_count, distance with all children's substree nodes}
  pair<int,int> dfs(unordered_map<int, vector<int>>& adj, int node, int count) {
    int sum = 0;
    visited[node] = true;
    for(int nei : adj[node]) {
      if(visited[nei]) continue;
      auto [node_count, distanceWithChildren] = dfs(adj, nei, 1);
      count += node_count;
      sum += distanceWithChildren + node_count;
    }
    nodes_count[node] = count;
    return {count, sum};
  }

  void re_rooting(unordered_map<int, vector<int>>& adj, int node, int root_distance) {
    visited[node] = true;

    distance[node] = root_distance;
    for(int nei : adj[node]) {
      if(visited[nei]) continue;
      int children_distance =  root_distance + (nodes_count[0] - nodes_count[nei]) - nodes_count[nei];
      re_rooting(adj, nei, children_distance);
    }
  }
};


int main() {
  int n = 6;
  vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
  vector<int> ans = Solution().sumOfDistancesInTree(6, edges);
  cout << "ans: " << ans << endl;
  return 0;
}