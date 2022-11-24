#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 279. Perfect Squares
class Solution {
public:
  int numSquares(int n) {
    vector<int> cache(n+1, -1);
    return helper(n, cache);
  }
  int helper(int n, vector<int>& cache) {
    if(cache[n] != -1) return cache[n];
    if(n<=3) return n;
    int minPath = n-1;
    for(int i=1,j=1; j<=n; ++i, j=i*i) {
      minPath = min(minPath, helper(n-j, cache));
    }
    minPath += 1;
    cache[n] = minPath;
    return minPath;
  }
};

int main() {
  cout << Solution().numSquares(50) << endl;
}
