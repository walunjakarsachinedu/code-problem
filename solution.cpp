#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
      int maxSum = INT_MIN, cmaxSum = 0;
      int minSum = INT_MIN, cminSum = 0;
      int total = 0;

      for(int r=0; r<nums.size(); r++) {
        cmaxSum = max(cmaxSum, 0);
        cmaxSum += nums[r];
        maxSum = max(maxSum, cmaxSum);

        cminSum = max(cminSum, 0);
        cminSum += -nums[r];
        minSum = max(minSum, cminSum);

        total += nums[r];
      }
      if (total == -minSum) return maxSum;
      return max(maxSum, total + minSum);
    }
};

int main() {
  vector<int> nums = {-2,-3,-2};
  int result = Solution().maxSubarraySumCircular(nums);
  cout << result << endl;
  return 0;
}