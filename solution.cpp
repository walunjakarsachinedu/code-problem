#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

class UnionFind;
class UnionFind {
  vector<int> graph;
  vector<int> rank;
public:
  UnionFind(int n) {
    rank = vector<int>(n, 0);
    graph = vector<int>(n);
    for(int i=0; i<n; i++) graph[i] = i;
  }

  int find(int node) {
    while(node != graph[node]) node = graph[node] = graph[graph[node]];
    return node;
  }

  void unions(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if(n1 == n2) return;
    if(rank[n1] >= rank[n2]) graph[n2] = n1, ++rank[n1];
    else graph[n1] = n2, ++rank[n2];
  }  
};

// 2421. Number of Good Paths
class Solution {
public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    vector<vector<int>> adj(vals.size());
    for(auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    map<int, vector<int>> valToIndex; // vals -> [node]
    for(int i=0; i<vals.size(); i++) valToIndex[vals[i]].push_back(i);

    UnionFind unionFind(vals.size());
    
    int result = 0;
    for(auto& [val, indexes] : valToIndex) {
      for(int node : indexes) for(int nei : adj[node]) if(vals[nei] <= vals[node]) unionFind.unions(nei, node);
      unordered_map<int, vector<int>> groups; // group -> [group node member]
      for(int node : indexes) groups[unionFind.find(node)].push_back(node);
      for(auto& [group, members] : groups) result += countGoodPaths(members.size());
    }
    return result;
  }

  int countGoodPaths(int count) {
    return count + count * (count - 1) / 2;
  }
};

int main() {
  vector<int> vals = {1,1,2,2,3}; 
  vector<vector<int>> edges = {{0,1},{1,2},{2,3},{2,4}};
  cout << Solution().numberOfGoodPaths(vals, edges) << endl;
  return 0;
}