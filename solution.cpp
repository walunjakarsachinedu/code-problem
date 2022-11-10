#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int cur_sum = nums[0];
        for(int i=1; i<nums.size(); i++) {
          cur_sum = max(cur_sum, 0);
          cur_sum += nums[i];
          result = max(result, cur_sum);
        }
        return result;
    }
};

int main() {
  Solution s;
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  s.maxSubArray(nums);
  return 0;
}