#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;


// 219. Contains Duplicate II
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      k = min(k, (int) nums.size() - 1);
      unordered_set<int> st;
      for(int i=0; i<=k;i++) {
        if(st.find(nums[i]) != st.end()) return true;
        st.insert(nums[i]);
      }
      for(int i=++k; i<nums.size(); i++) {
        st.erase(nums[i-k]);
        if(st.find(nums[i]) != st.end()) return true;
        st.insert(nums[i]);
      }
      return false;
    }
    // slightly optimized
    bool _containsNearbyDuplicate(vector<int>& nums, int k) {
      k = min(k, (int) nums.size() - 1);
      unordered_set<int> st;
      for(int i=0; i<nums.size(); ++i) {
        if(st.size() == k) st.erase(nums[i-k]);
        if(st.find(nums[i]) != st.end()) return true;
        st.insert(nums[i]);
      }
      return false;
    }
};


int main() {
  vector<int> nums = {1,2,3,1,2,3};
  int k = 2;
  bool containDublicate = Solution()._containsNearbyDuplicate(nums, k);

  if(containDublicate) cout << "contains dublicate" << endl;
  else cout << "not contains dublicate" << endl;

  return 0;
}