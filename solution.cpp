#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 2256. Minimum Average Difference
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        size_t sum = 0;
        int N = nums.size();
        for(int num: nums) sum += num;

        int minIndex = 0;
        int minDiff = INT_MAX;
        size_t curSum = 0;
        for(int i=0; i<N; i++) {
          curSum += nums[i];
          int curAvg = curSum/(i+1);
          int nextAvg = (i==N-1) ? 0 : (sum - curSum) / (N-(i+1));
          int curDiff = abs(curAvg - nextAvg);

          if(curDiff < minDiff) {
            minDiff = curDiff;
            minIndex = i;
          }
        }
        return minIndex;
    }
};
// 2,5,3,9,5,3
// sum = 27

int main() {
  vector<int> nums = {2,5,3,9,5,3}; 
  int minDiff = Solution().minimumAverageDifference(nums);
  cout << minDiff << endl;
  return 0;
}