#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 1443. Minimum Time to Collect All Apples in a Tree
class Solution {
public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>> adj(n);
    for(auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }
    return dfs(0, -1, adj, hasApple);
  }

  int dfs(int root, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
    int time = 0;
    for(int nei : adj[root]) {
      if(nei == parent) continue;
      int seconds = dfs(nei, root, adj, hasApple);
      if(seconds != 0 || hasApple[nei]) time += 2 + seconds;
    }
    return time;
  }
};

int main() {
  int n = 7;
  vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
  vector<bool> hasApple = {false,false,true,false,true,true,false};
  cout << Solution().minTime(n, edges, hasApple) << endl;
  return 0;
}