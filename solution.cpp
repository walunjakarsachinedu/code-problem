#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 978. Longest Turbulent Subarray
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
      if(arr.size() == 1) return 1;
      int l=0;
      bool lt = arr[0] < arr[1];
      int maxLen = 0;
      for(int r=1; r<arr.size(); r++) {
        if(arr[r-1] == arr[r]) l = r; 
        else if((arr[r-1] < arr[r] == lt) || (arr[r-1] > arr[r] == !lt)) l = r-1;
        lt = arr[r-1] < arr[r];
        maxLen = max(maxLen, r-l+1);
      }
      return maxLen;
    }
};

int main() {
  vector<int> arr = {9,4,2,10,7,8,8,1,9};
  int size = Solution().maxTurbulenceSize(arr);
  cout << size << endl;
  return 0;
}