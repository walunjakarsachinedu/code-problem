#include<vector>
#include<iostream>
using namespace std;


// 213. House Robber II
class Solution {
public:
  int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    vector<int> cache(nums.size(), -1), cache1(nums.size(), -1);
    return max(dp(0, nums, cache, nums.size()-1), dp(1, nums, cache1, nums.size()));
  }

  int dp(int i, vector<int>& nums, vector<int>& cache, int size) {
    if(i >= size) return 0;
    if(cache[i] != -1) return cache[i];

    int include = dp(i+2, nums, cache, size) + nums[i];
    int skip = dp(i+1, nums, cache, size);
    return cache[i] = max(skip, include);
  }
};

int main() {
  vector<int> nums = {1,2,3};
  cout << Solution().rob(nums) << endl;
  return 0;
}