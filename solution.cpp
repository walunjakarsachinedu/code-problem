#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 80. Remove Duplicates from Sorted Array II
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int l=0, count=1;
      bool isDublicate = false;
      for(int r=1; r<nums.size(); ++r) {
        if (!isDublicate && nums[r]==nums[l]) {
          isDublicate = true;
          nums[++l] = nums[r];
          ++count;
        }
        else if(nums[r] > nums[l]) {
          isDublicate = false;
          nums[++l] = nums[r];
          ++count;
        }
      }
      cout << "nums: " << nums << endl;
      return count;
    }
};

int main() {
  vector<int> nums = {1,1,1,2,2,3};
  int k = Solution().removeDuplicates(nums);
  cout << "k: " << k << endl;
  return 0;
}