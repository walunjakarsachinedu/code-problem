#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;


// 209. Minimum Size Subarray Sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int l=0;
      int minLen = INT_MAX;
      int curSum = 0;
      for(int r=0; r<nums.size(); r++) {
        curSum += nums[r];
        while(curSum >= target && l <= r) {
          minLen = min(minLen, r-l+1);
          curSum -= nums[l++];
        }
      }

      if(minLen == INT_MAX) return 0;
      return minLen;
    }
};



int main() {
  vector<int> nums = {1,4,4};
  int target = 4;
  int minlen = Solution().minSubArrayLen(2, nums);

  cout << minlen << endl;

  return 0;
}

