#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int count = 1, l=0;
      for (int r=1; r<nums.size(); ++r) {
        if (nums[r] > nums[l]) {
          ++count;
          nums[++l] = nums[r]; 
        }
      }
      cout << "nums: " << nums << endl;
      return count;
    }
};

int main() {
  vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
  int k = Solution().removeDuplicates(nums);
  cout << "k: " << k << endl;
  return 0;
}