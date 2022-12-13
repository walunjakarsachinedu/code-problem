#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 931. Minimum Falling Path Sum
class Solution {
  int R, C;
public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    R = matrix.size(), C = matrix[0].size();
    int minSum = INT_MAX;
    vector<vector<int>> cache(R, vector<int>(C, -1));
    for(int c=0; c<C; c++) {
      minSum = min(minSum, cost(matrix, 0, c, cache));
    }
    return minSum;
  }

  int cost(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& cache) {
    if(c<0 || c>=C) return INT_MAX;
    if(cache[r][c] != -1) return cache[r][c];
    if(r==R-1) return matrix[r][c];

    int minCost = cost(matrix, r+1, c, cache);
    minCost = min(cost(matrix, r+1, c-1, cache), minCost);
    minCost = min(cost(matrix, r+1, c+1, cache), minCost);
    cache[r][c] = matrix[r][c] + minCost;
    return cache[r][c];
  }

};

int main() {
  vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
  cout << Solution().minFallingPathSum(matrix) << endl;
  return 0;
}