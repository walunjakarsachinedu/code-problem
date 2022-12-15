#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 1143. Longest Common Subsequence
class Solution {
public:
  int longestCommonSubsequence(string t1, string t2) {
    vector<vector<int>> cache(t1.size(), vector<int>(t2.size(), -1));
    return dp(t1, t2, 0, 0, cache);
  }

  int dp(string& t1, string& t2, int i1, int i2, vector<vector<int>>& cache) {
    if(i1 >= t1.size() || i2 >= t2.size()) return 0;
    if(cache[i1][i2] != -1) return cache[i1][i2];
    int length = 0;
    if(t1[i1] == t2[i2]) length = 1 + dp(t1, t2, i1+1, i2+1, cache);
    else length = max(dp(t1, t2, i1+1, i2, cache), dp(t1, t2, i1, i2+1, cache));
    cache[i1][i2] = length;
    return length;
  }
};

int main() {
  string text1 = "abcde";
  string text2 = "ace";
  cout << Solution().longestCommonSubsequence(text1, text2) << endl;
  return 0;
}