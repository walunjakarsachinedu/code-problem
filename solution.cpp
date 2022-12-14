#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 198. House Robber
class Solution {
  int N;
public:
  int rob(vector<int>& nums) {
    N = nums.size();
    vector<int> cache(N, -1);
    return dp(nums, 0, 0, cache);
  }

  int dp(vector<int>& nums, int i, int money, vector<int>& cache) {
    if(i >= N) return money;
    if(cache[i] != -1) return cache[i];
    int maxAmt = dp(nums, i+2, nums[i], cache);
    if(i+1 < N) maxAmt = max(maxAmt, dp(nums, i+3, nums[i+1], cache));
    cache[i] = maxAmt + money;
    return cache[i];
  }
};

int main() {
  vector<int> nums = {1,2,3,1};
  cout << Solution().rob(nums) << endl;
  return 0;
}