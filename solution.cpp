#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 1061. Lexicographically Smallest Equivalent String
class OptimizedSolution {
public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    vector<int> graph(26);
    for(int i=0; i<26; i++) graph[i] = i;

    for(int i=0; i<s1.size(); i++) unions(s1[i], s2[i], graph);
    
    string s;
    for(char ch : baseStr) s += find(ch, graph);
    return s;
  }

private:
  int find(char ch, vector<int>& graph) {
    ch = ch - 'a';
    while(ch != graph[ch]) ch = graph[ch] = graph[graph[ch]];
    return ch + 'a';
  }

  void unions(char ch1, char ch2, vector<int>& graph) {
    ch1 = find(ch1, graph) - 'a';
    ch2 = find(ch2, graph) - 'a';
    if(ch1 == ch2) return;
    if(ch1 <= ch2) graph[ch2] = ch1;
    else graph[ch1] = ch2;
  }
};


class Solution { // without using union-find algorithm
public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    unordered_map<char, set<char>> adj;
    for(int i=0; i<s1.size(); i++) adj[s1[i]].insert(s2[i]), adj[s2[i]].insert(s1[i]);

    vector<set<char>> eq_ch; // list of set of equivalent characters
    set<char> visited;
    for(auto ch : s1) {
      if(visited.count(ch)) continue;
      eq_ch.push_back(set<char>());
      set<char>& tmp = eq_ch.back();
      dfs(ch, adj, tmp);
      visited.insert(tmp.begin(), tmp.end());
    }

    unordered_map<char, char> mp;
    for(auto s : eq_ch) {
      char min_char = *s.begin();
      for(auto ch : s) mp[ch] = min_char;
    }

    string minStr;
    for(auto ch : baseStr) minStr += (mp.count(ch)) ? mp[ch] : ch;

    return minStr;
  }

  void dfs(char node, unordered_map<char, set<char>>& adj, set<char>& visited) {
    if(visited.count(node)) return;
    visited.insert(node);
    for(auto nei : adj[node]) dfs(nei, adj, visited);
  }
};

int main() {
  string s1 = "parker", s2 = "morris", baseStr = "parser";
  cout << OptimizedSolution().smallestEquivalentString(s1, s2, baseStr) << endl;
  return 0;
}