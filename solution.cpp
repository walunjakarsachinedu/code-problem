#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 2246. Longest Path With Different Adjacent Characters
class Solution {
public:
  int longestPath(vector<int>& parent, string s) {
    vector<vector<int>> adj(parent.size());
    for(int i=1; i<parent.size(); i++) adj[i].push_back(parent[i]), adj[parent[i]].push_back(i);    

    vector<int> maxPath(parent.size(),0);
    dfs(0, -1, adj, s, maxPath);
    return *max_element(maxPath.begin(), maxPath.end());
  }
  
  int dfs(int node, int parent, vector<vector<int>>& adj, string& s, vector<int>& maxpath) {
    int p1=0, p2=0;
    for(int nei: adj[node]) {
      if(nei == parent) continue;
      int tmp = dfs(nei, node, adj, s, maxpath) + 1;
      if(s[nei] == s[node]) continue;
      if(tmp > p1) p2 = p1, p1 = tmp;
      else if(tmp > p2) p2 = tmp;
    }
    maxpath[node] = p1 + p2 + 1; 
    return max(p1, p2);
  }
};

int main() {
  vector<int> parent = {-1,0,0,0};
  string s = "aabc";
  cout << Solution().longestPath(parent, s) << endl;
  return 0;
}