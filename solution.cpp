#include<bits/stdc++.h>
#include "print.cpp"
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      if(intervals.size() == 0) return 0;
      auto comparator = [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
      };
      sort(intervals.begin(), intervals.end(), comparator);
      int end = intervals[0][1];
      int count = 1;

      for(int i=1; i<intervals.size(); i++) {
        if(intervals[i][0] >= end) {
          ++count;
          end = intervals[i][1];
        }
      }
      return intervals.size() - count;
    }
};

int main() {
  vector<vector<int>> intervals = {
    {1,3},
    {1,2},
    {2,3},
    {3,4}
  };
  Solution s;
  cout << s.eraseOverlapIntervals(intervals);
  return 0;
}