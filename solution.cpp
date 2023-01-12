#include<vector>
#include<iostream>
using namespace std;


// 198. House Robber
class Solution {
public:
  int rob(vector<int>& nums) {
    vector<int> cache(nums.size(), -1);
    return dp(0, nums, cache);
  }

  int dp(int i, vector<int>& nums, vector<int>& cache) {
    if(i >= nums.size()) return 0;
    if(cache[i] != -1) return cache[i];

    int include = dp(i+2, nums, cache) + nums[i];
    int skip = dp(i+1, nums, cache);
    return cache[i] = max(skip, include);
  }
};

int main() {
  vector<int> nums = {1,2,3,1};
  cout << Solution().rob(nums) << endl;
  return 0;
}