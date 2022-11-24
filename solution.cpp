#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;


// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        float avg = 0;
        int l = 0;
        for(int r=0;r<arr.size();r++) {
          avg += (float) arr[r]/k;
          if(r-l+1 == k) {
            if(avg >=threshold) ++count;
            avg -= (float) arr[l]/k;
            ++l;
          }
        }
        return count;
    }
};


int main() {
  vector<int> arr = {2,2,2,2,5,5,5,8};
  int k = 3;
  int threshold = 4;

  int count = Solution().numOfSubarrays(arr, k, threshold);
  cout << count << endl;
  return 0;
}