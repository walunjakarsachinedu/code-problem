#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 167. Two Sum II - Input Array Is Sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      size_t N = numbers.size();
      int l=0, r=N-1;
      while(l<r) {
        int sum = numbers[l]+numbers[r];
        if(sum == target) return {l+1,r+1};
        else if(sum < target) ++l;
        else --r;
      }
      return {0,0};
    }
};

int main() {
  vector<int> numbers = {2,7,11,15};
  int target = 9;
  vector<int> indexes = Solution().twoSum(numbers, target);
  cout << "indexes: " << indexes << endl;
  return 0;
}